#include <cstdlib>
#include <iostream>
struct Session {bool logout=false;bool isLogingOut(){return logout;}};
struct Player {bool random=true,world=true,alive=true,teleport=false,group=false,taxi=false,bg=false,queued=false,controlled=true;unsigned repops=0;Session session;bool IsInWorld(){return world;}bool IsAlive(){return alive;}bool IsBeingTeleported(){return teleport;}bool GetGroup(){return group;}bool IsTaxiFlying(){return taxi;}bool InBattleGround(){return bg;}bool InBattleGroundQueue(){return queued;}Session*GetSession(){return &session;}void RepopAtGraveyard(){++repops;}};
struct Context {unsigned cleanups=0;void ClearExpiredValues(){++cleanups;}};
struct PlayerbotAI {bool master=false,nearby=false;Context context;bool HasActivePlayerMaster(){return master;}bool HasPlayerNearby(){return nearby;}Context*GetAiObjectContext(){return &context;}};
struct PlayerbotAIStorage {PlayerbotAI*ai=nullptr;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}PlayerbotAI*GetAI(Player*){return ai;}};
namespace TortoiseBots {struct BotManager{static BotManager&Instance(){static BotManager s;return s;}bool IsControllableBot(Player*p){return p->controlled;}};struct BotWorldActions{static bool map;static bool IsMapExecution(){return map;}};bool BotWorldActions::map=false;}
struct RandomBotFacade {bool IsRandomBot(Player*p){return p->random;}bool ProcessBot(Player*);void Revive(Player*p){p->RepopAtGraveyard();}};
#include "ModuleNativeMaintenanceEligibility.inc"
void Check(bool ok,char const*msg){if(!ok){std::cerr<<msg<<'\n';std::exit(1);}}
int main(){Player bot;PlayerbotAI ai;RandomBotFacade facade;PlayerbotAIStorage::Instance().ai=&ai;
 Check(!facade.ProcessBot(nullptr),"null character excluded");
 bot.alive=false;for(int n=0;n<100;++n)Check(!facade.ProcessBot(&bot),"death recovery belongs to native AI");Check(!bot.repops&&!ai.context.cleanups,"repeated corpse/ghost maintenance does not teleport or clear recovery values");bot.alive=true;
 for(bool Player::*flag:{&Player::world,&Player::random,&Player::controlled}){bot.*flag=false;Check(!facade.ProcessBot(&bot),"native ownership required");bot.*flag=true;}
 for(bool Player::*flag:{&Player::teleport,&Player::group,&Player::taxi,&Player::bg,&Player::queued}){bot.*flag=true;Check(!facade.ProcessBot(&bot),"busy character excluded");bot.*flag=false;}
 bot.session.logout=true;Check(!facade.ProcessBot(&bot),"logout excluded");bot.session.logout=false;
 ai.master=true;Check(!facade.ProcessBot(&bot),"human master excluded");ai.master=false;ai.nearby=true;Check(!facade.ProcessBot(&bot),"human activity excluded");ai.nearby=false;
 TortoiseBots::BotWorldActions::map=true;Check(!facade.ProcessBot(&bot),"cache cleanup requires world owner");TortoiseBots::BotWorldActions::map=false;
 PlayerbotAIStorage::Instance().ai=nullptr;Check(!facade.ProcessBot(&bot),"missing AI excluded");PlayerbotAIStorage::Instance().ai=&ai;
 Check(facade.ProcessBot(&bot)&&ai.context.cleanups==1&&!bot.repops,"eligible quiet-world bot cleans expired values once");
 std::cout<<"Native death recovery and background maintenance eligibility passed\n";
}
