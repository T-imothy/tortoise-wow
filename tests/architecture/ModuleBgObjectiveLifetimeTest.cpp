
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
using uint32=std::uint32_t; using uint64=std::uint64_t;
struct ObjectGuid { unsigned value=0; void Clear(){value=0;} bool IsEmpty()const{return !value;} };
struct BattlegroundObjectiveState { ObjectGuid guid; uint64 mapGeneration=0; uint32 selectedAt=0; };
struct GameObject { ObjectGuid guid; ObjectGuid GetObjectGuid()const{return guid;} };
struct Map { std::map<unsigned,GameObject*> objects; GameObject* GetGameObject(ObjectGuid guid){auto it=objects.find(guid.value);return it==objects.end()?nullptr:it->second;} };
struct Player { Map* map; BattlegroundObjectiveState memory; bool dead=false,inWorld=true; uint64 generation=1; bool IsDead(){return dead;}bool IsInWorld(){return inWorld;}uint64 GetMapWorkGeneration(){return generation;}Map*GetMap(){return map;} };
struct WorldTimer { static uint32 getMSTime(){return 100;} };
struct BGTactics {
    Player*bot;
    GameObject* PreviousAbObjective(); void RememberAbObjective(GameObject*);
};
#define AI_VALUE(type,name) (&bot->memory)
#include "ModuleBgObjectiveMemory.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){
 Map first,second;GameObject flag{{12}},other{{21}};first.objects[12]=&flag;second.objects[21]=&other;
 Player a{&first},b{&second};BGTactics left{&a},right{&b};
 left.RememberAbObjective(&flag);right.RememberAbObjective(&other);
 BGTactics anotherAction{&a};
 Check(anotherAction.PreviousAbObjective()==&flag,"different actions for one AI share objective identity");
 Check(left.PreviousAbObjective()==&flag&&right.PreviousAbObjective()==&other,"independent bots and maps");
 first.objects.erase(12);Check(!left.PreviousAbObjective(),"despawn never returns stale pointer");
 flag.guid={99};first.objects[99]=&flag;Check(!left.PreviousAbObjective(),"recycled address does not inherit old GUID");
 left.RememberAbObjective(&flag);a.map=&second;++a.generation;
 Check(!left.PreviousAbObjective()&&a.memory.guid.IsEmpty(),"map transition invalidates objective");
 left.RememberAbObjective(&other);a.dead=true;Check(!left.PreviousAbObjective(),"death clears objective");
 a.dead=false;left.RememberAbObjective(&other);a.inWorld=false;Check(!left.PreviousAbObjective(),"out-of-world lifetime invalidated");
 Check(right.PreviousAbObjective()==&other,"other AI's objective unaffected");
 std::cout<<"Arathi objective identity, transitions, death and independent AI state passed\n";
}
