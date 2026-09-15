#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
using uint32=uint32_t;
struct Vector3 {
 float x=0,y=0,z=0;
 Vector3 operator-(Vector3 b)const{return{x-b.x,y-b.y,z-b.z};}
 Vector3 operator+(Vector3 b)const{return{x+b.x,y+b.y,z+b.z};}
 Vector3 operator*(float b)const{return{x*b,y*b,z*b};}
 Vector3 operator/(float b)const{return{x/b,y/b,z/b};}
 Vector3& operator+=(Vector3 b){*this=*this+b;return *this;}
 Vector3& operator-=(Vector3 b){*this=*this-b;return *this;}
 float squaredLength()const{return x*x+y*y+z*z;}
};
struct Map {
 unsigned calls=0,hitAt=0;
 bool GetDynamicObjectHitPos(Vector3,Vector3 end,Vector3& out,float distance){++calls;if(distance!=-0.1f)throw 1;out=end;out.x-=0.1f;return calls==hitAt;}
};
struct Unit {
 Map* map=nullptr;Vector3 p;bool los=true;
 Map* FindMap()const{return map;}Map* GetMap()const{return map;}
 float GetPositionX()const{return p.x;}float GetPositionY()const{return p.y;}float GetPositionZ()const{return p.z;}
 void GetPosition(float&x,float&y,float&z){x=p.x;y=p.y;z=p.z;}
 float GetDistance(float x,float y,float z){return std::sqrt((p-Vector3{x,y,z}).squaredLength());}
 bool IsWithinDist3d(float x,float y,float z,float r){return GetDistance(x,y,z)<r;}
 bool IsWithinLOS(float,float,float){return los;}
};
enum PathType{PATHFIND_NOPATH=1,PATHFIND_SHORTCUT=2,PATHFIND_NORMAL=4,PATHFIND_CASTER=8};
struct PathInfo {
 // This geometry fixture does not exercise memory accounting.
 struct MemoryRefresh { PathInfo& owner; };
 Unit const* m_sourceUnit;std::vector<Vector3>m_pathPoints;PathType m_type=PATHFIND_NOPATH;
 bool UpdateForCaster(Unit*,float);bool UpdateForMelee(Unit*,float);void CutPathWithDynamicLoS();
 void clear(){m_pathPoints.clear();}Vector3 getStartPosition(){return m_sourceUnit->p;}
};
#include "NativePathPostProcessing.inc"
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Map map;Unit owner{&map,{0,0,0}},target{&map,{20,0,0}};PathInfo path{&owner};
 // Exact failed-path shape from the population crash, and the sibling consumers.
 path.CutPathWithDynamicLoS();CHECK(map.calls==0&&path.m_pathPoints.empty()&&path.m_type==PATHFIND_NOPATH);
 CHECK(!path.UpdateForCaster(&target,5));CHECK(!path.UpdateForMelee(&target,5));CHECK(path.m_pathPoints.empty());
 path.m_pathPoints={{0,0,0}};path.CutPathWithDynamicLoS();CHECK(map.calls==0&&path.m_pathPoints.size()==1);
 CHECK(!path.UpdateForCaster(&target,5));CHECK(!path.UpdateForMelee(&target,5));
 // Valid collision paths retain first-hit clipping and complete unobstructed paths.
 path.m_pathPoints={{0,0,0},{10,0,0},{20,0,0}};path.m_type=PATHFIND_NORMAL;
 map.hitAt=1;path.CutPathWithDynamicLoS();CHECK(map.calls==1&&path.m_pathPoints.size()==2&&path.m_pathPoints[1].x==9.9f&&path.m_type==PATHFIND_NORMAL);
 map.calls=0;map.hitAt=0;path.m_pathPoints={{0,0,0},{10,0,0},{20,0,0}};path.CutPathWithDynamicLoS();CHECK(map.calls==2&&path.m_pathPoints.size()==3);
 // Ownerless coordinate queries cannot query a dynamic map or invent a path.
 path.m_sourceUnit=nullptr;path.CutPathWithDynamicLoS();CHECK(map.calls==2&&path.m_pathPoints.size()==3);
 path.m_sourceUnit=&owner;owner.map=nullptr;path.CutPathWithDynamicLoS();CHECK(map.calls==2);owner.map=&map;
 // Native already-in-range semantics still construct the required stationary pair.
 path.m_pathPoints.clear();target.p={1,0,0};CHECK(path.UpdateForCaster(&target,5));CHECK(path.m_pathPoints.size()==2);
 path.m_pathPoints.clear();CHECK(path.UpdateForMelee(&target,5));CHECK(path.m_pathPoints.size()==2);
 std::cout<<"Native empty/single path, collision clipping, ownerless query and in-range postprocessing passed\n";
}
