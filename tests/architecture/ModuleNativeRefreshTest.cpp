
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
using uint32=uint32_t;using int32=int32_t;
enum{POWER_MANA,POWER_ENERGY};enum{CORPSE,DEAD};constexpr uint32 MAX_MONEY_AMOUNT=0x7ffffffe;
uint32 urand(uint32 a,uint32){return a;}
struct Player {
 bool random=true,controlled=true,teleport=false,alive=true,canResurrect=true,bg=false,pvp=false;
 unsigned health=10,bones=0,repairs=0,money=10,level=60,resources[2]={1,2},maxResources[2]={100,200};
 unsigned deathState=CORPSE;unsigned GetDeathState(){return deathState;}char const*GetName(){return "fixture";}
 std::vector<int> events;
 bool IsBeingTeleported(){return teleport;}bool IsAlive(){return alive;}bool InBattleGround(){return bg;}
 void ResurrectPlayer(float){events.push_back(1);if(canResurrect){alive=true;health=100;}}
 void SpawnCorpseBones(){++bones;events.push_back(2);}void DurabilityRepairAll(bool,float){++repairs;}
 void SetHealthPercent(unsigned v){health=v;}void SetPvP(bool v){pvp=v;}unsigned GetLevel(){return level;}
 uint32 GetMaxPower(unsigned power){return maxResources[power];}void SetPower(unsigned power,unsigned value){resources[power]=value;}
 uint32 GetMoney(){return money;}void SetMoney(uint32 v){money=v;}void ModifyMoney(int32);
};
struct PlayerScript{void OnMoneyChanged(Player*,int32&){};};constexpr int PLAYERHOOK_ON_MONEY_CHANGED=0;
template<class T>struct ScriptRegistry{template<class F>static void ForEachEnabledHook(int,F f){T script;f(&script);}};
#include "NativeRefreshMoney.inc"
struct PlayerbotAI{unsigned resets=0,strategies=0;void Reset(){++resets;}void ResetStrategies(){++strategies;}};
struct PlayerbotAIStorage{PlayerbotAI* value=nullptr;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}PlayerbotAI*GetAI(Player*){return value;}};
struct Log{template<class...Args>void outString(char const*,Args...){}}sLog;
namespace TortoiseBots{
enum class RandomBotDestination{LocalGrind,Level};
struct BotManager{bool relocationAccepted=true;std::vector<RandomBotDestination>relocations;bool RelocateRandomBot(Player*,RandomBotDestination destination){relocations.push_back(destination);return relocationAccepted;}static BotManager&Instance(){static BotManager m;return m;}bool IsControllableBot(Player*p){return p->controlled;}};
struct BotWorldActions{static inline bool map=false;static bool IsMapExecution(){return map;}};
}
struct{bool disableRandomLevels=false;}sPlayerbotAIConfig;
struct PlayerbotFactory{static inline unsigned calls=0;PlayerbotFactory(Player*,unsigned){}void Refresh(){++calls;}};
struct RandomBotFacade{bool IsRandomBot(Player*p){return p->random;}bool Refresh(Player*);bool Revive(Player*);unsigned clearedEvents=0;void SetValue(Player*,char const*,unsigned){++clearedEvents;}};
#include "ModuleNativeRefresh.inc"
#include "ModuleNativeAdminRevive.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player bot;PlayerbotAI ai;RandomBotFacade facade;PlayerbotAIStorage::Instance().value=&ai;
 CHECK(facade.Refresh(&bot));CHECK(bot.health==100&&bot.pvp&&bot.repairs==1&&bot.resources[0]==100&&bot.resources[1]==200&&bot.money==510);CHECK(ai.resets==1&&PlayerbotFactory::calls==1);
 bot.alive=false;CHECK(facade.Refresh(&bot));CHECK(bot.alive&&bot.bones==1&&ai.strategies==1&&bot.events==std::vector<int>({1,2}));
 bot.alive=false;bot.canResurrect=false;unsigned before=PlayerbotFactory::calls;CHECK(!facade.Refresh(&bot));CHECK(bot.bones==1&&ai.strategies==1&&PlayerbotFactory::calls==before);
 bot.alive=true;bot.canResurrect=true;bot.health=5;sPlayerbotAIConfig.disableRandomLevels=true;CHECK(facade.Refresh(&bot));CHECK(bot.health==5&&PlayerbotFactory::calls==before);
 bot.alive=false;CHECK(facade.Refresh(&bot));CHECK(bot.alive&&bot.bones==2&&PlayerbotFactory::calls==before);sPlayerbotAIConfig.disableRandomLevels=false;
 bot.bg=true;bot.health=5;CHECK(facade.Refresh(&bot));CHECK(bot.health==5&&PlayerbotFactory::calls==before);bot.bg=false;
 bot.money=MAX_MONEY_AMOUNT-1;CHECK(facade.Refresh(&bot));CHECK(bot.money==MAX_MONEY_AMOUNT);
 CHECK(!facade.Refresh(nullptr));bot.random=false;CHECK(!facade.Refresh(&bot));bot.random=true;
 bot.controlled=false;CHECK(!facade.Refresh(&bot));bot.controlled=true;bot.teleport=true;CHECK(!facade.Refresh(&bot));bot.teleport=false;
 TortoiseBots::BotWorldActions::map=true;CHECK(!facade.Refresh(&bot));TortoiseBots::BotWorldActions::map=false;PlayerbotAIStorage::Instance().value=nullptr;CHECK(!facade.Refresh(&bot));

 PlayerbotAIStorage::Instance().value=&ai;bot=Player{};auto& manager=TortoiseBots::BotManager::Instance();
 CHECK(!facade.Revive(nullptr)&&!facade.Revive(&bot));bot.alive=false;bot.bg=true;CHECK(!facade.Revive(&bot)&&!bot.bones);bot.bg=false;
 bot.canResurrect=false;CHECK(!facade.Revive(&bot)&&!bot.bones&&!facade.clearedEvents&&manager.relocations.empty());bot.canResurrect=true;
 CHECK(facade.Revive(&bot)&&bot.alive&&bot.bones==1&&facade.clearedEvents==2&&manager.relocations.back()==TortoiseBots::RandomBotDestination::LocalGrind);
 bot.alive=false;bot.deathState=DEAD;manager.relocationAccepted=false;CHECK(facade.Revive(&bot)&&bot.alive&&bot.bones==2&&facade.clearedEvents==4&&manager.relocations.back()==TortoiseBots::RandomBotDestination::Level);
 CHECK(!facade.Revive(&bot)&&facade.clearedEvents==4&&manager.relocations.size()==2);
 bot.alive=false;TortoiseBots::BotWorldActions::map=true;CHECK(!facade.Revive(&bot)&&!bot.alive&&facade.clearedEvents==4);TortoiseBots::BotWorldActions::map=false;
 std::cout<<"Native refresh restores recovery/resources, preserves host rejection/config/BG rules and caps money through native hooks\n";
}
