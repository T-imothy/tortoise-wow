#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
using uint32=std::uint32_t; using int32=std::int32_t;
#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x << '\n'; std::exit(1); } } while (0)
uint32 clockNow=0; struct WorldTimer { static uint32 getMSTime(){return clockNow;} };
struct Position { uint32 map=0; float x=10,y=20,z=30;
    uint32 getMapId()const{return map;} float getX()const{return x;} float getY()const{return y;} float getZ()const{return z;} };
struct Bot { uint32 instance=1; uint32 GetInstanceId(){return instance;} } botObject;
struct AI { uint64_t generation=1; uint64_t GetTransitionGeneration(){return generation;} } aiObject;
struct LastMovement
{
    uint32 failedPathMap=0,failedPathInstance=1,failedPathRetryUntil=3000;
    int32 failedPathCellX=1,failedPathCellY=2,failedPathCellZ=3;
    uint64_t failedPathGeneration=1;
#include "ModuleClearPathFailure.inc"
};
bool Eligible(Position const& endPos, LastMovement& lastMove)
{
    Bot* bot=&botObject; AI* ai=&aiObject;
#include "ModulePathFailureGate.inc"
    return true;
}
int main()
{
    Position goal; LastMovement failure;
    CHECK(!Eligible(goal,failure)); clockNow=2999; CHECK(!Eligible(goal,failure));
    clockNow=3000; CHECK(Eligible(goal,failure));
    clockNow=0; failure=LastMovement{}; goal.x=16; CHECK(Eligible(goal,failure)); CHECK(failure.failedPathMap==UINT32_MAX);
    goal=Position{}; failure=LastMovement{}; goal.map=1; CHECK(Eligible(goal,failure));
    goal=Position{}; failure=LastMovement{}; botObject.instance=2; CHECK(Eligible(goal,failure)); botObject.instance=1;
    failure=LastMovement{}; aiObject.generation=0x100000001ULL; CHECK(Eligible(goal,failure)); aiObject.generation=1;
    failure=LastMovement{}; clockNow=UINT32_MAX-100; failure.failedPathRetryUntil=100;
    CHECK(!Eligible(goal,failure)); clockNow=99; CHECK(!Eligible(goal,failure)); clockNow=100; CHECK(Eligible(goal,failure));
    failure.clearPathFailure(); CHECK(Eligible(goal,failure));
    std::cout<<"Module path retry delay, wraparound, destination, instance and 64-bit transition invalidation passed\n";
}
