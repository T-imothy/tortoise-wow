#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using uint32=std::uint32_t;
#define CHECK(x) do {if(!(x)){std::cerr<<__LINE__<<": " #x<<'\n';std::exit(1);}}while(0)
uint32 clockNow=0,workCost=0;struct WorldTimer{static uint32 getMSTime(){return clockNow;}static uint32 getMSTimeDiff(uint32 a,uint32 b){return b-a;}};
uint32 urand(uint32 a,uint32){return a;}
struct Player {uint32 guid;uint32 GetGUIDLow(){return guid;}uint32 GetLevel(){return 60;}uint32 GetTotalPlayedTime(){return 999;}};
enum class BotLifecycle { InWorld, Removing };
struct BotRecord{bool enteredWorld=true;BotLifecycle lifecycle=BotLifecycle::InWorld;};
std::map<uint32,Player> players;std::map<uint32,BotRecord> records;
struct ObjectAccessor{Player* FindPlayer(uint32 id){auto i=players.find(id);return i==players.end()?nullptr:&i->second;}}sObjectAccessor;
struct BotManager{static BotManager& Instance(){static BotManager b;return b;}BotRecord* FindBot(uint32 id){auto i=records.find(id);return i==records.end()?nullptr:&i->second;}};
struct Config{uint32 randomBotMaintenanceBatch=128,randomBotMaintenanceBudgetMs=2;
    uint32 minRandomBotChangeStrategyTime=1,maxRandomBotChangeStrategyTime=1;
    uint32 minRandomBotRandomizeTime=1,maxRandomBotRandomizeTime=1;bool randomGearUpgradeEnabled=true;}sPlayerbotAIConfig;
namespace TortoiseBots{bool NeedsInitialGearSeeding(uint32,uint32){return false;}}
std::vector<uint32> visited,strategies;uint32 removeDuringRecovery=0;
struct Facade{void ProcessBot(Player*p){uint32 guid=p->guid;visited.push_back(guid);clockNow+=workCost;if(guid==removeDuringRecovery){players.erase(guid);records.erase(guid);}}
    void ChangeStrategy(Player*p){strategies.push_back(p->guid);}uint32 GetValue(uint32,const char*){return 1;}
    void UpdateGearSpells(Player*){}void SetValue(uint32,const char*,uint32){} }sRandomBotFacade;
class RandomBotService {public:struct Candidate{uint32 characterGuid;};std::vector<Candidate>m_candidates;
    std::vector<uint32>m_strategyAgeMs,m_randomizeAgeMs;size_t m_nextMaintenance=0;
    void UpdateMaintenance(uint32_t elapsed);
};
#include "ModulePopulationMaintenance.inc"
RandomBotService MakePool(uint32 count)
{
    players.clear();records.clear();visited.clear();strategies.clear();clockNow=0;workCost=0;removeDuringRecovery=0;
    RandomBotService s;for(uint32 i=1;i<=count;++i){players.emplace(i,Player{i});records.emplace(i,BotRecord{});s.m_candidates.push_back({i});}
    s.m_strategyAgeMs.resize(count);s.m_randomizeAgeMs.resize(count);return s;
}
int main()
{
    auto s=MakePool(6000);
    s.UpdateMaintenance(1000);CHECK(visited.size()==128&&strategies.size()==128);
    CHECK(s.m_strategyAgeMs[0]==0&&s.m_strategyAgeMs[5999]==1000);
    s.UpdateMaintenance(1000);CHECK(visited.size()==256&&visited[128]==129);
    CHECK(s.m_strategyAgeMs[5999]==2000);
    for(unsigned n=2;n<47;++n)s.UpdateMaintenance(1000);
    std::set<uint32> coverage(visited.begin(),visited.end());CHECK(coverage.size()==6000);
    s=MakePool(10);workCost=1;s.UpdateMaintenance(1000);
    CHECK(visited.size()==2&&s.m_nextMaintenance==2);
    s.UpdateMaintenance(1000);CHECK(visited.size()==4&&visited[2]==3);
    s=MakePool(10);workCost=100;s.UpdateMaintenance(1000);
    CHECK(visited.size()==1&&s.m_nextMaintenance==1); // One action cannot be preempted.
    s=MakePool(10);removeDuringRecovery=1;s.UpdateMaintenance(1000);
    CHECK(visited.size()==10&&strategies.size()==9);
    CHECK(std::find(strategies.begin(),strategies.end(),1)==strategies.end());
    s=MakePool(3);players.erase(2);records.erase(3);s.UpdateMaintenance(1000);
    CHECK((visited==std::vector<uint32>{1}));CHECK(s.m_strategyAgeMs[1]==0&&s.m_strategyAgeMs[2]==0);
    s=MakePool(3);records[2].lifecycle=BotLifecycle::Removing;s.UpdateMaintenance(1000);
    CHECK((visited==std::vector<uint32>{1,3}));CHECK(s.m_strategyAgeMs[1]==0);
    s=MakePool(0);s.UpdateMaintenance(1000);CHECK(visited.empty());
    s=MakePool(3);sPlayerbotAIConfig.randomBotMaintenanceBatch=1;
    for(unsigned i=0;i<6;++i)s.UpdateMaintenance(1000);
    CHECK((visited==std::vector<uint32>{1,2,3,1,2,3}));
    std::cout<<"Module 6000-bot maintenance bounds, fairness, elapsed timers and removal safety passed\n";
}
