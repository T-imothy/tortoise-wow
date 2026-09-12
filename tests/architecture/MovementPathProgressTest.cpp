#include <vector>
#include <memory>
#include <thread>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <iostream>
using uint8=unsigned char;using uint32=unsigned;constexpr unsigned NAV_AREA_WATER=8;
struct Unit {unsigned GetMapId()const{return 1;}unsigned GetInstanceId()const{return 1;}};
struct PathFinder {PathFinder(Unit const*){}PathFinder(unsigned,unsigned){}void setAreaCost(unsigned,float){}};
struct TravelMap {bool gethasToGen(){return false;}}sTravelNodeMap;
struct Config {float targetPosRecalcDistance=.01f;}sPlayerbotAIConfig;
struct WorldPosition;
std::vector<std::vector<WorldPosition>> responses;
struct WorldPosition {
 unsigned map=1;float x=0;WorldPosition(float px=0):x(px){}
 unsigned GetMapId()const{return map;}unsigned getMapId()const{return map;}
 float distance(WorldPosition const& p)const{return std::fabs(x-p.x);}
 bool isPathTo(std::vector<WorldPosition> const& p)const{return !p.empty()&&distance(p.back())<.01f;}
 std::vector<WorldPosition> getPathStepFrom(WorldPosition const&,std::unique_ptr<PathFinder>&,Unit const*)const{if(responses.empty())return {};auto p=responses.front();responses.erase(responses.begin());return p;}
 std::vector<WorldPosition> getPathFromPath(std::vector<WorldPosition> const&,Unit const*,uint8)const;
};
#include "MovementPathProgressNative.inc"
void Check(bool b){if(!b)throw std::runtime_error("native path progress regression");}
int main(){Unit bot;WorldPosition goal(10);
 Check(goal.getPathFromPath({},&bot,5).empty());
 responses={{WorldPosition(0)}};Check(goal.getPathFromPath({WorldPosition(0)},&bot,5).empty());
 responses={};Check(goal.getPathFromPath({WorldPosition(0)},&bot,5).empty());
 responses={};auto p=goal.getPathFromPath({WorldPosition(0),WorldPosition(3)},&bot,5);Check(p.size()==2&&p.back().x==3);
 responses={{WorldPosition(0),WorldPosition(3)},{WorldPosition(3),WorldPosition(10)}};p=goal.getPathFromPath({WorldPosition(0)},&bot,5);Check(p.size()==3&&p[1].x==3&&p.back().x==10);
 WorldPosition other(0);other.map=2;Check(goal.getPathFromPath({other},&bot,5).empty());
 std::cout<<"Native path assembly rejects empty/no-progress requests and preserves useful partial prefixes\n";
}
