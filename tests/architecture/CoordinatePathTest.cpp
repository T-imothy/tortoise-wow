#include "DetourNavMesh.h"
#include "DetourNavMeshBuilder.h"
#include "DetourNavMeshQuery.h"
#include "DetourCommon.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>
#include <tuple>
#include <vector>
using uint32=uint32_t;using uint16=uint16_t;using uint8=uint8_t;using int32=int32_t;
static void Check(bool v){if(!v)throw std::runtime_error("native coordinate path assertion failed");}
#define ASSERT(x) Check(bool(x))
#define MANGOS_ASSERT(x) ASSERT(x)
#define DEBUG_LOG(...) ((void)0)
#define SMOOTH_PATH_SLOP 0.4f
#define SMOOTH_PATH_STEP_SIZE 2.0f
struct Vector3{float x=0,y=0,z=0;Vector3()=default;Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3 operator-(Vector3 p)const{return {x-p.x,y-p.y,z-p.z};}float squaredLength()const{return x*x+y*y+z*z;}};
using PointsArray=std::vector<Vector3>;
enum{NAV_GROUND=1,NAV_WATER=2,NAV_MAGMA=4,NAV_SLIME=8,NAV_STEEP_SLOPES=16,UNIT_STAT_IGNORE_PATHFINDING=1,TYPEID_UNIT=3,TYPEID_PLAYER=4,MAP_ALL_LIQUIDS=0xff,LIQUID_MAP_NO_WATER=0};
struct GridMapLiquidData{float level=0;};
struct Terrain{bool IsSwimmable(float,float,float)const{return false;}uint32 getLiquidStatus(float,float,float,uint32,GridMapLiquidData*)const{return LIQUID_MAP_NO_WATER;}};
struct Map{bool FindCollisionModel(float,float,float,float,float,float)const{return false;}};
struct Transport{void CalculatePassengerOffset(float&,float&,float&){}uint32 GetDisplayId()const{return 1;}};
struct Unit{bool IsPlayer()const{return true;}uint32 mapId=821;Terrain terrain;Map map;bool CanSwim()const{return false;}bool CanFly()const{return false;}bool CanWalk()const{return true;}bool HasUnitState(uint32)const{return false;}uint32 GetTypeId()const{return TYPEID_PLAYER;}uint32 GetGUIDLow()const{return 7;}uint32 GetMapId()const{return mapId;}float GetObjectBoundingRadius()const{return 0.5f;}Terrain const* GetTerrain()const{return &terrain;}Map const* GetMap()const{return &map;}char const* GetName()const{return "fixture";}void GetZoneAndAreaId(uint32& z,uint32& a)const{z=a=0;}void UpdateGroundPositionZ(float&,float&,float&)const{}void GetSafePosition(float& x,float& y,float& z,Transport*)const{x=2;y=2;z=0;}};
struct Creature:Unit{};
struct Config{bool GetBoolDefault(char const*,bool v)const{return v;}}sConfig;
struct Log{template<class...A>void outError(char const*,A...)const{}}sLog;
namespace TurtleDiagnostics{enum{Path};struct Scope{Scope(int){}};}
namespace MMAP{
struct MMapManager{std::map<uint32,dtNavMeshQuery const*> maps;uint32 selected=0;dtNavMeshQuery const* GetNavMeshQuery(uint32 id){selected=id;auto i=maps.find(id);return i==maps.end()?nullptr:i->second;}dtNavMeshQuery const* GetModelNavMeshQuery(uint32){return nullptr;}};
namespace MMapFactory{MMapManager* createOrGetMMapManager(){static MMapManager m;return &m;}}
}
using restricted_movement_t=std::tuple<uint32,uint32,uint32>;
std::array<restricted_movement_t,0> NoMovementAreas;
#include "CoordinatePathClass.inc"
#include "CoordinatePathImplementation.inc"
#include "CoordinatePathMath.inc"
#include "CoordinatePathFlatTile.inc"
int main(){try{
 dtNavMesh mesh;dtNavMeshParams params{};params.tileWidth=params.tileHeight=10;params.maxTiles=8;params.maxPolys=8;
 Check(dtStatusSucceed(mesh.init(&params)));auto tile=AddFlatTile(mesh,0);AddFlatTile(mesh,3);
 dtNavMeshQuery query;Check(dtStatusSucceed(query.init(&mesh,2048)));
 auto* manager=MMAP::MMapFactory::createOrGetMMapManager();manager->maps[821]=&query;
 Vector3 start(2,2,0),end(8,8,0);
 for(bool straight:{false,true}){
  PathInfo path(821,104);path.setUseStrightPath(straight);Check(path.calculate(start,end));
  Check(manager->selected==821);Check(path.getPathType()==PATHFIND_NORMAL);Check(path.getPath().size()>=2);
  Check(path.ExcludesSteepSlopes());Check(std::fabs(path.getPath().back().x-end.x)<1);
  path.ResetForNewRequest();Check(path.ExcludesSteepSlopes());Check(path.calculate(start,end));
  Check(!path.calculate(8,8,0));Check(path.getPathType()==PATHFIND_NOPATH&&path.getPath().empty());
 }
 PathInfo missing(999,0);Check(!missing.calculate(start,end,true));Check(missing.getPathType()==PATHFIND_NOPATH&&missing.getPath().empty());
 PathInfo noContext(static_cast<Unit const*>(nullptr));Check(!noContext.calculate(start,end));
 PathInfo malformed(821,0);Vector3 invalid=start;invalid.x=std::numeric_limits<float>::quiet_NaN();Check(!malformed.calculate(invalid,end));Check(malformed.getPath().empty());
 PathInfo gap(821,0);gap.calculate(start,Vector3(5,35,0),true);Check(!(gap.getPathType()&PATHFIND_DEST_FORCED));Check(gap.getPathType()&PATHFIND_INCOMPLETE);Check(!gap.getPath().empty()&&gap.getPath().back().y<11);
 Check(dtStatusSucceed(mesh.setPolyFlags(tile,NAV_GROUND|NAV_STEEP_SLOPES)));
 PathInfo steep(821,0);steep.calculate(start,end,true);Check(steep.getPathType()==PATHFIND_NOPATH);Check(!(steep.getPathType()&PATHFIND_DEST_FORCED));
 Check(dtStatusSucceed(mesh.setPolyFlags(tile,NAV_GROUND)));
 Unit player;PathInfo live(&player);Check(live.calculate(8,8,0));Check(live.getPathType()==PATHFIND_NORMAL);
 std::cout<<"Native ownerless and unit pathfinding pass real Detour tile, missing-map, steep-slope, partial-route and invalid-coordinate checks\n";
 }catch(std::exception const& e){std::cerr<<e.what()<<'\n';return 1;}}
