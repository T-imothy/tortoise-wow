#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>
using uint32=std::uint32_t;
struct ObjectGuid {uint32 n=0;ObjectGuid(uint32 v=0):n(v){}uint32 GetCounter()const{return n;}bool IsEmpty()const{return n==0;}operator uint32()const{return n;}};
struct Config {uint32 minRandomBots=0,maxRandomBots=0,randomBotsMaxLoginsPerInterval=2,randomBotMaintenanceBatch=128,randomBotMaintenanceBudgetMs=2,randomBotLoginDbQueueLimit=256;bool randomBotAutoCreate=true;}sPlayerbotAIConfig;
uint32 rollCount=0;uint32 urand(uint32 low,uint32 high){++rollCount;if(low>high)std::abort();return low;}
struct Facade{uint32 target=0,writes=0;uint32 GetValue(uint32,const char*){return target;}void SetValue(uint32,const char*,uint32 v){target=v;++writes;}}sRandomBotFacade;
uint32 clockValue=0;struct WorldTimer {static uint32 getMSTime(){return clockValue;}static uint32 getMSTimeDiff(uint32 a,uint32 b){return b-a;}};
struct Session{bool network=false;bool HasNetworkTransport(){return network;}};
struct Map{bool dungeon=false;bool IsDungeon(){return dungeon;}};
struct Player{Session session;Map map;bool transfer=false,combat=false,group=false,bg=false,queue=false,transport=false,taxi=false;Session*GetSession(){return &session;}bool IsBeingTeleported(){return transfer;}bool IsInCombat(){return combat;}void*GetGroup(){return group?this:nullptr;}bool InBattleGround(){return bg;}bool InBattleGroundQueue(){return queue;}void*GetTransport(){return transport?this:nullptr;}bool IsTaxiFlying(){return taxi;}Map*GetMap(){return &map;}};
struct Lft{bool IsQueued(ObjectGuid g){return g==12;}bool IsInOffer(ObjectGuid g){return g==13;}}sLFTMgr;
std::map<uint32,Player>players;
struct Accessor{Player*FindPlayerNotInWorld(ObjectGuid g){auto i=players.find(g);return i==players.end()?nullptr:&i->second;}}sObjectAccessor;
struct Database {size_t async=0,results=0;size_t GetPendingAsyncOperationCount(){return async;}size_t GetPendingResultCount(){return results;}}CharacterDatabase,LoginDatabase;
enum class BotLifecycle {PendingAdd,InWorld,Removing};
struct Record{bool random=true;BotLifecycle lifecycle=BotLifecycle::InWorld;ObjectGuid masterGuid;};
std::map<uint32,Record>records;std::vector<uint32>removed;uint32 removalCost=0;
struct BotManager{static BotManager&Instance(){static BotManager m;return m;}static bool HasRandomAdmissionCapacity();Record*FindBot(ObjectGuid g){auto i=records.find(g);return i==records.end()?nullptr:&i->second;}bool RemoveBot(ObjectGuid g,bool){records[g].lifecycle=BotLifecycle::Removing;removed.push_back(g);clockValue+=removalCost;return true;}};
struct BotActivityLeaseManager {std::set<uint32>busy;static BotActivityLeaseManager&Instance(){static BotActivityLeaseManager l;return l;}bool IsAvailableForBackground(uint32 g){return !busy.count(g);}};
class RandomBotService {public:struct Candidate{ObjectGuid characterGuid;};std::vector<Candidate>m_candidates;uint32 m_targetCount=0,m_desiredTargetCount=0;bool m_targetReady=false;size_t m_nextRemoval=0;std::set<uint32>pinned;bool IsPinnedGuid(uint32 g){return pinned.count(g);}void RefreshPopulationTarget();uint32 DesiredTargetCount()const;void RemoveSurplusBots(uint32);};
#include "ModulePopulationReconcile.inc"
#include "ModuleAdmissionCapacity.inc"
void Check(bool v,char const*m){if(!v){std::cerr<<m<<'\n';std::exit(1);}}
int main(){RandomBotService s;sPlayerbotAIConfig.minRandomBots=6000;sPlayerbotAIConfig.maxRandomBots=6000;sRandomBotFacade.target=4000;s.RefreshPopulationTarget();Check(s.m_targetCount==6000&&sRandomBotFacade.target==6000,"raised fixed target reconciles persisted lower target");auto writes=sRandomBotFacade.writes;for(int i=0;i<100;++i)s.RefreshPopulationTarget();Check(sRandomBotFacade.writes==writes,"stable target not rewritten per cadence");
    sPlayerbotAIConfig.minRandomBots=100;sPlayerbotAIConfig.maxRandomBots=200;sRandomBotFacade.target=150;s.RefreshPopulationTarget();Check(s.m_targetCount==150,"valid persisted target retained");sPlayerbotAIConfig.randomBotAutoCreate=false;s.m_candidates.resize(10);s.RefreshPopulationTarget();Check(s.m_targetCount==10&&sRandomBotFacade.target==150,"pool cap never overwrites desired target");sPlayerbotAIConfig.randomBotAutoCreate=true;
    sPlayerbotAIConfig.minRandomBots=0;sPlayerbotAIConfig.maxRandomBots=0;s.RefreshPopulationTarget();Check(s.m_targetCount==0&&sRandomBotFacade.target==0,"zero target disables population");
    RandomBotService zero;sPlayerbotAIConfig.maxRandomBots=10;zero.RefreshPopulationTarget();uint32 rolls=rollCount;zero.RefreshPopulationTarget();Check(rollCount==rolls,"zero selection remains stable");
    sPlayerbotAIConfig.minRandomBots=std::numeric_limits<uint32>::max();sPlayerbotAIConfig.maxRandomBots=1;s.RefreshPopulationTarget();Check(s.m_targetCount==1,"reversed full-width range is safe");
    s.m_candidates.clear();for(uint32 i=1;i<=6000;++i){s.m_candidates.push_back({i});records[i]={};players[i]={};}s.m_targetCount=5985;s.pinned.insert(1);records[2].masterGuid=9;players[3].combat=true;players[4].map.dungeon=true;players[5].group=true;players[6].session.network=true;players[7].transfer=true;players[8].queue=true;players[9].taxi=true;BotActivityLeaseManager::Instance().busy.insert(10);records[11].random=false;
    while(removed.size()<15){size_t before=removed.size();s.RemoveSurplusBots(6000-uint32(before));Check(removed.size()-before<=2,"bounded logout batch");}Check(removed.size()==15,"converges exactly to target");for(uint32 n:removed)Check(n>13,"protected activity never removed");
    removed.clear();s.m_targetCount=0;s.m_nextRemoval=0;removalCost=3;s.RemoveSurplusBots(6000);Check(removed.size()==1,"time limit stops further removals");removalCost=0;
    s.m_nextRemoval=5999;records[6000].lifecycle=BotLifecycle::PendingAdd;removed.clear();s.RemoveSurplusBots(6000);Check(!removed.empty()&&removed[0]==6000,"surplus pending admission can be cancelled");
    Check(BotManager::HasRandomAdmissionCapacity(),"empty queues admit");CharacterDatabase.async=256;Check(!BotManager::HasRandomAdmissionCapacity(),"character SQL pressure");CharacterDatabase.async=0;CharacterDatabase.results=256;Check(!BotManager::HasRandomAdmissionCapacity(),"character callback pressure");CharacterDatabase.results=0;LoginDatabase.async=256;Check(!BotManager::HasRandomAdmissionCapacity(),"auth SQL pressure");LoginDatabase.async=0;LoginDatabase.results=256;Check(!BotManager::HasRandomAdmissionCapacity(),"auth callback pressure");sPlayerbotAIConfig.randomBotLoginDbQueueLimit=0;Check(BotManager::HasRandomAdmissionCapacity(),"explicit disabled pressure threshold");
    std::cout<<"Population target, bounded convergence, protected activity and database backpressure passed\n";
}
