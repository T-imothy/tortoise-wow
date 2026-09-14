#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
using uint32=unsigned;
struct Player{};
namespace ai { template<class T>class Value; class AiObjectContext; struct Event{}; }
struct PlayerbotAI{Player bot;ai::AiObjectContext*context=nullptr;ai::AiObjectContext*GetAiObjectContext(){return context;}};
namespace ai {
struct Qualified { virtual ~Qualified()=default; std::string qualifier; std::string getQualifier(){return qualifier;} };
struct UntypedValue {
 Player*bot;std::string name;
 UntypedValue(PlayerbotAI*ai,std::string n):bot(&ai->bot),name(std::move(n)){}
 virtual ~UntypedValue()=default;
 virtual bool Protected(){return false;}virtual uint32 LastChangeDelay(){return 0;}
 virtual void Reset(){}virtual bool Expired(){return false;}virtual bool Expired(uint32){return false;}
 std::string getName(){return name;}
};
#include "ModuleCalculatedValueBase.inc"
#include "ModuleMemoryCalculatedBase.inc"
class AiObjectContext {
public:
 std::map<std::string,Value<int>*>values;
 template<class T>Value<T>*GetValue(std::string const&name){auto i=values.find(name);return i==values.end()?nullptr:dynamic_cast<Value<T>*>(i->second);}
};
}
namespace TortoiseBots {
struct BotWorldActions {
 inline static bool map=false;
 bool accept=true;
 std::deque<std::function<void(PlayerbotAI&)>>pending;
 static bool IsMapExecution(){return map;}
 static BotWorldActions&Instance(){static BotWorldActions x;return x;}
 bool EnqueueContinuation(Player*,std::string const&,ai::Event const&,std::function<void(PlayerbotAI&)>callback){if(!accept)return false;pending.push_back(std::move(callback));return true;}
 void Drain(PlayerbotAI&ai){struct Restore{bool before;~Restore(){map=before;}}restore{map};map=false;auto batch=std::move(pending);pending.clear();for(auto&f:batch)f(ai);}
};
}
#include "ModuleWorldValue.inc"
struct Fact:ai::WorldCalculatedValue<int> {
 int calls=0,result=7;std::function<int()>nested;
 Fact(PlayerbotAI*ai,std::string name="fact",int interval=60):WorldCalculatedValue(ai,std::move(name),interval){}
 int Calculate()override{if(TortoiseBots::BotWorldActions::map)throw std::runtime_error("foreign world calculation");++calls;return nested?nested():result;}
 void Expire(){lastCheckTime=1;}
};
struct MemoryFact:ai::WorldCalculatedValue<int,ai::MemoryCalculatedValue<int>> {
 int calls=0,result=7;
 MemoryFact(PlayerbotAI*ai):WorldCalculatedValue(ai,"memory",4){}
 int Calculate()override{if(TortoiseBots::BotWorldActions::map)throw std::runtime_error("foreign memory calculation");++calls;return result;}
 bool EqualToLast(int current)override{return current==lastValue;}
 void Expire(){lastCheckTime=1;lastChangeTime=1;}
};
struct QualifiedFact:Fact,ai::Qualified { using Fact::Fact; };
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){
 PlayerbotAI ai;ai::AiObjectContext context;ai.context=&context;Fact fact(&ai);context.values["fact"]=&fact;
 auto&queue=TortoiseBots::BotWorldActions::Instance();
 CHECK(fact.Get()==7&&fact.calls==1);CHECK(fact.Get()==7&&fact.calls==1);
 TortoiseBots::BotWorldActions::map=true;fact.Expire();fact.result=9;
 CHECK(fact.Get()==7&&fact.Get()==7&&fact.calls==1&&queue.pending.size()==1);
 queue.Drain(ai);CHECK(fact.Get()==9&&fact.calls==2&&queue.pending.empty());
 Fact empty(&ai,"empty");context.values["empty"]=&empty;CHECK(empty.Get()==0&&empty.calls==0);queue.Drain(ai);CHECK(empty.Get()==7&&empty.calls==1);
 fact.Expire();queue.accept=false;CHECK(fact.Get()==9&&queue.pending.empty());queue.accept=true;fact.Get();CHECK(queue.pending.size()==1);
 queue.pending.clear();fact.Get();CHECK(queue.pending.size()==1);queue.Drain(ai);CHECK(fact.calls==3);
 fact.Expire();fact.Get();fact.Reset();queue.Drain(ai);CHECK(fact.calls==3);
 fact.Get();queue.Drain(ai);CHECK(fact.calls==4);
 auto old=std::make_unique<Fact>(&ai,"replace");context.values["replace"]=old.get();old->Get();old.reset();
 Fact replacement(&ai,"replace");context.values["replace"]=&replacement;queue.Drain(ai);CHECK(replacement.calls==0);
 replacement.Get();queue.Drain(ai);CHECK(replacement.calls==1);
 Fact dependency(&ai,"dependency"),outer(&ai,"outer");context.values["dependency"]=&dependency;context.values["outer"]=&outer;
 outer.nested=[&]{return dependency.Get()+1;};CHECK(outer.Get()==0&&queue.pending.size()==1);queue.Drain(ai);
 CHECK(outer.Get()==8&&outer.calls==1&&dependency.calls==1&&queue.pending.empty());
 CHECK(fact.LazyGet()==9&&queue.pending.empty());fact.Reset();CHECK(fact.LazyGet()==9&&queue.pending.size()==1);queue.Drain(ai);
 QualifiedFact first(&ai,"qualified"),second(&ai,"qualified");first.qualifier="first";second.qualifier="second";first.result=11;second.result=22;
 context.values["qualified::first"]=&first;context.values["qualified::second"]=&second;
 CHECK(first.Get()==0&&second.Get()==0&&queue.pending.size()==2);queue.Drain(ai);
 CHECK(first.Get()==11&&second.Get()==22&&first.calls==1&&second.calls==1);
 MemoryFact memory(&ai);context.values["memory"]=&memory;CHECK(memory.Get()==0);queue.Drain(ai);CHECK(memory.Get()==7&&memory.GetLastValue()==7&&memory.calls==1);
 memory.result=9;memory.Expire();CHECK(memory.Get()==7&&memory.GetLastValue()==7);queue.Drain(ai);CHECK(memory.Get()==9&&memory.GetLastValue()==9&&memory.calls==2);
 TortoiseBots::BotWorldActions::map=false;
 std::cout<<"World value cache checks passed: owner execution, last-completed facts, nested dependencies, coalescing, rejection, discard, reset and replacement\n";
}
