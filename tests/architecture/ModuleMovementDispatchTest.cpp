#include <cmath>
#include <vector>
#include <stdexcept>
#include <iostream>
using uint32=unsigned;
enum ForcedMovement{FORCED_MOVEMENT_WALK,FORCED_MOVEMENT_RUN};
enum{MOVE_WALK_MODE=1,MOVE_RUN_MODE=2,MOVE_PATHFINDING=4};
struct Point{float x=0,y=0,z=0;};
struct Transport{void CalculatePassengerPosition(float&,float&,float&){}void CalculatePassengerOffset(float&,float&,float&){} };
struct MotionMaster{
 int clears=0,pointStarts=0,pathStarts=0;uint32 options=0;bool walked=false;std::vector<Point> route;
 void Clear(){++clears;}
 void MovePoint(uint32,float x,float y,float z,uint32 flags){++pointStarts;options=flags;route={{x,y,z}};}
 void MovePath(std::vector<Point> p,ForcedMovement,bool,bool walk){++pathStarts;route=p;walked=walk;}
};
struct Player{float x=0;bool fly=false;MotionMaster motion;MotionMaster* GetMotionMaster(){return &motion;}bool IsFreeFlying(){return fly;}Transport* GetTransport(){return nullptr;}void UpdateAllowedPositionZ(float&,float&,float&){} };
struct WorldPosition{
 float x=0,y=0,z=0;WorldPosition()=default;WorldPosition(float px):x(px){}WorldPosition(Player* p):x(p->x){}
 float distance(Player* p)const{return std::fabs(x-p->x);}uint32 GetMapId()const{return 821;}
 float getX()const{return x;}float getY()const{return y;}float getZ()const{return z;}
 std::vector<Point> toPointsArray(std::vector<WorldPosition> p){std::vector<Point> out;for(auto v:p)out.push_back({v.x,v.y,v.z});return out;}
 float GetPathLength(std::vector<WorldPosition> p){float sum=0;for(unsigned i=1;i<p.size();++i)sum+=std::fabs(p[i].x-p[i-1].x);return sum;}
};
struct TravelPath{std::vector<WorldPosition> points;std::vector<WorldPosition> GetPointPath(){return points;}};
struct MovementAction{
 Player* bot;float waited=-1;int hazards=0;
 void GeneratePathAvoidingHazards(std::vector<WorldPosition>&){++hazards;}
 void WaitForReach(float distance){waited=distance;}
 void DispatchMovement(TravelPath,bool,bool);
};
#include "ModuleMovementDispatchNative.inc"
void Check(bool v,const char* msg){if(!v)throw std::runtime_error(msg);}
int main(){try{
 for(bool walk:{false,true}){
  Player player;MovementAction action{&player};action.DispatchMovement({{WorldPosition(5),WorldPosition(10)}},true,walk);
  Check(player.motion.pathStarts==1&&player.motion.pointStarts==0,"precomputed path has two movement owners");
  Check(player.motion.route.size()==3&&player.motion.route[0].x==0&&player.motion.route[1].x==5,"first route corner overwritten");
  Check(player.motion.walked==walk,"walk/run intent lost");Check(action.waited==10,"wait did not include live origin");
 }
 Player p;MovementAction a{&p};a.DispatchMovement({},true,false);Check(p.motion.clears==0,"empty path clears active movement");
 a.DispatchMovement({{WorldPosition(0.0f),WorldPosition(10)}},true,false);Check(p.motion.route.size()==2,"duplicate live origin inserted");
 for(bool generate:{false,true}){Player single;MovementAction one{&single};one.DispatchMovement({{WorldPosition(10)}},generate,true);
  Check(single.motion.pointStarts==1&&single.motion.pathStarts==0,"single point has multiple owners");
  Check(single.motion.options==(MOVE_WALK_MODE|(generate?MOVE_PATHFINDING:0)),"native point options corrupted");}
 Player flying;flying.fly=true;MovementAction f{&flying};f.DispatchMovement({{WorldPosition(0.0f),WorldPosition(10)}},true,false);
 Check(flying.motion.pointStarts==1&&flying.motion.pathStarts==0,"free-flight path lost native point owner");
 std::cout<<"Active module dispatch preserves a single native movement owner, route corners and walk flags\n";
 }catch(std::exception const& e){std::cerr<<e.what()<<'\n';return 1;}}
