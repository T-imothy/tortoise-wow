#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
#include "MapWork.h"
using uint32=uint32_t;using int32=int32_t;
enum{MOVEFLAG_NONE=0,MOVEFLAG_JUMPING=1,MOVEFLAG_FALLINGFAR=2,MSG_MOVE_STOP=3,MSG_MOVE_FALL_LAND=4,IN_MILLISECONDS=1000};
uint32 now=1000;struct WorldTimer{static uint32 getMSTime(){return now;}};
struct MovementInfo{struct JumpInfo{}jump;struct{float x=0,y=0,z=0;}pos;int flags=0;void AddMovementFlag(int f){flags|=f;}void SetMovementFlags(int f){flags=f;}};
struct WorldPosition{uint32 map=0;float x=0,y=0,z=0;bool valid=false;WorldPosition()=default;WorldPosition(uint32 m,float a,float b,float c):map(m),x(a),y(b),z(c),valid(true){}operator bool()const{return valid;}uint32 GetMapId()const{return map;}float getX()const{return x;}float getY()const{return y;}float getZ()const{return z;}};
struct Player{uint32 map=1,instance=2;uint64_t generation=3;bool inWorld=true,teleport=false;unsigned relocations=0,stops=0,fallClears=0;MovementInfo m_movementInfo;
 uint32 GetMapId(){return map;}uint32 GetInstanceId(){return instance;}uint64_t GetMapWorkGeneration(){return generation;}bool IsInWorld(){return inWorld;}bool IsBeingTeleported(){return teleport;}
 void Relocate(float x,float y,float z){++relocations;m_movementInfo.pos={x,y,z};}void StopMoving(){++stops;}void SetFallInformation(float){++fallClears;}void UpdateAllowedPositionZ(float,float,float&z){z=0;}char const*GetName(){return "fixture";}
};
struct WorldPacket{int opcode;explicit WorldPacket(int o):opcode(o){}WorldPacket& operator<<(MovementInfo const&){return *this;}};
struct Log{template<class...T>void outDetail(T...){} }sLog;
struct PlayerbotAI{Player*bot;WorldPosition jumpDestination;MapWorkStamp jumpStamp{};uint32 jumpTime=0;bool fallAfterJump=false;std::vector<int>packets;
 void SetJumpDestination(WorldPosition const&);void UpdateJumpMovement();WorldPosition GetJumpDestination(){return jumpDestination;}void ResetJumpDestination(){jumpDestination={};}void QueuePacket(WorldPacket const&p){packets.push_back(p.opcode);}
#include "ModuleJumpDeadline.inc"
};
#include "ModuleJumpLifetime.inc"
int main(){bool fail=false;
 for(unsigned variant=0;variant<6;++variant){Player p;PlayerbotAI ai{&p};ai.SetJumpDestination({1,10,20,5});ai.SetJumpTime(2000);ai.fallAfterJump=true;
  if(variant==0)++p.map;if(variant==1)++p.instance;if(variant==2)++p.generation;if(variant==3)p.inWorld=false;if(variant==4)p.teleport=true;if(variant==5)ai.SetJumpDestination({9,10,20,5});
  now=3000;ai.UpdateJumpMovement();if(ai.jumpTime||ai.fallAfterJump||ai.jumpDestination||p.relocations||p.stops||p.fallClears||!ai.packets.empty())fail=true;
 }
 Player p;PlayerbotAI ai{&p};ai.SetJumpDestination({1,10,20,5});ai.SetJumpTime(5);now=0xfffffff0;ai.UpdateJumpMovement();if(p.relocations||ai.jumpTime!=5)fail=true;
 now=5;ai.UpdateJumpMovement();if(p.relocations!=1||p.stops!=1||p.fallClears!=1||ai.jumpTime||ai.packets!=std::vector<int>{MSG_MOVE_STOP,MSG_MOVE_FALL_LAND})fail=true;
 ai.UpdateJumpMovement();if(p.relocations!=1)fail=true;
 ai.SetJumpDestination({1,10,20,5});ai.SetJumpTime(0xfffffff0);now=4;ai.UpdateJumpMovement();if(p.relocations!=2||ai.jumpTime)fail=true;
 ai.SetJumpTime(0);if(ai.jumpTime==0)fail=true;
 ai.SetJumpDestination({1,10,20,5});ai.SetJumpTime(20);ai.fallAfterJump=true;now=20;ai.UpdateJumpMovement();
 if(ai.jumpTime<=now||ai.fallAfterJump||p.fallClears!=2||ai.jumpDestination.getZ()!=0)fail=true;
 now=ai.jumpTime;ai.UpdateJumpMovement();if(ai.jumpTime||p.fallClears!=3||p.m_movementInfo.pos.z!=0)fail=true;
 if(fail){std::cerr<<"Native jump lifetime, timer wrap, packet order or fall continuation failed\n";return 1;}
 std::cout<<"Native jump rejects stale owners, handles deadline wrap and completes one ordered landing or staged fall\n";
}
