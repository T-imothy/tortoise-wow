#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "ActionFailureBackoff.h"
using uint32=uint32_t; using uint64=uint64_t;
#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x << '\n'; std::exit(1); } } while(0)
struct { uint32 failedActionRetryBaseMs=250,failedActionRetryMaxMs=2000,failedActionCacheTtlMs=30000,failedActionCacheMaxEntries=64; } sPlayerbotAIConfig;
namespace WorldTimer { uint32 now=100; uint32 getMSTime(){return now;} }
enum ActionResult { ACTION_RESULT_IMPOSSIBLE, ACTION_RESULT_FAILED };
enum class BotState { BOT_STATE_NON_COMBAT, BOT_STATE_COMBAT };
constexpr float ACTION_HIGH=100;
struct Unit { std::string GetName(){return "target";} };
struct Player:Unit {
 bool combat=false,alive=true;float x=0,y=0,z=0;uint32 money=10,health=100,power=100;uint64 generation=1;
 bool IsInCombat() const{return combat;} bool IsAlive() const{return alive;}
 float GetPositionX() const{return x;} float GetPositionY() const{return y;} float GetPositionZ() const{return z;}
 uint32 GetMoney() const{return money;} uint32 GetHealth() const{return health;}
 int GetPowerType() const{return 1;} uint32 GetPower(int type)const{CHECK(type==1);return power;}
 uint64 GetMapWorkGeneration()const{return generation;}
};
struct AI {Player p;bool human=false,real=false,owned=false;Player* GetBot(){return &p;}bool HasRealPlayerMaster()const{return human;}bool IsRealPlayer()const{return real;}bool IsOwnedBot()const{return owned;}};
struct Action {int id=0;bool reaction=false;float relevance=1;bool IsReaction()const{return reaction;}float getRelevance()const{return relevance;}Unit* GetTarget(){return nullptr;}std::string getName(){return std::to_string(id);}};
struct Event {Player* owner=nullptr;std::vector<int> packet;Player* getOwner(){return owner;}auto& getPacket(){return packet;}};
struct { bool IsEnabled(){return false;}void OnActionFailed(Player*,std::string,std::string){} } sObservabilityEmitter;
class Engine {
public:
 AI* ai;BotState state=BotState::BOT_STATE_NON_COMBAT;ai::ActionFailureBackoff actionFailures;
 float failX=0,failY=0,failZ=0;uint32 failMoney=0,failHealth=0,failMana=0;uint64 failureMapGeneration=0;
 std::string FailureKey(Action* a,Event&,ActionResult reason)const{return std::to_string(a->id)+":"+std::to_string(reason);}
 bool AllowBackgroundRetry(Action*,Event&)const;
 bool IsFailureBackedOff(Action*,Event&)const;
 void RecordFailure(Action*,Event&,ActionResult);
 void ClearActionFailures(Action*,Event&);
 void RefreshFailureContext();
};
#include "BotRetryPolicy.inc"
int main(){
 AI ai;Engine e{&ai};Action a;Event event;
 e.RefreshFailureContext();CHECK(e.AllowBackgroundRetry(&a,event));
 ai.human=true;CHECK(!e.AllowBackgroundRetry(&a,event));ai.human=false;
 ai.real=true;CHECK(!e.AllowBackgroundRetry(&a,event));ai.real=false;
 ai.owned=true;CHECK(!e.AllowBackgroundRetry(&a,event));ai.owned=false;
 ai.p.combat=true;CHECK(!e.AllowBackgroundRetry(&a,event));ai.p.combat=false;
 ai.p.alive=false;CHECK(!e.AllowBackgroundRetry(&a,event));ai.p.alive=true;
 e.state=BotState::BOT_STATE_COMBAT;CHECK(!e.AllowBackgroundRetry(&a,event));e.state=BotState::BOT_STATE_NON_COMBAT;
 a.reaction=true;CHECK(!e.AllowBackgroundRetry(&a,event));a.reaction=false;
 a.relevance=ACTION_HIGH;CHECK(!e.AllowBackgroundRetry(&a,event));a.relevance=1;
 event.owner=&ai.p;CHECK(!e.AllowBackgroundRetry(&a,event));event.owner=nullptr;
 event.packet.push_back(1);CHECK(!e.AllowBackgroundRetry(&a,event));event.packet.clear();
 e.RecordFailure(&a,event,ACTION_RESULT_IMPOSSIBLE);CHECK(e.actionFailures.Size()==0);
 e.RecordFailure(&a,event,ACTION_RESULT_FAILED);CHECK(e.IsFailureBackedOff(&a,event));
 WorldTimer::now+=249;CHECK(e.IsFailureBackedOff(&a,event));++WorldTimer::now;CHECK(!e.IsFailureBackedOff(&a,event));
 e.RecordFailure(&a,event,ACTION_RESULT_FAILED);WorldTimer::now+=499;CHECK(e.IsFailureBackedOff(&a,event));++WorldTimer::now;CHECK(!e.IsFailureBackedOff(&a,event));
 for(int i=0;i<10;++i)e.RecordFailure(&a,event,ACTION_RESULT_FAILED);
 WorldTimer::now+=1999;CHECK(e.IsFailureBackedOff(&a,event));++WorldTimer::now;CHECK(!e.IsFailureBackedOff(&a,event));
 Action other;other.id=1;CHECK(!e.IsFailureBackedOff(&other,event));e.ClearActionFailures(&a,event);CHECK(e.actionFailures.Size()==0);
 sPlayerbotAIConfig.failedActionCacheMaxEntries=2;
 for(int i=0;i<20;++i){a.id=i;++WorldTimer::now;e.RecordFailure(&a,event,ACTION_RESULT_FAILED);CHECK(e.actionFailures.Size()<=2);}
 a.id=0;CHECK(!e.IsFailureBackedOff(&a,event));a.id=19;CHECK(e.IsFailureBackedOff(&a,event));
 WorldTimer::now+=30001;e.RefreshFailureContext();CHECK(e.actionFailures.Size()==0);
 for(int change=0;change<7;++change){
  e.RecordFailure(&a,event,ACTION_RESULT_FAILED);CHECK(e.actionFailures.Size()==1);
  if(change==0)++ai.p.x;if(change==1)++ai.p.money;if(change==2)--ai.p.power;
  if(change==3)ai.human=true;if(change==4)ai.owned=true;if(change==5)++ai.p.generation;if(change==6)ai.p.combat=true;
  e.RefreshFailureContext();CHECK(e.actionFailures.Size()==0);ai.human=ai.owned=ai.p.combat=false;
 }
 WorldTimer::now=0xfffffff0u;e.RecordFailure(&a,event,ACTION_RESULT_FAILED);CHECK(e.IsFailureBackedOff(&a,event));WorldTimer::now+=250;CHECK(!e.IsFailureBackedOff(&a,event));
 sPlayerbotAIConfig.failedActionRetryBaseMs=0;CHECK(!e.AllowBackgroundRetry(&a,event));e.RefreshFailureContext();CHECK(e.actionFailures.Size()==0);
 std::cout<<"Selected-module bounded retry cache, ownership eligibility, resource and map invalidation passed\n";
}
