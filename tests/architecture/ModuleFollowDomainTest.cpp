#include <iostream>
#include <string>
struct Unit{bool safe=true;};
struct PlayerbotAI{bool IsSafe(Unit*target){return target&&target->safe;}};
struct Context{Unit*target=nullptr;struct Value{Unit*target;Unit*Get(){return target;}}value;template<class T>Value*GetValue(std::string const&){value.target=target;return &value;}};
struct FollowAction{Context*context;PlayerbotAI*ai;bool RequiresWorldOwner()const;};
#include "ModuleFollowDomain.inc"
namespace TortoiseBots{struct BotWorldActions{inline static bool map=false;static bool IsMapExecution(){return map;}};}
struct MovementAction{PlayerbotAI*ai;unsigned copiedPositions=0;bool MoveTo2(Unit*){++copiedPositions;return true;}bool Follow(Unit*,float,float);};
#include "ModuleFollowPositionGate.inc"
 return true;
}
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){PlayerbotAI ai;Context context;FollowAction action{&context,&ai};MovementAction movement{&ai};Unit local,foreign{false};
 CHECK(!action.RequiresWorldOwner());context.target=&local;CHECK(!action.RequiresWorldOwner());context.target=&foreign;CHECK(action.RequiresWorldOwner());
 TortoiseBots::BotWorldActions::map=true;CHECK(!movement.Follow(&foreign,0,0)&&movement.copiedPositions==0);CHECK(!movement.Follow(nullptr,0,0));CHECK(movement.Follow(&local,0,0));
 TortoiseBots::BotWorldActions::map=false;CHECK(movement.Follow(&foreign,0,0)&&movement.copiedPositions==1);CHECK(!movement.Follow(nullptr,0,0)&&movement.copiedPositions==1);
 std::cout<<"Follow domain passed: local map decisions, cross-map world admission, no foreign position copy on map and retained world travel\n";
}
