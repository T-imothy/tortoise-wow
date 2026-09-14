#include <cstdlib>
#include <iostream>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
using ObjectGuid=unsigned;
enum class BotState {BOT_STATE_NON_COMBAT};
constexpr int MOVEFLAG_WALK_MODE=1,UNIT_STAND_STATE_SIT=1,UNIT_STAND_STATE_STAND=0;
#define BOT_TEXT(x) x
void Check(bool ok,char const*msg){if(!ok){std::cerr<<msg<<'\n';std::exit(1);}}
struct PlayerbotAI;
struct Group;
struct Movement {bool walk=false;bool HasMovementFlag(int){return walk;}void AddMovementFlag(int){walk=true;}void RemoveMovementFlag(int){walk=false;}};
struct Player {ObjectGuid guid;Group*group=nullptr;bool inWorld=true,teleport=false,bg=false,real=false,moving=false;int map=1,stand=0;unsigned stops=0,emotes=0;Movement m_movementInfo;
 Group*GetGroup(){return group;}bool IsInWorld(){return inWorld;}bool IsBeingTeleported(){return teleport;}bool InBattleGround(){return bg;}ObjectGuid GetObjectGuid(){return guid;}ObjectGuid getObjectGuid(){return guid;}char const*GetName(){return "fixture";}int GetStandState(){return stand;}void SetStandState(int s){stand=s;}void StopMoving(){++stops;}void TextEmote(std::string const&){++emotes;}};
