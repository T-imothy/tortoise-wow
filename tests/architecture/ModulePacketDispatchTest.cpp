
#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <stack>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
using uint16 = std::uint16_t;
constexpr uint16 MSG_RAID_READY_CHECK = 3;
struct WorldPacket {
    uint16 opcode; int id; bool isEmpty = false;
    uint16 getOpcode() const { return opcode; }
    bool empty() const { return isEmpty; }
};
struct ExternalEventHelper {
    std::function<bool(WorldPacket const&)> callback;
    bool HandlePacket(std::map<uint16, std::string> const&, WorldPacket const& p) { return callback(p); }
};
#include "ModulePacketTypes.inc"
#include "ModulePacketMethods.inc"
void Check(bool ok, char const* reason) { if (!ok) { std::cerr << reason << '\n'; std::exit(1); } }
int main() {
    PacketHandlingHelper packets;
    packets.AddHandler(1, "normal"); packets.AddHandler(2, "retry", true);
    packets.AddHandler(MSG_RAID_READY_CHECK, "ready");
    std::vector<int> seen;
    ExternalEventHelper helper{[&](WorldPacket const& p) {
        seen.push_back(p.id);
        if (p.id == 10) packets.AddPacket({1, 11}); // Native reentrant send.
        if (p.id == 20) throw std::runtime_error("malformed packet");
        return p.opcode != 2;
    }};
    packets.AddPacket({1, 10}); packets.Handle(helper);
    Check(seen == std::vector<int>{10}, "reentrant packet waits for the next batch");
    packets.Handle(helper); Check(seen.back() == 11, "reentrant packet retained");
    packets.AddPacket({1, 19}); packets.AddPacket({1, 20});
    try { packets.Handle(helper); Check(false, "expected packet error"); } catch (std::runtime_error const&) {}
    packets.AddPacket({1, 21}); packets.Handle(helper);
    Check(seen[seen.size()-2] == 21 && seen.back() == 19, "error releases lock and retains untouched packets");
    packets.AddPacket({2, 30}); packets.Handle(helper); packets.Handle(helper);
    Check(seen[seen.size()-2] == 30 && seen.back() == 30, "retry policy retained");
    helper.callback = [&](WorldPacket const& p) { seen.push_back(p.id); return true; };
    packets.Handle(helper); auto before = seen.size();
    packets.AddPacket({1, 40, true}); packets.AddPacket({99, 41});
    packets.AddPacket({MSG_RAID_READY_CHECK, 42, true}); packets.Handle(helper);
    Check(seen.size() == before+1 && seen.back() == 42, "empty ready-check exception and opcode filter preserved");
    std::atomic<int> done{0};
    std::vector<std::thread> workers;
    before = seen.size();
    for (int i=0;i<4;++i) workers.emplace_back([&,i] {
        for (int j=0;j<1000;++j) packets.AddPacket({1, 100+i*1000+j});
        ++done;
    });
    while (done != 4) packets.Handle(helper);
    for (auto& worker : workers) worker.join();
    packets.Handle(helper);
    Check(seen.size() == before+4000, "concurrent producers lose no packets");
    std::map<int,int> counts;
    for (auto it=seen.begin()+before;it!=seen.end();++it) ++counts[*it];
    Check(counts.size()==4000, "no duplicate packet dispatch");
    std::cout << "Module packet reentrancy, errors, retries and concurrent producers passed\n";
}
