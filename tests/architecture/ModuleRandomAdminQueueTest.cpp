
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using uint32=std::uint32_t;
struct ObjectGuid{uint32 n;uint32 GetCounter()const{return n;}};
struct Player{uint32 guid;std::string name;bool random=true,controllable=true,teleport=false;std::uint64_t generation=1;ObjectGuid GetObjectGuid(){return {guid};}uint32 GetGUIDLow(){return guid;}char const*GetName(){return name.c_str();}bool IsBeingTeleported(){return teleport;}};
struct Accessor{std::map<uint32,Player*>live;Player*FindPlayer(ObjectGuid id){auto i=live.find(id.n);return i==live.end()?nullptr:i->second;}}sObjectAccessor;
struct Clock{static uint32 now;static uint32 getMSTime(){return now++;}static uint32 getMSTimeDiff(uint32 a,uint32 b){return b-a;}};uint32 Clock::now=0;using WorldTimer=Clock;
struct Config{bool enabled=true;uint32 randomBotUpdateInterval=1000,randomBotMaintenanceBatch=2,randomBotMaintenanceBudgetMs=100;}sPlayerbotAIConfig;
bool normalizePlayerName(std::string&name){return !name.empty();}
struct Log{template<class...Args>void outString(char const*,Args...){}}sLog;
struct Facade{bool resetAccepted=true;bool ResetPersistentValues(){return resetAccepted;}bool InitializeBot(Player*){++calls;return true;}int calls=0;bool Refresh(Player*){++calls;return true;}void UpdateGearSpells(Player*){++calls;}bool Revive(Player*){++calls;return true;}void ChangeStrategy(Player*){++calls;}}sRandomBotFacade;
namespace TortoiseBots{
enum class RandomBotAdminAction{Refresh,Upgrade,Revive,ChangeStrategy,Remove,Initialize,Teleport,Rpg,Grind};
enum class RandomBotDestination{Level,LocalGrind,Rpg};
struct BotManager{std::vector<RandomBotDestination> relocations;bool RelocateRandomBot(Player*,RandomBotDestination d){relocations.push_back(d);return true;}static BotManager&Instance(){static BotManager s;return s;}std::vector<Player*>GetAllBots(){std::vector<Player*>v;for(auto&kv:sObjectAccessor.live)v.push_back(kv.second);return v;}Player*FindBot(ObjectGuid g){return sObjectAccessor.FindPlayer(g);}bool IsRandomBot(ObjectGuid g){auto*p=sObjectAccessor.FindPlayer(g);return p&&p->random;}bool IsControllableBot(Player*p){return p->controllable;}void RemoveBot(ObjectGuid g,bool){auto*p=sObjectAccessor.FindPlayer(g);sObjectAccessor.live.erase(g.n);delete p;}};
struct RandomBotService{bool m_initialized=true,m_targetReady=true;uint32 m_serviceElapsedMs=0;struct AdminRequest{ObjectGuid guid;RandomBotAdminAction action;std::uint64_t generation;};std::deque<AdminRequest>m_adminRequests;std::set<std::pair<uint32,RandomBotAdminAction>>m_adminKeys;
 uint32 QueueAdminAction(RandomBotAdminAction,std::string);void RequestUpdate();bool ResetPersistentState();void ProcessAdminActions();};
#include "ModuleRandomAdminQueue.inc"
}
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){using namespace TortoiseBots;RandomBotService service;
 for(uint32 i=1;i<=6;++i)sObjectAccessor.live[i]=new Player{i,"Bot"+std::to_string(i)};
 sObjectAccessor.live[6]->random=false;
 Check(service.QueueAdminAction(RandomBotAdminAction::Refresh,"all")==5,"only random bots selected");
 Check(service.QueueAdminAction(RandomBotAdminAction::Refresh,"all")==0,"duplicate batch coalesced");
 sObjectAccessor.live[1]->controllable=false;sObjectAccessor.live[2]->teleport=true;
 service.ProcessAdminActions();Check(sRandomBotFacade.calls==0&&service.m_adminRequests.size()==3,"reclaim and teleport cancel, count budget bounds scan");
 service.ProcessAdminActions();Check(sRandomBotFacade.calls==2&&service.m_adminRequests.size()==1,"bounded execution makes progress");
 service.ProcessAdminActions();Check(sRandomBotFacade.calls==3&&service.m_adminKeys.empty(),"queue and duplicate index drained");
 service.QueueAdminAction(RandomBotAdminAction::Remove,"Bot3");service.ProcessAdminActions();Check(!sObjectAccessor.live.count(3),"native removal may destroy player safely");
 service.QueueAdminAction(RandomBotAdminAction::Refresh,"Bot4");++sObjectAccessor.live[4]->generation;
 service.ProcessAdminActions();Check(sRandomBotFacade.calls==3&&service.m_adminKeys.empty(),"queued work cannot reach a replacement login of the same GUID");
 service.QueueAdminAction(RandomBotAdminAction::Refresh,"Bot4");service.ProcessAdminActions();Check(sRandomBotFacade.calls==4,"a new explicit request reaches the new incarnation");
 service.RequestUpdate();Check(service.m_serviceElapsedMs==1000,"update preserves minimum cadence");
 service.QueueAdminAction(RandomBotAdminAction::Initialize,"Bot5");service.ProcessAdminActions();Check(sRandomBotFacade.calls==5,"init delegates to native facade");
 service.QueueAdminAction(RandomBotAdminAction::Refresh,"all");sRandomBotFacade.resetAccepted=false;
 Check(!service.ResetPersistentState()&&!service.m_adminRequests.empty()&&service.m_targetReady,"failed store reset leaves queue and target intact");
 sRandomBotFacade.resetAccepted=true;Check(service.ResetPersistentState()&&service.m_adminRequests.empty()&&service.m_adminKeys.empty()&&!service.m_targetReady,"accepted reset clears pending admin requests and requests reconciliation");
 for(auto action:{RandomBotAdminAction::Teleport,RandomBotAdminAction::Rpg,RandomBotAdminAction::Grind}){service.QueueAdminAction(action,"Bot5");service.ProcessAdminActions();}
 Check(BotManager::Instance().relocations==std::vector<RandomBotDestination>{RandomBotDestination::Level,RandomBotDestination::Rpg,RandomBotDestination::LocalGrind},"relocation commands preserve distinct destination policies");
 for(auto&kv:sObjectAccessor.live)delete kv.second;
 std::cout<<"Random-bot admin queue bounds, deduplication, reclaim and removal passed\n";
}
