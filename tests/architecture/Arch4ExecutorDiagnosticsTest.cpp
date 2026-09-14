#include "MapTaskExecutor.h"
#include "Util/DevDiagnosticsService.h"
#include <cassert>
#include <memory>
#include <iostream>
using namespace ManTech::Diag;
int main(){
 std::atomic<unsigned> count{0};
 {
  MapContext context(1,9);
  MapTaskExecutor pool(2);
  MapTaskJoin group;
  for(unsigned i=0;i<60;++i)group.tasks.push_back(pool.Submit([&,value=std::make_unique<int>(1)]{
   assert(Context==((1ULL<<32)|9));count+=*value;
  },"executor_fixture"));
  group.tasks.push_back(pool.Submit([]{throw std::runtime_error("expected");},"executor_throw"));
  bool thrown=false;try{group.Get();}catch(std::runtime_error const&){thrown=true;}
  assert(thrown&&count==60);
 }
 assert(Context==0);
 {MapTaskExecutor inlinePool(0);inlinePool.Submit([&]{++count;},"inline_fixture").get();}
 // Full queue uses its existing inline fallback; destruction still drains jobs.
 {
  MapTaskExecutor pool(1);std::promise<void> release,entered;auto gate=release.get_future().share();
  auto busy=pool.Submit([&]{entered.set_value();gate.wait();},"blocked_fixture");entered.get_future().wait();
  std::vector<std::future<void>> pending;
  for(unsigned i=0;i<257;++i)pending.push_back(pool.Submit([&]{++count;},"full_queue_fixture"));
  assert(count==62);release.set_value();busy.get();
 }
 assert(count==318);
 auto snapshot=Snapshot();assert(snapshot.find("executor_fixture")!=std::string::npos);
 std::cout<<"PASS native executor move-only tasks, exception join, context propagation, inline fallback and draining\n";
}
