#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
using uint32=std::uint32_t;using uint64=std::uint64_t;
enum {CONFIG_UINT32_MAX_PLAYER_LEVEL,CONFIG_UINT32_START_PLAYER_LEVEL};
struct Player;
struct Session {bool headless=true,network=false;Player*player=nullptr;bool IsHeadless(){return headless;}bool HasNetworkTransport(){return network;}Player*GetPlayer(){return player;}};
struct Player {bool random=true,world=true,teleport=false,group=false,combat=false,bg=false,queued=false,taxi=false;uint32 level=20;Session*session=nullptr;
 bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}Session*GetSession(){return session;}bool GetGroup(){return group;}bool IsInCombat(){return combat;}bool InBattleGround(){return bg;}bool InBattleGroundQueue(){return queued;}bool IsTaxiFlying(){return taxi;}uint32 GetLevel(){return level;}uint32 GetGUIDLow(){return 1;}};
struct AI {bool master=false,guild=false;uint32 resets=0;bool HasActivePlayerMaster(){return master;}bool IsInRealGuild(){return guild;}void Reset(bool){++resets;}};
struct PlayerbotAIStorage {static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}AI*ai=nullptr;AI*GetAI(Player*){return ai;}};
struct World {uint32 cap=60,start=1;std::map<uint32,Session*>sessions;uint32 getConfig(int k){return k==CONFIG_UINT32_MAX_PLAYER_LEVEL?cap:start;}auto const&GetAllSessions(){return sessions;}}sWorld;
struct Config {uint32 randomBotMinLevel=1,randomBotMaxLevel=60,syncLevelNoPlayer=10,syncLevelMaxAbove=5;float randomBotMaxLevelChance=0;bool syncLevelWithPlayers=false,disableRandomLevels=false;}sPlayerbotAIConfig;
uint32 lower=0,upper=0;uint32 urand(uint32 a,uint32 b){if(a!=0){lower=a;upper=b;}return a;}
struct PlayerbotFactory {inline static uint32 calls=0,requestedLevel=0;Player*bot;uint32 level;PlayerbotFactory(Player*p,uint32 l):bot(p),level(l){}void Randomize(bool incremental,bool sync){if(incremental||sync)std::abort();++calls;requestedLevel=level;bot->level=level;}};
namespace TortoiseBots {struct BotActivityLeaseManager {bool available=true;static BotActivityLeaseManager&Instance(){static BotActivityLeaseManager s;return s;}bool IsAvailableForBackground(uint32){return available;}};}
struct RandomBotFacade {uint32 storedLevel=0;bool pinned=false;bool IsPinnedBot(uint32){return pinned;}bool IsRandomBot(Player*p){return p->random;}void SetValue(Player*,char const*,uint32 n){storedLevel=n;}bool InitializeBot(Player*);};
#include "ModuleBotInitialization.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){Player bot;Session session;bot.session=&session;AI ai;PlayerbotAIStorage::Instance().ai=&ai;RandomBotFacade facade;
 Check(!facade.InitializeBot(nullptr),"missing player rejected");
 facade.pinned=true;Check(!facade.InitializeBot(&bot),"pinned fixture preserved");facade.pinned=false;
 TortoiseBots::BotActivityLeaseManager::Instance().available=false;Check(!facade.InitializeBot(&bot),"service lease preserved");TortoiseBots::BotActivityLeaseManager::Instance().available=true;
 for(bool Player::*flag:{&Player::group,&Player::combat,&Player::bg,&Player::queued,&Player::taxi,&Player::teleport}){bot.*flag=true;Check(!facade.InitializeBot(&bot),"busy bot preserved");bot.*flag=false;}
 bot.random=false;Check(!facade.InitializeBot(&bot),"owned bot preserved");bot.random=true;session.headless=false;Check(!facade.InitializeBot(&bot),"human transport preserved");session.headless=true;
 ai.master=true;Check(!facade.InitializeBot(&bot),"human master preserved");ai.master=false;ai.guild=true;Check(!facade.InitializeBot(&bot),"real guild preserved");ai.guild=false;
 sPlayerbotAIConfig.randomBotMinLevel=5;Check(facade.InitializeBot(&bot)&&lower==5&&upper==60&&bot.level==5&&facade.storedLevel==5&&ai.resets==1,"full native factory and state reset");
 sPlayerbotAIConfig.randomBotMaxLevelChance=1;Check(facade.InitializeBot(&bot)&&bot.level==60,"configured max-level weighting");
 sPlayerbotAIConfig.syncLevelWithPlayers=true;Player human;human.level=25;Session network;network.network=true;network.player=&human;sWorld.sessions[1]=&network;
 Check(facade.InitializeBot(&bot)&&bot.level==30,"live human level sync");network.network=false;Check(facade.InitializeBot(&bot)&&bot.level==15,"headless sessions excluded from level sync");
 sPlayerbotAIConfig.syncLevelMaxAbove=UINT32_MAX;Check(facade.InitializeBot(&bot)&&bot.level==60,"sync addition does not overflow");
 sPlayerbotAIConfig.disableRandomLevels=true;bot.level=17;Check(facade.InitializeBot(&bot)&&PlayerbotFactory::requestedLevel==17,"fixed level respects native factory policy");
 std::cout<<"Native random initialization eligibility, class factory, level bounds and synchronization passed\n";
}
