#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using uint32=std::uint32_t;
struct Session {bool headless=true;bool IsHeadless(){return headless;}};
struct Player {Session session;bool world=true,map=true,teleport=false,hasSession=true;bool IsInWorld(){return world;}void*GetMap(){return map?this:nullptr;}bool IsBeingTeleported(){return teleport;}Session*GetSession(){return hasSession?&session:nullptr;}char const*GetName(){return "fixture";}};
struct ByteBufferException {};
namespace TortoiseBots {struct BotWorldActions {static inline thread_local bool map=false;struct MapScope{bool previous=map;MapScope(){map=true;}~MapScope(){map=previous;}};};struct BotManager{static BotManager&Instance(){static BotManager m;return m;}bool IsPacketBridgeTestEnabled(){return false;}};}
struct PlayerbotAI {Player*bot=nullptr;bool context=true,engine=true,logout=false,malformed=false,unexpected=false;unsigned calls=0,elapsed=0;bool minimal=false;Player*GetBot(){return bot;}void*GetAiObjectContext(){return context?this:nullptr;}void*GetCurrentEngine(){return engine?this:nullptr;}bool GetShouldLogOut(){return logout;}void UpdateAI(unsigned diff,bool small){if(!TortoiseBots::BotWorldActions::map)std::abort();++calls;elapsed=diff;minimal=small;if(malformed)throw ByteBufferException{};if(unexpected)throw std::runtime_error("injected");}};
struct Log{unsigned errors=0;template<class...T>void outString(char const*,T...){ }template<class...T>void outError(char const*,T...){++errors;}}sLog;
namespace TortoiseBots {
struct PlayerbotAIStorage{Player*player=nullptr;PlayerbotAI*ai=nullptr;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}PlayerbotAI*GetAI(Player*p){return p==player?ai:nullptr;}};
struct PlayerbotAIAdapter{static bool CanUpdatePlayer(Player*);static void UpdatePlayer(Player*,uint32_t,bool);};
struct BotPlayerAdapter{bool IsAIUpdateDue(Player*,uint32);void OnAIUpdate(Player*,uint32,bool);};
#include "ModuleNativeMapAdmission.inc"
#include "ModuleNativeMapHooks.inc"
}
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){using namespace TortoiseBots;Player p,other;PlayerbotAI ai;ai.bot=&p;auto&s=PlayerbotAIStorage::Instance();s.player=&p;s.ai=&ai;BotPlayerAdapter hooks;
 Check(hooks.IsAIUpdateDue(&p,300),"usable bot remains due for packet/movement upkeep");hooks.OnAIUpdate(&p,237,true);Check(ai.calls==1&&ai.elapsed==237&&ai.minimal&&!BotWorldActions::map,"native elapsed/minimal forwarded exactly once and map scope restored");
 auto rejected=[&]{unsigned before=ai.calls;Check(!hooks.IsAIUpdateDue(&p,300),"unusable bot cannot consume background AI work");hooks.OnAIUpdate(&p,300,false);Check(ai.calls==before,"foreground dispatch revalidates admission");};
 p.session.headless=false;rejected();p.session.headless=true;p.world=false;rejected();p.world=true;p.map=false;rejected();p.map=true;p.teleport=true;rejected();p.teleport=false;p.hasSession=false;rejected();p.hasSession=true;ai.context=false;rejected();ai.context=true;ai.engine=false;rejected();ai.engine=true;ai.logout=true;rejected();ai.logout=false;ai.bot=&other;rejected();ai.bot=&p;s.ai=nullptr;rejected();s.ai=&ai;
 Check(!hooks.IsAIUpdateDue(nullptr,1)&&!hooks.IsAIUpdateDue(&other,1),"null or replacement player cannot inherit AI");
 ai.malformed=true;hooks.OnAIUpdate(&p,15,false);Check(sLog.errors==1&&!BotWorldActions::map,"malformed packet contained and scope restored");ai.malformed=false;ai.unexpected=true;try{hooks.OnAIUpdate(&p,15,false);Check(false,"unexpected exception must remain visible");}catch(std::runtime_error const&){}Check(!BotWorldActions::map,"unexpected unwind restores domain");
 std::cout<<"Native map hook admission, elapsed forwarding, reclaim and unwind passed\n";
}
