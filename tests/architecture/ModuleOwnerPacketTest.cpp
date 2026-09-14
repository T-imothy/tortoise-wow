#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>
using uint64=std::uint64_t;
enum { SMSG_SPELL_FAILURE=1, SMSG_SPELL_DELAYED, SMSG_MOVE_KNOCK_BACK, SMSG_EMOTE, SMSG_MESSAGECHAT, NORMAL };
struct WorldPacket { int opcode; int id; int getOpcode() const { return opcode; } };
struct ByteBufferException {};
struct Player {
    uint64 generation=7; bool inWorld=true, teleporting=false;
    std::thread::id owner=std::this_thread::get_id();
    uint64 GetMapWorkGeneration()const {
        if(std::this_thread::get_id()!=owner) throw std::runtime_error("foreign thread read Player generation");
        return generation;
    }
    bool IsInWorld()const{return inWorld;}
    bool IsBeingTeleported()const{return teleporting;}
    char const* GetName()const{return "test";}
};
struct Log { int errors=0; template<class... Args> void outError(char const*,Args...){++errors;} } sLog;
struct PacketHandlingHelper {std::vector<int> queued;void AddPacket(WorldPacket const&p){queued.push_back(p.id);}};
struct Event {};
class PlayerbotAI;
namespace TortoiseBots {
struct BotWorldActions {
    inline static bool map=false;
    bool accept=true;
    std::deque<std::function<void(PlayerbotAI&)>> pending;
    static bool IsMapExecution(){return map;}
    static BotWorldActions& Instance(){static BotWorldActions x;return x;}
    bool EnqueueContinuation(Player*,char const*,Event const&,std::function<void(PlayerbotAI&)> callback){if(!accept)return false;pending.push_back(std::move(callback));return true;}
    void Drain(PlayerbotAI& ai){bool before=map;map=false;auto batch=std::move(pending);pending.clear();for(auto& f:batch)f(ai);map=before;}
};
}
class PlayerbotAI {
public:
    Player* bot; PacketHandlingHelper botOutgoingPacketHandlers;
    std::function<void(WorldPacket const&)> callback;
    void HandleBotOutgoingPacket(WorldPacket const&);
    void ProcessPendingBotPackets(bool worldControlOnly = false);
    void ProcessBotOutgoingPacket(WorldPacket const&p){callback(p);}
    #include "ModuleOwnerPacketTypes.inc"
};
#include "ModuleOwnerPacketMethods.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){
    Player bot; PlayerbotAI ai; ai.bot=&bot;
    std::vector<int> seen;
    ai.callback=[&](WorldPacket const&p){
        Check(std::this_thread::get_id()==bot.owner,"gameplay runs only on owner");
        seen.push_back(p.id);
        if(p.id==10) ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,11});
        if(p.id==20) throw ByteBufferException{};
        if(p.id==30){ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,33});throw std::runtime_error("unexpected");}
    };
    ai.HandleBotOutgoingPacket({SMSG_SPELL_DELAYED,1});
    ai.HandleBotOutgoingPacket({SMSG_SPELL_FAILURE,2});
    ai.HandleBotOutgoingPacket({SMSG_MOVE_KNOCK_BACK,3});
    Check(seen.empty(),"producer does not execute gameplay");
    ai.ProcessPendingBotPackets(); Check(seen==std::vector<int>({1,2,3}),"spell and movement events preserve FIFO");
    ai.HandleBotOutgoingPacket({NORMAL,4});
    Check(ai.botOutgoingPacketHandlers.queued==std::vector<int>({4}),"ordinary packets keep native action queue");
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,10}); ai.ProcessPendingBotPackets();
    Check(seen.back()==10,"reentrant sends wait for next batch");
    ai.ProcessPendingBotPackets();Check(seen.back()==11,"reentrant send retained");
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,20}); ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,21});
    ai.ProcessPendingBotPackets();Check(seen.back()==21&&sLog.errors==1,"malformed event preserves later reactions");
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,30}); ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,31});
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,32});
    try{ai.ProcessPendingBotPackets();Check(false,"expected error");}catch(std::runtime_error const&){}
    ai.ProcessPendingBotPackets();
    Check(std::vector<int>(seen.end()-3,seen.end())==std::vector<int>({31,32,33}),"unwind preserves FIFO before reentrant arrivals");
    seen.clear();
    ai.HandleBotOutgoingPacket({SMSG_MOVE_KNOCK_BACK,40}); ai.HandleBotOutgoingPacket({SMSG_SPELL_FAILURE,41});
    ai.HandleBotOutgoingPacket({SMSG_SPELL_DELAYED,42}); ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,43});
    ++bot.generation; ai.HandleBotOutgoingPacket({SMSG_MOVE_KNOCK_BACK,44}); ai.ProcessPendingBotPackets();
    Check(seen==std::vector<int>({43,44}),"native generation discards stale map events but preserves chat and new-map events");
    seen.clear(); ai.HandleBotOutgoingPacket({SMSG_MOVE_KNOCK_BACK,45});bot.teleporting=true;ai.ProcessPendingBotPackets();
    Check(seen.empty(),"pending teleport rejects spatial notification");bot.teleporting=false;
    ai.HandleBotOutgoingPacket({SMSG_SPELL_FAILURE,46});bot.inWorld=false;ai.ProcessPendingBotPackets();
    Check(seen.empty(),"out-of-world spatial notification rejected");bot.inWorld=true;
    std::atomic<int> done{0}; std::vector<std::thread> producers;
    for(int i=0;i<4;++i)producers.emplace_back([&,i]{for(int j=0;j<1000;++j)ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,100+i*1000+j});++done;});
    while(done!=4)ai.ProcessPendingBotPackets();
    for(auto&t:producers)t.join();ai.ProcessPendingBotPackets();
    std::map<int,int> counts;for(int id:seen)++counts[id];
    Check(seen.size()==4000&&counts.size()==4000,"foreign-map producers lose no notifications and never inspect Player state");
    seen.clear();auto& world=TortoiseBots::BotWorldActions::Instance();
    TortoiseBots::BotWorldActions::map=true;
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,50});ai.HandleBotOutgoingPacket({SMSG_SPELL_FAILURE,51});ai.HandleBotOutgoingPacket({SMSG_EMOTE,52});
    ai.ProcessPendingBotPackets();Check(seen==std::vector<int>({51})&&world.pending.size()==1,"map owner handles spell events and defers social events");
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,53});ai.ProcessPendingBotPackets();Check(world.pending.size()==1,"one coalesced world drain per AI");
    ai.HandleBotOutgoingPacket({SMSG_MOVE_KNOCK_BACK,54});world.Drain(ai);
    Check(seen==std::vector<int>({51,50,52,53}),"world continuation drains social FIFO without consuming pending movement");
    ai.ProcessPendingBotPackets();Check(seen.back()==54,"movement remains for map owner");
    ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,55});ai.ProcessPendingBotPackets();world.pending.clear();
    ++bot.generation;world.accept=false;ai.ProcessPendingBotPackets();Check(world.pending.empty(),"rejected retry retains mailbox");
    world.accept=true;ai.ProcessPendingBotPackets();Check(world.pending.size()==1,"discard or rejection releases coalescing gate");world.Drain(ai);Check(seen.back()==55,"social data survives discarded transfer continuation");
    seen.clear();ai.HandleBotOutgoingPacket({SMSG_MESSAGECHAT,60});ai.HandleBotOutgoingPacket({SMSG_SPELL_FAILURE,30});ai.HandleBotOutgoingPacket({SMSG_EMOTE,61});
    try{ai.ProcessPendingBotPackets();Check(false,"expected map exception");}catch(std::runtime_error const&){}
    ai.ProcessPendingBotPackets();world.Drain(ai);
    Check(seen==std::vector<int>({30,60,61,33}),"mixed-domain unwind preserves social FIFO before reentrant sends");
    TortoiseBots::BotWorldActions::map=false;
    std::cout<<"Owner packet FIFO, reentrancy, exception, map generation and concurrent chat checks passed\n";
}
