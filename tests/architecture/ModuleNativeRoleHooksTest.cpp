#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using uint8=std::uint8_t;using uint32=std::uint32_t;
enum BotRoles{NONE=0,TANK=1,HEAL=2,DPS=4};
struct Session {bool headless=true;bool IsHeadless(){return headless;}};
struct Player {uint32 guid=1;uint8 level=60,cls=1;BotRoles roles=DPS;bool reachable=true;int resets=0;Session session;Session*GetSession()const{return const_cast<Session*>(&session);}uint32 GetObjectGuid()const{return guid;}uint32 GetGUIDLow(){return guid;}uint8 GetLevel(){return level;}uint8 getClass(){return cls;}void ResetTalents(bool){++resets;}};
struct AI {uint8 forced=0;bool humanMaster=false;int resets=0;uint8 GetForcedRole(){return forced;}void SetForcedRole(uint8 r){forced=r;}bool HasActivePlayerMaster(){return humanMaster;}void ResetStrategies(){++resets;}};
std::map<Player*,AI>ais;
struct PlayerbotAIStorage {static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}AI*GetAI(Player*p){auto it=ais.find(p);return it==ais.end()?nullptr:&it->second;}};
struct BotManager {bool random=true;std::vector<Player*>followers;static BotManager&Instance(){static BotManager m;return m;}bool IsRandomBot(uint32){return random;}std::vector<Player*>GetBotsForMaster(uint32){return followers;}};
struct AiFactory {static BotRoles GetPlayerRoles(Player const*p){return p->roles;}};
bool reachable=true;int talentSelections=0;
namespace ai {struct ChangeTalentsAction{static std::vector<int>getPremadePaths(uint8,const char*,BotRoles){return reachable?std::vector<int>{1}:std::vector<int>{};}static void AutoSelectTalents(Player*p,std::ostringstream*,BotRoles role){++talentSelections;p->roles=role;}};}
struct Facade {int clears=0;void SetValue(uint32,const char*,uint32 value){if(value==0)++clears;}}sRandomBotFacade;
struct BotPlayerAdapter {bool IsManagedBot(Player*);uint8 GetBotRoles(Player*);bool IsAIControlled(Player const*);bool HasAIFollowers(Player const*);bool GetAllowedRoles(Player const*,uint8&);void SetForcedRole(Player*,uint8);bool IsMachineDriven(Player const*);};
#include "ModuleNativeRoleHooks.inc"
enum{CONFIG_BOOL_LFT_BOTFILL_ENABLE};
struct World {bool nativeFill=false;bool getConfig(int){return nativeFill;}}sWorld;
struct Config {bool enabled=true,randomBotLftEnabled=true;}sPlayerbotAIConfig;
struct LftBotFillService {bool CanFillQueue()const;};
#include "ModuleLftOwner.inc"
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){BotPlayerAdapter adapter;Player bot;uint8 roles=7;Check(!adapter.IsAIControlled(&bot),"headless alone is not module AI");ais[&bot]={};Check(adapter.IsAIControlled(&bot),"attached headless AI classified");Check(adapter.GetAllowedRoles(&bot,roles)&&roles==4,"native role query uses current spec");bot.session.headless=false;Check(!adapter.IsManagedBot(&bot)&&adapter.GetBotRoles(&bot)==0,"network rolecheck remains interactive");roles=7;Check(!adapter.IsAIControlled(&bot)&&!adapter.GetAllowedRoles(&bot,roles)&&roles==7,"network ownership wins without changing unanswered output");adapter.SetForcedRole(&bot,1);Check(ais[&bot].forced==0,"no network role mutation");bot.session.headless=true;
    BotManager::Instance().followers={&bot};Check(adapter.HasAIFollowers(&bot)&&!adapter.HasAIFollowers(nullptr),"master query uses registered followers");
    Check(adapter.IsManagedBot(&bot)&&adapter.GetBotRoles(&bot)==4,"native rolecheck answers current spec");adapter.SetForcedRole(&bot,2);Check(adapter.GetBotRoles(&bot)==2,"native rolecheck answers forced role");Check(bot.resets==1&&talentSelections==1&&bot.roles==HEAL&&sRandomBotFacade.clears==2,"reachable contradictory random spec replaced");adapter.SetForcedRole(&bot,2);Check(talentSelections==1,"same role does not repeat reset");adapter.SetForcedRole(&bot,0);Check(bot.resets==1,"clear role preserves chosen talents");
    reachable=false;adapter.SetForcedRole(&bot,1);Check(bot.resets==1,"unreachable role does not wipe talents");reachable=true;ais[&bot].humanMaster=true;adapter.SetForcedRole(&bot,4);Check(bot.resets==1,"human-controlled random bot keeps spec");ais[&bot].humanMaster=false;BotManager::Instance().random=false;adapter.SetForcedRole(&bot,1);Check(bot.resets==1,"owned bot keeps spec");BotManager::Instance().random=true;bot.level=9;adapter.SetForcedRole(&bot,4);Check(bot.resets==1,"low level does not respec");auto prior=ais[&bot].forced;adapter.SetForcedRole(&bot,3);Check(ais[&bot].forced==prior,"invalid composite role rejected");
    LftBotFillService service;Check(service.CanFillQueue(),"module owns configured fill by default");sWorld.nativeFill=true;Check(!service.CanFillQueue(),"explicit native filler has exclusive priority");sWorld.nativeFill=false;sPlayerbotAIConfig.randomBotLftEnabled=false;Check(!service.CanFillQueue(),"module disabled");sPlayerbotAIConfig.randomBotLftEnabled=true;sPlayerbotAIConfig.enabled=false;Check(!service.CanFillQueue(),"AI disabled");
    std::cout<<"Native AI identity, role policy and exclusive LFT ownership passed\n";
}
