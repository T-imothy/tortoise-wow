#include <atomic>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
#include "BotRemovalQueue.h"
struct ObjectGuid{unsigned value=0;unsigned GetCounter()const{return value;}std::string GetString()const{return std::to_string(value);}};
struct WorldSession{bool network=true;bool HasNetworkTransport(){return network;}};
struct Player{WorldSession session;WorldSession*GetSession(){return &session;}};
struct Accessor{Player*player=nullptr;Player*FindPlayer(ObjectGuid){return player;}}sObjectAccessor;
struct Log{template<class...T>void outString(T...){}}sLog;
namespace TortoiseBots{
enum class BotLifecycle{InWorld,Removing};enum class BotActivity{Grinding};enum class HeadlessSessionState{NotFound,Active};
struct BotRecord{uint64_t generation;ObjectGuid characterGuid;BotLifecycle lifecycle=BotLifecycle::InWorld;};struct BotEntry{BotRecord record;};
struct BotWorldActions{static inline thread_local bool map=false;static bool IsMapExecution(){return map;}};
struct BotActivityLeaseManager{unsigned releases=0;static BotActivityLeaseManager&Instance(){static BotActivityLeaseManager x;return x;}void Release(unsigned,BotActivity){++releases;}};
struct BotSessionAdapter{static inline HeadlessSessionState state=HeadlessSessionState::NotFound;static inline std::vector<std::pair<unsigned,bool>>stops;static void StopHeadlessSession(ObjectGuid id,bool save){stops.emplace_back(id.value,save);}static HeadlessSessionState GetHeadlessSessionState(ObjectGuid){return state;}};
struct BotManager{bool m_inBotUpdate=false;BotRemovalQueue m_pendingBotRemovals;std::unordered_map<unsigned,BotEntry>m_bots;bool RemoveBot(ObjectGuid,bool);void DrainPendingBotRemovals();void Add(unsigned id,uint64_t generation){m_bots.insert_or_assign(id,BotEntry{{generation,{id}}});}};
#include "ModuleNativeRemoval.inc"
}
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){using namespace TortoiseBots;BotManager manager;auto&stops=BotSessionAdapter::stops;auto&leases=BotActivityLeaseManager::Instance();manager.Add(1,1);
 CHECK(!manager.RemoveBot({99},true));manager.m_inBotUpdate=true;CHECK(manager.RemoveBot({1},false));CHECK(manager.RemoveBot({1},true));CHECK(stops.empty()&&manager.m_bots.size()==1);manager.DrainPendingBotRemovals();CHECK(stops.empty());manager.m_inBotUpdate=false;manager.DrainPendingBotRemovals();CHECK(stops.size()==1&&stops.back().second&&manager.m_bots.empty());
 manager.Add(1,2);manager.m_inBotUpdate=true;CHECK(manager.RemoveBot({1},true));manager.m_inBotUpdate=false;manager.Add(1,3);manager.DrainPendingBotRemovals();CHECK(stops.size()==1&&manager.m_bots.at(1).record.generation==3);
 unsigned releaseBefore=leases.releases;std::atomic<unsigned>admitted=0;std::vector<std::thread>producers;
 for(unsigned n=0;n<8;++n)producers.emplace_back([&,n]{BotWorldActions::map=true;for(unsigned k=0;k<128;++k)if(manager.RemoveBot({1},n==7))++admitted;BotWorldActions::map=false;});for(auto&t:producers)t.join();CHECK(admitted==1024&&stops.size()==1&&leases.releases==releaseBefore&&manager.m_bots.at(1).record.lifecycle==BotLifecycle::InWorld);
 BotWorldActions::map=true;manager.DrainPendingBotRemovals();CHECK(stops.size()==1);BotWorldActions::map=false;manager.DrainPendingBotRemovals();CHECK(stops.size()==2&&stops.back().second&&manager.m_bots.empty());
 BotRemovalQueue queue;CHECK(!queue.Push(0,1,true)&&!queue.Push(1,0,true));CHECK(queue.Push(5,10,true));CHECK(queue.Push(5,11,false));CHECK(!queue.Push(5,10,true));auto latest=queue.Take();CHECK(latest.size()==1&&latest[0].generation==11&&!latest[0].save&&queue.Take().empty());
 manager.Add(8,4);BotSessionAdapter::state=HeadlessSessionState::Active;CHECK(manager.RemoveBot({8},false)&&manager.m_bots.at(8).record.lifecycle==BotLifecycle::Removing);BotSessionAdapter::state=HeadlessSessionState::NotFound;Player network;sObjectAccessor.player=&network;CHECK(manager.RemoveBot({8},true)&&manager.m_bots.empty());
 std::cout<<"Native removals defer map/AI teardown, preserve save intent, reject stale incarnations and retain native stop/reclaim behavior\n";
}
