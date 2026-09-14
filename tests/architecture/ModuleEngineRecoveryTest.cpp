#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using uint32=uint32_t; using uint64=uint64_t;
#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x << '\n'; std::exit(1); } } while(0)
std::string failure;
void Fail(char const* site) { if(failure==site) throw std::runtime_error(site); }
struct Unit {};
struct Player:Unit {
 bool world=true,teleport=false;uint32 map=1;uint64 generation=1;
 bool IsTaxiFlying(){return false;}bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}
 uint32 GetMapId(){return map;}uint64 GetMapWorkGeneration(){return generation;}
 float GetPositionX(){return 0;}float GetPositionY(){return 0;}float GetPositionZ(){return 0;}
 int GetTeam(){return 0;}void Say(std::string,int){}
};
enum class BotState { BOT_STATE_NON_COMBAT };
char const* BotStateName(BotState){return "test";}
enum class PlayerbotSecurityLevel { PLAYERBOT_SECURITY_ALLOW_ALL };
constexpr int ALLIANCE=0, LANG_COMMON=0, LANG_ORCISH=1;
enum ActionResult {ACTION_RESULT_FAILED=1,ACTION_RESULT_UNKNOWN,ACTION_RESULT_OK,ACTION_RESULT_IMPOSSIBLE,ACTION_RESULT_USELESS,ACTION_RESULT_DEFERRED};
class Engine;
struct Event;
struct AI {
 Engine* current=nullptr;Engine* GetCurrentEngine(){return current;}
 unsigned commands=0;bool DoSpecificAction(std::string const&,Event const&,bool){++commands;return true;}
 Player p;uint64 transition=1;Player* GetBot(){return &p;}Player* GetMaster(){return nullptr;}
 uint64 GetTransitionGeneration(){return transition;}void HandleCommands(){Fail("commands");}
 template<class... T> void TellPlayerNoFacing(T&&...){}
};
struct Event {bool expired=false;bool HasExpiredOwner() const{return expired;}Player* getOwner(){return nullptr;}std::string source="test payload";std::string getSource()const{return source;}};
using PlayerbotAI=AI;
namespace TortoiseBots {
struct BotWorldActions {
 static inline bool map=false,admit=true;
 std::vector<std::function<void(PlayerbotAI&)>> pending;
 static BotWorldActions& Instance(){static BotWorldActions q;return q;}
 static bool IsMapExecution(){return map;}
 bool EnqueueContinuation(Player*,std::string const&,Event const&,std::function<void(PlayerbotAI&)> f){if(!admit)return false;pending.push_back(std::move(f));return true;}
 void Drain(AI& ai){auto callbacks=std::move(pending);pending.clear();bool prior=map;map=false;for(auto& f:callbacks)f(ai);map=prior;}
};}
struct NextAction {
 static inline int live=0;std::string name;float relevance;
 NextAction(std::string n,float r=0):name(std::move(n)),relevance(r){++live;}
 NextAction(NextAction const& v):name(v.name),relevance(v.relevance){Fail("next-copy");++live;}
 ~NextAction(){--live;}auto const& getName()const{return name;}float getRelevance()const{return relevance;}
 static void destroy(NextAction** actions){if(actions){for(int i=0;actions[i];++i)delete actions[i];delete[] actions;}}
};
struct Action {
 std::string name="work";float relevance=1;bool useful=true,possible=true,result=true,prerequisite=false;
 bool worldOwner=false;bool RequiresWorldOwner()const{return worldOwner;}
 std::function<void()> execute;
 auto getName(){return name;}float getRelevance(){return relevance;}void setRelevance(float r){relevance=r;}
 bool isUsefulWhenStunned(){return true;}bool isUseful(){Fail("useful");return useful;}
 bool isPossible(){Fail("possible");return possible;}
 void MakeVerbose(bool){}NextAction** getContinuers(){Fail("continuers");return nullptr;}
};
struct ActionNode {
 static inline int live=0;std::string name;Action* action;
 ActionNode(std::string n,Action* a):name(std::move(n)),action(a){++live;}
 ~ActionNode(){--live;}auto getName(){return name;}
 NextAction** getPrerequisites(){Fail("prerequisites");if(!action->prerequisite)return nullptr;action->prerequisite=false;return new NextAction*[2]{new NextAction("prereq",3),nullptr};}
 NextAction** getAlternatives(){Fail("alternatives");return nullptr;}
 NextAction** getContinuers(){Fail("continuers");return nullptr;}
};
struct ActionBasket {
 static inline int live=0;ActionNode* action;float relevance;bool skip;Event event;
 ActionBasket(ActionNode* a,float r,bool s,Event const& e):action(a),relevance(r),skip(s),event(e){++live;}
 ~ActionBasket(){--live;}ActionNode* getAction(){return action;}float getRelevance(){return relevance;}
 bool isSkipPrerequisites(){return skip;}Event getEvent(){return event;}
 void setRelevance(float r){relevance=r;}void setEvent(Event e){event=e;}
};
class Queue {
 std::list<ActionBasket*> actions;
 public:
 void Push(ActionBasket*);ActionNode* Pop(ActionBasket* =nullptr);ActionBasket* Peek();int Size();
 void RemoveExpired(){Fail("expire");}
};
#include "ModuleEngineQueue.inc"
struct Multiplier {float value=1;float GetValue(Action*){Fail("multiplier");return value;}std::string getName(){return "test";}};
struct Context {void Update(){Fail("context");}};
struct TransitionTracker {
 enum Event{NONE,AWAY};Event Update(bool world,bool teleport,uint32,float,float,float,uint64){return world&&!teleport?NONE:AWAY;}
 void NoteAway(){}
};
struct {bool logValuesPerTick=false;uint32 reactDelay=200,iterationsPerTick=10;template<class... T> bool CanLogAction(T&&...){return false;}} sPlayerbotAIConfig;
class Engine {
 public:
 AI* ai;Context context;Context* aiObjectContext=&context;Queue queue;Action work,prereq;
 BotState state=BotState::BOT_STATE_NON_COMBAT;TransitionTracker transitions;
 struct {void ClearAll(){}} actionFailures;
 std::shared_ptr<int> worldContinuationEpoch=std::make_shared<int>(0);std::weak_ptr<int> pendingWorldDecision;
 bool WorldContinuationPending()const{return !pendingWorldDecision.expired();}
 void CancelWorldContinuation(){worldContinuationEpoch=std::make_shared<int>(0);pendingWorldDecision.reset();}
 bool ScheduleWorldContinuation(Event const&,std::function<void(Engine&)>);
 bool inDoNextAction=false,reinitPending=false,backoff=false;float lastRelevance=0;int rebuilt=0,executed=0;
 std::list<Multiplier*> multipliers;
 Engine(AI* a):ai(a){ai->current=this;prereq.name="prereq";}
 ~Engine(){worldContinuationEpoch.reset();DrainQueue();}
 void DrainQueue(){while(auto* n=queue.Pop())delete n;}
 void Init(){CHECK(!inDoNextAction);Fail("init");CancelWorldContinuation();DrainQueue();++rebuilt;}
 void RequestInit(){if(inDoNextAction)reinitPending=true;else Init();}
 void LogValues(){}template<class... T> void LogAction(T&&...){}std::string StrategySignature(){return "test";}
 void RefreshFailureContext(){}void ProcessTriggers(bool){Fail("triggers");}void PushDefaultActions(){Fail("defaults");}
 Action* InitializeAction(ActionNode* n){Fail("initialize");return n->action;}
 ActionNode* CreateActionNode(std::string const& n){Fail("create");if(n=="missing-node")return nullptr;return new ActionNode(n,n=="missing-action"?nullptr:n=="prereq"?&prereq:&work);}
 bool ListenAndExecute(Action* a,Event&){++executed;if(a->execute)a->execute();Fail("execute");return a->result;}
 bool AllowBackgroundRetry(Action*,Event&){return true;}bool IsFailureBackedOff(Action*,Event&){return backoff;}
 void ClearActionFailures(Action*,Event&){}void RecordFailure(Action*,Event&,int){}
 bool DoNextAction(Unit* =nullptr,int=0,bool=false,bool=false);
 ActionResult ExecuteAction(std::string const&,Event&);bool QueueAction(std::string const&,float,Event const&);bool CanExecuteAction(std::string const&,bool,bool);
 bool MultiplyAndPush(NextAction**,float,bool,Event const&,char const*);
 bool MultiplyAndPush(std::vector<NextAction> const&,float,bool,Event const&,char const*);
 void PushAgain(ActionNode*,float,Event const&);
 void Add(float relevance=1){queue.Push(new ActionBasket(new ActionNode("work",&work),relevance,true,Event()));}
};
#include "ModuleEngineContinuation.inc"
#include "ModuleEngineWalk.inc"
#include "ModuleEnginePush.inc"
#include "ModuleEnginePushAgain.inc"
#include "ModuleEngineExplicit.inc"
struct Reaction {
 Action* action=nullptr;Event event;uint32 duration=0;
 void SetAction(Action* a){action=a;duration=1000;}void SetEvent(Event const& e){event=e;}
 bool IsValid(){return action!=nullptr;}Action* GetAction(){return action;}Event& GetEvent(){return event;}
 void Reset(){action=nullptr;duration=0;}bool Update(uint32 elapsed){duration=duration>elapsed?duration-elapsed:0;return duration<=100;}
};
class ReactionEngine:public Engine {
 public:using Engine::Engine;bool worldReactionFound=false;Reaction incomingReaction,ongoingReaction;
 uint32 aiReactionUpdateDelay=0;bool IsReacting(){return ongoingReaction.IsValid();}bool HasIncomingReaction(){return incomingReaction.IsValid();}
 bool CanUpdateAIReaction(){return aiReactionUpdateDelay<100&&ai->p.world&&!ai->p.teleport;}
 bool FindReaction(bool);bool StartReaction();void StopReaction();bool Update(uint32,bool,bool,bool&);
 void Reset(){CancelWorldContinuation();worldReactionFound=false;incomingReaction.Reset();ongoingReaction.Reset();aiReactionUpdateDelay=0;}
};
#include "ModuleEngineReaction.inc"
#include "ModuleEngineReactionLifecycle.inc"
template<class F> void Throws(F f,char const* site){failure=site;bool caught=false;try{f();}catch(std::runtime_error const& e){CHECK(std::string(e.what())==site);caught=true;}failure.clear();CHECK(caught);}
void NoLeaks(){CHECK(ActionNode::live==0);CHECK(ActionBasket::live==0);CHECK(NextAction::live==0);}
int main(){
 for(auto site:{"context","triggers","defaults","initialize","useful","multiplier","prerequisites","possible","execute","continuers","expire"}){
  AI ai;{Engine e(&ai);Multiplier m;e.multipliers.push_back(&m);e.Add();
   // Prerequisite failure requires the native prerequisite branch.
   if(std::string(site)=="prerequisites"){e.DrainQueue();e.queue.Push(new ActionBasket(new ActionNode("work",&e.work),1,false,Event()));}
   Throws([&]{e.DoNextAction();},site);CHECK(!e.inDoNextAction);
   e.RequestInit();CHECK(e.rebuilt==1);e.Add();CHECK(e.DoNextAction());CHECK(!e.inDoNextAction);
  }NoLeaks();
 }
 // A strategy mutation followed by failure must not rebuild during unwinding.
 {AI ai;Engine e(&ai);e.Add();e.work.execute=[&]{e.RequestInit();CHECK(e.reinitPending);Fail("execute");};
  Throws([&]{e.DoNextAction();},"execute");CHECK(!e.inDoNextAction);CHECK(e.reinitPending);CHECK(e.rebuilt==0);CHECK(ActionNode::live==0);
  // Failed rebuild retains the retry signal. Teleport defers it until arrival.
  ai.p.teleport=true;CHECK(!e.DoNextAction());CHECK(e.reinitPending);ai.p.teleport=false;
  Throws([&]{e.DoNextAction();},"init");CHECK(!e.inDoNextAction);CHECK(e.reinitPending);
  CHECK(!e.DoNextAction());CHECK(!e.reinitPending);CHECK(e.rebuilt==1);
  e.work.execute={};e.Add();CHECK(e.DoNextAction());
 }NoLeaks();
 // Normal completion services a requested rebuild once, after releasing the popped node.
 {AI ai;Engine e(&ai);e.work.execute=[&]{e.RequestInit();CHECK(e.rebuilt==0);};e.Add();CHECK(e.DoNextAction());CHECK(e.rebuilt==1);CHECK(!e.reinitPending);CHECK(!e.inDoNextAction);}NoLeaks();
 // A nested owner must retain its outer decision state even on an exception.
 {AI ai;Engine e(&ai);e.inDoNextAction=true;e.Add();Throws([&]{e.DoNextAction();},"execute");CHECK(e.inDoNextAction);e.inDoNextAction=false;}NoLeaks();
 // Native helper releases remaining inputs and the popped source on every failure.
 for(auto site:{"create","initialize","next-copy"}){
  AI ai;{Engine e(&ai);Throws([&]{e.PushAgain(new ActionNode("work",&e.work),1,Event());},site);}NoLeaks();
 }
 {AI ai;Engine e(&ai);Throws([&]{e.MultiplyAndPush(new NextAction*[3]{new NextAction("one"),new NextAction("two"),nullptr},1,false,Event(),"alt");},"initialize");}NoLeaks();
 // Successful duplicate merge and rejected zero relevance also have exactly one owner.
 {AI ai;Engine e(&ai);e.Add();CHECK(e.MultiplyAndPush(std::vector<NextAction>{NextAction("work")},2,false,Event(),"alt"));CHECK(e.queue.Size()==1);
  CHECK(!e.MultiplyAndPush(std::vector<NextAction>{NextAction("discard")},0,false,Event(),"cont"));e.DrainQueue();}NoLeaks();
 // The active reaction walk shares the same ownership guarantees and preserves payloads.
 for(auto site:{"initialize","useful","possible","alternatives"}){
  AI ai;{ReactionEngine e(&ai);e.Add();if(std::string(site)=="alternatives")e.work.possible=false;
   Throws([&]{e.FindReaction(false);},site);CHECK(ActionNode::live==0);CHECK(ActionBasket::live==0);
   e.work.possible=true;e.Add();CHECK(e.FindReaction(false));CHECK(e.incomingReaction.event.source=="test payload");
  }NoLeaks();
 }
 // Prerequisite replacement succeeds without double deletion of the original node.
 {AI ai;Engine e(&ai);e.work.prerequisite=true;e.queue.Push(new ActionBasket(new ActionNode("work",&e.work),1,false,Event()));CHECK(e.DoNextAction());e.DrainQueue();}NoLeaks();
 // Explicit command and capability-query paths must release nodes on failure too.
 for(auto site:{"initialize","useful","possible","execute","continuers"}){
  AI ai;{Engine e(&ai);Event event;Throws([&]{e.ExecuteAction("work",event);},site);CHECK(ActionNode::live==0);CHECK(e.ExecuteAction("work",event)==ACTION_RESULT_OK);}NoLeaks();
 }
 for(auto site:{"initialize","useful","possible"}){AI ai;{Engine e(&ai);Throws([&]{e.CanExecuteAction("work",true,true);},site);CHECK(ActionNode::live==0);}NoLeaks();}
 {AI ai;Engine e(&ai);Event event;Throws([&]{e.QueueAction("work",1,event);},"initialize");CHECK(ActionNode::live==0);CHECK(e.QueueAction("work",1,event));CHECK(e.QueueAction("work",2,event));CHECK(e.queue.Size()==1);e.DrainQueue();}NoLeaks();
 {AI ai;Engine e(&ai);Event stale;stale.expired=true;failure="create";
  CHECK(e.ExecuteAction("work",stale)==ACTION_RESULT_FAILED);CHECK(!e.QueueAction("work",1,stale));failure.clear();
  CHECK(!e.CanExecuteAction("missing-node",true,true));CHECK(!e.CanExecuteAction("missing-action",true,true));
  e.queue.Push(new ActionBasket(new ActionNode("work",&e.work),1,true,stale));CHECK(!e.DoNextAction());CHECK(e.executed==0);CHECK(e.queue.Size()==0);
 }NoLeaks();
 // Deferred decisions retain the exact basket and cannot run eligibility/listeners early.
 {AI ai;Engine e(&ai);auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;e.work.worldOwner=true;e.Add();
  failure="useful";CHECK(!e.DoNextAction());CHECK(e.executed==0&&e.queue.Size()==1&&q.pending.size()==1);
  CHECK(!e.DoNextAction());CHECK(q.pending.size()==1);failure.clear();q.Drain(ai);CHECK(e.executed==1&&e.queue.Size()==0&&!e.WorldContinuationPending());
  // Backpressure retains the basket; no false success/failure or side effect.
  q.admit=false;e.Add();CHECK(!e.DoNextAction());CHECK(e.queue.Size()==1&&q.pending.empty()&&!e.WorldContinuationPending());q.admit=true;
  CHECK(!e.DoNextAction());e.Init();q.Drain(ai);CHECK(e.executed==1);q.map=false;
 }NoLeaks();
 // Reset/destruction, discarded queue and changed AI identity cancel continuations.
 {AI ai,other;auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;
  {Engine e(&ai);e.work.worldOwner=true;e.Add();CHECK(!e.DoNextAction());}q.Drain(ai);
  {Engine e(&ai);e.work.worldOwner=true;e.Add();CHECK(!e.DoNextAction());q.Drain(other);CHECK(e.executed==0&&!e.WorldContinuationPending());
   CHECK(!e.DoNextAction());q.pending.clear();CHECK(!e.WorldContinuationPending());CHECK(!e.DoNextAction());q.Drain(ai);CHECK(e.executed==1);}
  q.map=false;
 }NoLeaks();
 {AI ai;Engine e(&ai);Event event;auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;e.work.worldOwner=true;
  failure="useful";CHECK(e.ExecuteAction("work",event)==ACTION_RESULT_DEFERRED);CHECK(e.executed==0&&ai.commands==0);failure.clear();q.Drain(ai);CHECK(ai.commands==1);
  q.admit=false;CHECK(e.ExecuteAction("work",event)==ACTION_RESULT_FAILED);q.admit=true;q.map=false;
  // A native rejection must not even evaluate success continuers.
  e.work.result=false;failure="continuers";CHECK(e.ExecuteAction("work",event)==ACTION_RESULT_FAILED);failure.clear();
 }NoLeaks();
 {AI ai;ReactionEngine e(&ai);auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;e.work.worldOwner=true;e.Add();
  failure="useful";CHECK(!e.FindReaction(false));CHECK(e.queue.Size()==1&&!e.incomingReaction.IsValid());failure.clear();q.Drain(ai);
  CHECK(e.worldReactionFound&&e.incomingReaction.IsValid());q.map=false;
 }NoLeaks();
 // Deferred selection must announce interruption before starting the reaction.
 {AI ai;ReactionEngine e(&ai);auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;e.work.worldOwner=true;e.Add();bool found=false;
  CHECK(!e.Update(200,false,false,found));CHECK(!found&&e.executed==0);q.Drain(ai);
  CHECK(e.Update(200,false,false,found));CHECK(found&&e.executed==0); // PlayerbotAI interrupts here.
  CHECK(e.Update(200,false,false,found));CHECK(!found&&e.executed==0);q.Drain(ai);
  CHECK(e.executed==1&&e.IsReacting());e.Reset();q.map=false;
 }NoLeaks();
 // An eligibility change or reset between selection and execution cancels it.
 {AI ai;ReactionEngine e(&ai);auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;e.work.worldOwner=true;
  e.incomingReaction.SetAction(&e.work);CHECK(!e.StartReaction());e.work.possible=false;q.Drain(ai);CHECK(e.executed==0&&!e.HasIncomingReaction());
  e.work.possible=true;e.incomingReaction.SetAction(&e.work);CHECK(!e.StartReaction());e.Reset();q.Drain(ai);CHECK(e.executed==0);q.map=false;
 }NoLeaks();
 {AI ai;Engine e(&ai);auto& q=TortoiseBots::BotWorldActions::Instance();q.map=true;e.work.worldOwner=true;e.Add();CHECK(!e.DoNextAction());
  ai.current=nullptr;q.Drain(ai);CHECK(e.executed==0&&e.queue.Size()==1);ai.current=&e;CHECK(!e.DoNextAction());q.Drain(ai);CHECK(e.executed==1);q.map=false;
 }NoLeaks();
 std::cout<<"Native decision/reaction exception recovery, deferred rebuild retry and action ownership passed\n";
}
