// Actual resolver -> point spline request -> path handoff. Native geometry is
// covered separately by the asset probe; these fixtures exercise failure flags.
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
using uint32=uint32_t;
#define MANGOSBOT_ZERO
constexpr int BATTLEGROUND_TG=6,LOG_BG=1;
struct Vector3 {float x=0,y=0,z=0;Vector3()=default;Vector3(float a,float b,float c):x(a),y(b),z(c){}};
struct Transport {uint32 GetGUIDLow()const{return 1;}};
struct Unit;
struct BattleGround{virtual ~BattleGround()=default;};
struct BattleGroundTG:BattleGround{bool AdmitBotDiagnostic(Unit*){return false;}};
struct Log{static Log& Instance(){static Log l;return l;} template<class... A> void out(A...){} };
struct Unit{int bg=6;bool strict=true;int type=1;BattleGroundTG battle;int GetBattleGroundTypeId(){return bg;}bool InBattleGround(){return bg!=0;}BattleGround* GetBattleGround(){return &battle;}uint32 GetInstanceId(){return 102;}uint32 GetGUIDLow(){return 1;}};
struct WorldPosition{
 float x=0,y=0,z=0;uint32 map=821;
 float distance(const WorldPosition& p)const{return std::sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));}
 uint32 GetMapId()const{return map;}uint32 getMapId()const{return map;}float getX()const{return x;}float getY()const{return y;}float getZ()const{return z;}
 std::vector<WorldPosition> getPathTo(const WorldPosition&,Unit*)const;
 std::vector<WorldPosition> GetPathTo(const WorldPosition& p,Unit* u)const{return getPathTo(p,u);}
};
std::vector<WorldPosition> generated;
std::vector<WorldPosition> WorldPosition::getPathTo(const WorldPosition&,Unit*)const{return generated;}
struct TravelPath{std::vector<WorldPosition> p;bool empty()const{return p.empty();}WorldPosition GetBack()const{return p.back();}WorldPosition getBack()const{return p.back();}void addPath(std::vector<WorldPosition> v){p=v;}void addPoint(WorldPosition v){p.push_back(v);}};
struct LastMovement{TravelPath lastPath;};
struct Config{float sightDistance=60;}sPlayerbotAIConfig;
struct Nodes{std::vector<int> GetNodes(){return {};}TravelPath GetFullPath(WorldPosition,WorldPosition,Unit*){return {};}std::vector<int> getNodes(){return {};}TravelPath getFullPath(WorldPosition,WorldPosition,Unit*){return {};}}sTravelNodeMap;
struct MovementAction{Unit* bot;TravelPath ResolveMovePath(const WorldPosition&,const WorldPosition&,Unit*,LastMovement&,bool);};
#include "StrictResolverNative.inc"
enum{PATHFIND_NORMAL=1,PATHFIND_INCOMPLETE=2,PATHFIND_NOPATH=4,PATHFIND_SHORTCUT=8,PATHFIND_NOT_USING_PATH=16,PATHFIND_FLYPATH=32,PATHFIND_UNDERWATER=64};
enum{MOVE_PATHFINDING=1,MOVE_FORCE_DESTINATION=2,MOVE_EXCLUDE_STEEP_SLOPES=4,MOVE_STRAIGHT_PATH=8};
struct PathFinder{
 Unit* owner;bool strict;int type;std::vector<Vector3> points{{0,0,0},{100,100,60}};
 PathFinder(Unit* u):owner(u),strict(u->strict),type(u->type){}
 bool ExcludesSteepSlopes()const{return strict;}void ExcludeSteepSlopes(){strict=true;}
 int getPathType()const{return type;}const std::vector<Vector3>& getPath()const{return points;}
 Transport* GetTransport()const{return nullptr;}void setUseStrightPath(bool){}void calculate(float,float,float,bool){}
};
namespace Movement{
struct MoveSplineInit{
 Unit& unit;
 struct{std::vector<Vector3> path;bool uninterruptible=false;int path_Idx_offset=0;}args;
 bool stopped=false,flying=false;
 void MovebyPath(const std::vector<Vector3>& p){args.path=p;}void SetStop(){stopped=true;}
 void SetTransport(uint32){}void SetFly(){flying=true;}
 void Move(const PathFinder*);void MoveTo(float,float,float,uint32=0);void MoveTo(const Vector3&,uint32=0);
};
#include "StrictSplineMoveNative.inc"
#include "StrictSplineToNative.inc"
}
void Check(bool b,const char* s){if(!b)throw std::runtime_error(s);}
int main(){try{
 Unit bot;MovementAction action{&bot};LastMovement last;WorldPosition start{},end{100,100,60};
 Check(action.ResolveMovePath(start,end,&bot,last,true).empty(),"failed Thorn route became destination-only move");
 for(unsigned map:{0u,1u,30u,489u,529u,33u,409u,821u}){start.map=end.map=map;bot.bg=0;Check(action.ResolveMovePath(start,end,&bot,last,true).empty(),"failed generic ground route became direct move");}
 Check(action.ResolveMovePath(start,end,&bot,last,false).p.size()==1,"explicit direct intent lost");
 bot.bg=6;generated={start,{50,30,4},end};auto path=action.ResolveMovePath(start,end,&bot,last,true);Check(path.p.size()==3,"valid route lost");
 last.lastPath=path;generated.clear();Check(action.ResolveMovePath(start,end,&bot,last,true).p.size()==3,"valid cache lost");
 for(int type:std::vector<int>{PATHFIND_NOPATH,PATHFIND_NORMAL|PATHFIND_SHORTCUT,PATHFIND_NORMAL|PATHFIND_NOT_USING_PATH,0}){
  bot.type=type;Movement::MoveSplineInit init{bot};init.MoveTo(100,100,60,MOVE_PATHFINDING|MOVE_FORCE_DESTINATION);
  Check(init.stopped&&init.args.path.empty(),"failed/shortcut strict path launched across air");
 }
 for(int type:std::vector<int>{PATHFIND_NORMAL,PATHFIND_INCOMPLETE}){bot.type=type;Movement::MoveSplineInit init{bot};init.MoveTo(100,100,60,MOVE_PATHFINDING);Check(!init.stopped&&init.args.path.size()==2,"usable native prefix rejected");}
 bot.strict=false;bot.type=PATHFIND_NOPATH;Movement::MoveSplineInit legacy{bot};legacy.MoveTo(100,100,60,MOVE_PATHFINDING);Check(legacy.stopped&&legacy.args.path.empty(),"creature failed path launched");
 Movement::MoveSplineInit explicitStrict{bot};explicitStrict.MoveTo(100,100,60,MOVE_PATHFINDING|MOVE_EXCLUDE_STEEP_SLOPES);Check(explicitStrict.stopped,"explicit slope exclusion ignored");
 for(int type:std::vector<int>{PATHFIND_NORMAL|PATHFIND_FLYPATH|PATHFIND_NOT_USING_PATH,PATHFIND_NORMAL|PATHFIND_UNDERWATER}){bot.strict=true;bot.type=type;Movement::MoveSplineInit valid{bot};valid.MoveTo(1,2,3,MOVE_PATHFINDING);Check(!valid.stopped&&valid.args.path.size()==2,"native flight/swim lost");}
 bot.strict=true;Movement::MoveSplineInit direct{bot};direct.MoveTo(100,100,60,0);Check(!direct.stopped&&direct.args.path.size()==2,"explicit direct/jump caller changed");
 std::cout<<"Native resolver and point-spline handoff reject failed ground routes on all maps; partial, direct, flight and swim contracts preserved\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
