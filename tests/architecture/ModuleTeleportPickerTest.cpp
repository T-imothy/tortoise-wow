#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using uint32=unsigned;using int32=int;
enum{HIGHGUID_UNIT,UNIT_NPC_FLAG_INNKEEPER};
struct AreaTableEntry{unsigned Id=1;};
struct Player{unsigned map=0,level=10;float x=0;unsigned GetMapId(){return map;}unsigned GetLevel(){return level;}char const*GetName(){return "Fixture";}};
namespace ai {
enum class TravelDestinationPurpose{GenericRpg,Grind};
struct WorldPosition{unsigned map=0;float x=0;bool enemy=false,usable=true;AreaTableEntry area;unsigned flag=1;unsigned getMapId()const{return map;}float sqDistance(WorldPosition const&other)const{return (x-other.x)*(x-other.x);}unsigned getAreaFlag(){return flag;}AreaTableEntry const*GetArea(){return &area;}bool IsEnemyHomeZoneFor(unsigned){return enemy;}};
struct PlayerTravelInfo{WorldPosition position;PlayerTravelInfo(Player*p){position.map=p->map;position.x=p->x;}auto const&getPosition(){return position;}unsigned GetTeam(){return 0;}};
struct TravelDestination{bool possible=true;unsigned entry=1;std::vector<WorldPosition*>points;virtual ~TravelDestination()=default;bool IsPossible(PlayerTravelInfo const&){return possible;}unsigned GetEntry(){return entry;}auto GetPoints(){return points;}};
struct EntryTravelDestination:TravelDestination{bool creature=true,inn=false;bool GetCreatureInfo(){return creature;}bool HasNpcFlag(int){return inn;}};
std::set<unsigned>hostile;
struct GuidPosition{unsigned entry;GuidPosition(int,unsigned e):entry(e){}bool IsHostileTo(Player*){return hostile.count(entry)!=0;}};
struct TravelMgr{std::vector<TravelDestination*>destinations;auto GetDestinations(PlayerTravelInfo,unsigned,std::vector<int>,bool,float){return destinations;}bool TryGetValidatedAreaLevel(unsigned,int32&level){level=10;return true;}};
}
namespace MaNGOS {template<class T>struct Singleton{static T&Instance(){static T value;return value;}};}
struct Log{template<class...T>void outString(char const*,T...){}}sLog;
unsigned urand(unsigned minimum,unsigned){return minimum;}
unsigned probes=0;std::set<ai::WorldPosition const*>probed;
bool IsUsableTeleportPoint(ai::WorldPosition const&point){++probes;probed.insert(&point);return point.usable;}
#include "ModuleTeleportPicker.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){Player bot;auto&mgr=MaNGOS::Singleton<ai::TravelMgr>::Instance();ai::WorldPosition good;
 std::vector<ai::EntryTravelDestination>destinations(41);for(auto&d:destinations){d.points={&good};mgr.destinations.push_back(&d);}destinations.back().inn=true;
 Check(PickLevelFittingPoint(&bot,ai::TravelDestinationPurpose::GenericRpg,0,true,true)==&good&&probes==1,"rare inn filtered before bounded terrain probing");
 ai::WorldPosition far;far.x=2000;ai::WorldPosition otherMap;otherMap.map=1;ai::WorldPosition near;near.x=500;
 destinations.back().points={&far,&otherMap,&near};mgr.destinations={&destinations.back()};probes=0;
 Check(PickLevelFittingPoint(&bot,ai::TravelDestinationPurpose::Grind,1000,false,true)==&near&&probes==1,"local limit applies to selected spawn and map before terrain work");
 ai::hostile.insert(1);Check(!PickLevelFittingPoint(&bot,ai::TravelDestinationPurpose::GenericRpg,0,true,true),"hostile inn rejected");ai::hostile.clear();
 std::vector<ai::WorldPosition>bad(40);mgr.destinations.clear();probes=0;probed.clear();
 for(unsigned i=0;i<40;++i){bad[i].usable=false;destinations[i].points={&bad[i]};mgr.destinations.push_back(&destinations[i]);}
 Check(!PickLevelFittingPoint(&bot)&&probes==32&&probed.size()==32,"destination attempts bounded and never waste probes on a repeated choice");
 mgr.destinations={&destinations[0]};destinations[0].points.clear();for(auto&p:bad)destinations[0].points.push_back(&p);probes=0;probed.clear();
 Check(!PickLevelFittingPoint(&bot)&&probes==8&&probed.size()==8,"point attempts bounded without repeats");
 std::cout<<"Native teleport picker validates each local point, inn membership and distinct bounded probes\n";
}
