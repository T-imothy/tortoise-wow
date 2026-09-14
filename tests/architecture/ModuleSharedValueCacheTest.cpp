
#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
using int32=std::int32_t;
struct PlayerbotAI {static std::atomic<int> live;PlayerbotAI(){++live;}~PlayerbotAI(){--live;}};
std::atomic<int> PlayerbotAI::live{0};
struct UntypedValue {virtual ~UntypedValue()=default;};
template<class T>struct Value{virtual T Get()=0;virtual void Set(T)=0;};
std::function<int()> nested;
struct TestValue:UntypedValue,Value<int>{bool ready=false;int value=0;PlayerbotAI*owner;std::string name;
 TestValue(PlayerbotAI*a,std::string n):owner(a),name(n){}
 int Get()override{if(!ready){if(PlayerbotAI::live!=1)std::abort();value=name=="nested"?nested():42;std::this_thread::yield();ready=true;}return value;}
 void Set(int n)override{value=n;ready=true;}
};
struct SharedValueContext {std::map<std::string,std::unique_ptr<TestValue>> values;};
template<class T>struct NamedObjectContextList {
 SharedValueContext*context=nullptr;void Add(SharedValueContext*p){context=p;}
 UntypedValue*GetObject(std::string const&name,PlayerbotAI*ai){auto&slot=context->values[name];if(!slot)slot.reset(new TestValue(ai,name));return slot.get();}
};
#include "ModuleSharedValueContext.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){
 {SharedObjectContext context;nested=[&]{return context.ReadValue<int>("base")+1;};
 std::vector<std::thread> workers;
 for(int i=0;i<8;++i)workers.emplace_back([&]{for(int j=0;j<1000;++j){Check(context.ReadValue<int>("nested")==43,"nested shared calculation");Check(context.ReadValue<int>("qualified",7)==42,"qualified cache publication");}});
 for(auto&worker:workers)worker.join();
 context.WriteValue<int>("base",77);Check(context.ReadValue<int>("base")==77,"manual update after initialization");
 context.WriteValue<int>("qualified",std::string("seven"),88);Check(context.ReadValue<int>("qualified",std::string("seven"))==88,"qualified write");
 Check(PlayerbotAI::live==1,"one live owner for all shared values");}
 Check(PlayerbotAI::live==0,"owner lifetime ends with cache");
 std::cout<<"Shared value concurrent publication, nested reads, writes and owner lifetime passed\n";
}
