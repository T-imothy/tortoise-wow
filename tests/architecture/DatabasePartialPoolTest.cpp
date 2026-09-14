#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
using uint32=std::uint32_t;
int stopped=0,joined=0,drained=0;bool allStopped=true;
struct Worker{bool running=true;int tail=0;void Stop(){running=false;++stopped;}size_t DrainRequests(){if(running)std::abort();if(tail){--tail;++drained;return 1;}return 0;}};
struct Thread{bool active=true;bool joinable(){return active;}void join(){if(!active)std::abort();active=false;++joined;}};
struct Database{std::vector<std::shared_ptr<Worker>>m_threadsBodies;std::vector<Thread>m_delayThreads;uint32 m_numAsyncWorkers=0;void HaltDelayThread();};
#include "DatabasePartialPool.inc"
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){Database db;db.m_numAsyncWorkers=16;for(int i=0;i<2;++i){auto w=std::make_shared<Worker>();w->tail=3;db.m_threadsBodies.push_back(w);db.m_delayThreads.push_back({});}db.HaltDelayThread();Check(stopped==2&&joined==2&&drained==6,"partial pool stops existing workers and drains their tails");Check(db.m_threadsBodies.empty()&&db.m_delayThreads.empty()&&db.m_numAsyncWorkers==0,"partial pool fully reset");db.HaltDelayThread();Check(stopped==2&&joined==2,"repeated cleanup is idempotent");db.m_numAsyncWorkers=4;db.HaltDelayThread();Check(db.m_numAsyncWorkers==0,"zero workers initialized");db.m_threadsBodies.push_back(std::make_shared<Worker>());db.m_delayThreads.push_back({false});db.HaltDelayThread();Check(stopped==3&&joined==2,"non-joinable thread cleanup");std::cout<<"Partial database pool cleanup and repeat shutdown passed\n";}
