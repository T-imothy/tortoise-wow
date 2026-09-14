#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <vector>
using uint32_t=std::uint32_t;
struct Session {bool IsHeadless(){return true;}};
struct Player {Session session;bool teleport=false,near=false,far=false;Session*GetSession(){return &session;}bool IsBeingTeleported(){return teleport;}bool IsBeingTeleportedNear(){return near;}bool IsBeingTeleportedFar(){return far;}};
struct Accessor {std::map<unsigned,Player*> players;Player*FindPlayerNotInWorld(unsigned id){auto i=players.find(id);return i==players.end()?nullptr:i->second;}}sObjectAccessor;
struct PlayerbotAI {bool logout=false;bool GetShouldLogOut(){return logout;}void SetShouldLogOut(bool value){logout=value;}unsigned acks=0;void HandleTeleportAck(){++acks;}};
struct Adapter {PlayerbotAI ai;bool usable=true;unsigned calls=0;std::function<void()> callback;bool IsInitialized(){return true;}bool IsUsable(){return usable;}PlayerbotAI*GetAI(){return &ai;}void Update(unsigned){++calls;if(callback)callback();}};
struct Log{template<class...T>void outString(char const*,T...){}}sLog;
namespace TortoiseBots {
struct NativeGuildTrades {static inline std::function<void()> callback;static void Update(){if(callback)callback();}};
struct BotWorldActions {static inline bool map=false;static bool IsMapExecution(){return map;}struct MapScope{bool previous=map;MapScope(){map=true;}~MapScope(){map=previous;}};static inline std::function<void()> callback;static BotWorldActions&Instance(){static BotWorldActions x;return x;}void Drain(){if(callback)callback();}};
enum class BotLifecycle{InWorld,Removing};
struct Record {unsigned characterGuid;BotLifecycle lifecycle=BotLifecycle::InWorld;};
struct BotEntry {Record record;std::unique_ptr<Adapter> aiAdapter;};
struct BotManager {
 struct PendingBotRemoval{unsigned characterGuid;bool save;};
 std::map<unsigned,BotEntry>m_bots;bool m_inBotUpdate=false;bool m_packetTestEnabled=false;std::vector<PendingBotRemoval>m_pendingBotRemovals;
 void UpdateBots(uint32_t);
 void DrainPendingBotRemovals(){if(m_inBotUpdate)return;std::vector<PendingBotRemoval> pending;pending.swap(m_pendingBotRemovals);for(auto const&r:pending)RemoveBot(r.characterGuid,r.save); }
 void RemoveBot(unsigned id,bool save){auto i=m_bots.find(id);if(i==m_bots.end())return;if(m_inBotUpdate){i->second.record.lifecycle=BotLifecycle::Removing;m_pendingBotRemovals.push_back({id,save});}else m_bots.erase(i);}
 void Add(unsigned id){m_bots.emplace(id,BotEntry{{id},std::make_unique<Adapter>()});}
};
#include "ModuleBotDispatch.inc"
}
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){using namespace TortoiseBots;BotManager manager;Player p;sObjectAccessor.players[1]=&p;
 manager.Add(1);manager.Add(2);
 manager.UpdateBots(1);Check(!manager.m_bots[1].aiAdapter->calls&&!manager.m_bots[2].aiAdapter->calls,"world maintenance cannot duplicate native map AI");
 manager.RemoveBot(1,true);manager.RemoveBot(2,true);
 manager.Add(1);auto*adapter=manager.m_bots[1].aiAdapter.get();p.teleport=true;
 manager.UpdateBots(1);Check(!adapter->calls&&!adapter->ai.acks,"pending far transfer pauses without premature ack");
 p.near=true;manager.UpdateBots(1);Check(adapter->ai.acks==1&&!adapter->calls,"near transfer acknowledged before AI usability");
 p.near=false;p.far=true;manager.UpdateBots(1);Check(adapter->ai.acks==2&&!adapter->calls,"far transfer acknowledged before AI usability");
 p.teleport=p.far=false;BotWorldActions::callback=[&]{manager.RemoveBot(1,true);throw std::runtime_error("injected");};
 try{manager.UpdateBots(1);Check(false,"injected exception must escape world continuation");}catch(std::runtime_error const&){}
 Check(!manager.m_inBotUpdate&&manager.m_bots.size()==1,"unwind restores guard without deleting active stack");
 BotWorldActions::callback={};manager.UpdateBots(1);Check(manager.m_bots.empty(),"next pass drains pending stop");
 manager.Add(1);BotWorldActions::callback=[&]{Check(manager.m_inBotUpdate,"world actions require the deferred-removal guard");manager.RemoveBot(1,true);Check(manager.m_bots.size()==1,"queued action removal must retain its AI stack");};
 manager.UpdateBots(1);Check(manager.m_bots.empty(),"world action removals drain after return");BotWorldActions::callback={};
 manager.Add(1);manager.m_bots[1].aiAdapter->ai.logout=true;bool updated=false;manager.m_bots[1].aiAdapter->callback=[&]{updated=true;};manager.UpdateBots(1);Check(manager.m_bots.empty()&&!updated,"logout intent is consumed before AI and teardown follows the guard");
 manager.Add(1);NativeGuildTrades::callback=[&]{Check(manager.m_inBotUpdate,"native trades must share the removal guard");manager.RemoveBot(1,true);Check(!manager.m_bots.empty(),"native trade hooks cannot destroy their active AI");};
 manager.UpdateBots(1);NativeGuildTrades::callback={};Check(manager.m_bots.empty(),"trade-requested removal drains after native update");
 std::cout<<"Native bot dispatch removal, teleport ack and unwind ownership passed\n";
}