struct GroupReference {Player*member=nullptr;GroupReference*following=nullptr;Player*GetSource(){return member;}GroupReference*next(){return following;}};
struct Group {Player*leader=nullptr;GroupReference*first=nullptr;ObjectGuid GetLeaderGuid(){return leader?leader->guid:0;}GroupReference*GetFirstMember(){return first;}};
struct Log {unsigned errors=0;template<class...T>void outError(T...){++errors;}}sLog;
struct Facade {bool free=true;bool IsFreeBot(Player*){return free;}}sRandomBotFacade;
struct ServerFacade {float distance=1;float getDistance2d(Player*,Player*){return distance;}bool isMoving(Player*p){return p->moving;}}sServerFacade;
struct Event {};
namespace TortoiseBots {
struct BotWorldActions {static bool map;bool accept=true;std::vector<std::function<void(PlayerbotAI&)>>work;static bool IsMapExecution(){return map;}static BotWorldActions&Instance(){static BotWorldActions q;return q;}bool EnqueueContinuation(Player*,char const*,Event,std::function<void(PlayerbotAI&)>f){if(!accept)return false;work.push_back(std::move(f));return true;}};
bool BotWorldActions::map=false;
struct BotManager {bool registered=true,accept=true;unsigned binds=0,clears=0;PlayerbotAI*current=nullptr;Player*next=nullptr;static BotManager&Instance(){static BotManager m;return m;}bool IsBot(ObjectGuid){return registered;}bool BindBotMaster(ObjectGuid,ObjectGuid);bool ClearBotMaster(ObjectGuid);};
}
struct PlayerbotAIStorage {static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}void*GetAI(Player*p){return p&&!p->real?p:nullptr;}};
struct PlayerbotAI {Player*bot=nullptr,*master=nullptr;bool active=false,hasBg=true,silent=true,explicitActivityOverride=false;unsigned strategies=0,resets=0,changes=0,tells=0;unsigned aiInternalUpdateDelay=0;std::weak_ptr<int>pendingMasterReconciliation;
 void ReconcileMasterAndPosture();bool HasActivePlayerMaster(){return active;}bool IsRealPlayer(){return bot->real;}Player*GetMaster(){return master;}void SetMaster(Player*p){master=p;}void ResetStrategies(){++strategies;}void Reset(bool){++resets;}Player*GetGroupMaster(){return bot->group?bot->group->leader:nullptr;}bool IsInGroup_Helper(Player*p,Player*b,bool){return p->group&&p->group==b->group;}std::string GetDefaultMovementStrategy(){return "follow";}void ChangeStrategy(std::string const&,BotState){++changes;}bool HasStrategy(char const*name,BotState){return std::string(name)=="silent"?silent:hasBg;}void TellPlayer(Player*,char const*){++tells;}bool IsSafe(Player*p,Player*q){return p&&q&&p->inWorld&&q->inWorld&&!p->teleport&&!q->teleport&&p->map==q->map;}
 void ForcedActivity(bool forceActivity,std::function<void()>body){
#include "ModuleActivityOverrideScope.inc"
 body();
 }
};
bool TortoiseBots::BotManager::BindBotMaster(ObjectGuid,ObjectGuid){Check(!BotWorldActions::map,"master bind must be world owned");if(!accept)return false;++binds;current->master=next;return true;}
bool TortoiseBots::BotManager::ClearBotMaster(ObjectGuid){Check(!BotWorldActions::map,"master release must be world owned");if(!accept)return false;++clears;current->master=nullptr;return true;}
#include "ModuleMasterReconciliation.inc"
void Drain(PlayerbotAI&ai){auto&q=TortoiseBots::BotWorldActions::Instance();auto work=std::move(q.work);q.work.clear();TortoiseBots::BotWorldActions::map=false;for(auto&f:work)f(ai);}
int main(){using namespace TortoiseBots;Player bot{1},human{2},other{3};human.real=true;other.real=true;Group group{&human};bot.group=&group;human.group=&group;other.group=&group;PlayerbotAI ai;ai.bot=&bot;auto&m=BotManager::Instance();m.current=&ai;m.next=&human;auto&q=BotWorldActions::Instance();
 BotWorldActions::map=true;ai.ReconcileMasterAndPosture();ai.ReconcileMasterAndPosture();Check(q.work.size()==1&&!ai.master&&!m.binds,"map requests coalesce without changing ownership");
 group.leader=&other;m.next=&other;Drain(ai);Check(ai.master==&other&&m.binds==1&&ai.resets==1&&bot.stops==1,"world continuation adopts current group leader, not captured player");
 ai.ReconcileMasterAndPosture();Check(m.binds==1,"repeated reconciliation preserves existing leader without replaying adoption");
 BotWorldActions::map=true;q.accept=false;ai.ReconcileMasterAndPosture();Check(q.work.empty()&&ai.pendingMasterReconciliation.expired(),"queue rejection releases coalescing token");q.accept=true;ai.ReconcileMasterAndPosture();Check(q.work.size()==1,"rejected work can retry");q.work.clear();Check(ai.pendingMasterReconciliation.expired(),"discard releases coalescing token");
 ai.ReconcileMasterAndPosture();bot.teleport=true;Drain(ai);Check(m.binds==1,"transfer suppresses world reconciliation");bot.teleport=false;
 bot.group=nullptr;ai.active=false;m.accept=false;ai.ReconcileMasterAndPosture();Check(ai.master==&other&&!m.clears,"failed native release preserves master");m.accept=true;ai.ReconcileMasterAndPosture();Check(!ai.master&&m.clears==1,"world release clears abandoned group ownership");
 bot.group=&group;group.leader=&human;m.next=&human;ai.ReconcileMasterAndPosture();Check(ai.master==&human,"human ownership reacquired");ai.active=true;human.m_movementInfo.walk=true;human.stand=UNIT_STAND_STATE_SIT;ai.ReconcileMasterAndPosture();Check(bot.m_movementInfo.walk&&bot.stand==UNIT_STAND_STATE_SIT,"same-map human posture mirrored");
 human.map=2;ai.ReconcileMasterAndPosture();Check(!bot.m_movementInfo.walk,"cross-map master cannot impose walking");ai.ReconcileMasterAndPosture();Check(bot.stand==UNIT_STAND_STATE_STAND,"cross-map sitting released");
 bot.bg=true;ai.hasBg=false;ai.ReconcileMasterAndPosture();Check(ai.strategies>=3,"native battleground strategy reconciliation retained");
 ai.explicitActivityOverride=false;try{ai.ForcedActivity(true,[&]{Check(ai.explicitActivityOverride,"forced action is active");ai.ForcedActivity(false,[&]{Check(ai.explicitActivityOverride,"nested call preserves outer activity");});throw std::runtime_error("action failure");});}catch(std::runtime_error const&){}Check(!ai.explicitActivityOverride,"action exception restores activity override");
 ai.explicitActivityOverride=true;ai.ForcedActivity(false,[]{});Check(ai.explicitActivityOverride,"existing caller override retained");
 std::cout<<"World master reconciliation, current-state adoption, rejection, posture and exception recovery passed\n";
}
