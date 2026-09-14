#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
using uint32=unsigned;
enum {CLASS_WARLOCK=9};
struct Group{};
struct Player{unsigned cls=CLASS_WARLOCK;Group*group=nullptr;unsigned GetClass(){return cls;}Group const*GetGroup(){return group;}};
enum class WorldBuffTravelStep{STEP_BOOTY_BAY,STEP_DM_TRAVEL,STEP_DM_PORTAL,STEP_SONGFLOWER,STEP_PORTAL_HOME,OTHER};
struct Value{time_t value=0;time_t Get(){return value;}void Set(time_t n){value=n;}};
struct Context{Value time;template<class T>Value*GetValue(char const*){return &time;}};
time_t nowValue=100;time_t NativeTime(std::nullptr_t){return nowValue;}
unsigned rolls=0;uint32 urand(uint32,uint32){++rolls;return 5;}
class WorldBuffTravelApplyAction{public:Player*bot;Context*context;bool TrySummonFarAwayMembers(WorldBuffTravelStep);};
#define time NativeTime
#include "ModuleWorldBuffCooldown.inc"
    return false; // Fixture stops before target discovery and native summons.
}
#undef time
bool Finish(Value* summonTime, bool didSummon, uint32 pendingCount, uint32 remainingToSummon){
#include "ModuleWorldBuffCooldownFinish.inc"
}
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){Group group;Player player;player.group=&group;Context first,other;
 WorldBuffTravelApplyAction a{&player,&first},sameAI{&player,&first},otherAI{&player,&other};
 auto step=WorldBuffTravelStep::STEP_BOOTY_BAY;
 Check(!a.TrySummonFarAwayMembers(step)&&rolls==1&&first.time.value==105,"first eligible attempt records cooldown");
 Check(sameAI.TrySummonFarAwayMembers(step)&&rolls==1,"another action instance of same AI shares cooldown");
 Check(!otherAI.TrySummonFarAwayMembers(step)&&rolls==2,"other AI and replacement login have independent cooldown");
 nowValue=105;Check(!a.TrySummonFarAwayMembers(step)&&rolls==3,"expired cooldown admits next attempt");
 player.cls=1;Check(!a.TrySummonFarAwayMembers(step)&&rolls==3,"non-warlock does not mutate cooldown");
 player.cls=CLASS_WARLOCK;Check(!a.TrySummonFarAwayMembers(WorldBuffTravelStep::OTHER)&&rolls==3,"unrelated travel step does not mutate cooldown");
 Check(Finish(&first.time,false,1,0)&&first.time.value==110,"pending member retains cooldown");
 Check(!Finish(&first.time,false,0,0)&&first.time.value==0,"completed regrouping clears cooldown");
 std::cout<<"World-buff summon cooldown is per AI incarnation and shared across its action instances\n";
}
