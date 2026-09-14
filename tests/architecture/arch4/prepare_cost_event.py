from pathlib import Path
import sys
import re, shutil
w=Path(__file__).parent
s=w.parents[2]
t=Path(sys.argv[1]);t.mkdir(parents=True,exist_ok=True)
d=w
for name in ['chat_queue_tests.cpp','account_membership_tests.cpp','shuffle_tests.cpp']:
 shutil.copyfile(d/name,t/name)
ai=(s/'modules/ManTechPlayerbots/playerbot/PlayerbotAI.cpp').read_text()
start=ai.index('    // Extract due replies');end=ai.index('    // logout if logout timer',start)
(t/'chat_queue_block.inc').write_text(ai[start:end])
h=(s/'src/game/AI/CreatureEventAI.h').read_text()
fragment=h[h.index('#define EVENT_UPDATE_TIME'):h.index('class CreatureEventAI :')]
mgr=(s/'src/game/AI/CreatureEventAIMgr.h').read_text()
generation=mgr[mgr.index('struct CreatureEventAIGeneration'):mgr.index('class CreatureEventAIMgr')]
prefix='''#include <cstdint>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <cassert>
#include <iostream>
#include "Memory/MemoryLedger.h"
using uint32=uint32_t;using uint16=uint16_t;using uint8=uint8_t;using int32=int32_t;
class Creature;
using ScriptMap=std::map<uint32,uint32>;using ScriptMapMap=std::map<uint32,ScriptMap>;
enum {Category_EventAI};
template<class T,int C> using turtle_vector=std::vector<T>;
template<class K,class V,int C> using turtle_unordered_map=std::unordered_map<K,V>;
'''
test='''
int main(){
 auto gen=std::make_shared<CreatureEventAIGeneration>();
 gen->scripts[1][0]=123;
 CreatureEventAI_Event e{};e.event_id=42;e.action[0]=&gen->scripts.at(1);
 gen->events[7].push_back(e);
 std::weak_ptr<CreatureEventAIGeneration> old=gen;
 {
  std::shared_ptr<CreatureEventAIGeneration const> firstPin=gen,secondPin=gen;
  std::vector<CreatureEventAIHolder> first,second;
  first.emplace_back(firstPin->events.at(7).front());second.emplace_back(secondPin->events.at(7).front());
  first.front().Time=250;first.front().Enabled=false;
  assert(second.front().Time==0&&second.front().Enabled);
  assert(&first.front().Event==&second.front().Event);
  for(int i=0;i<10000;++i)first.emplace_back(firstPin->events.at(7).front());
  assert(first.front().Time==250&&!first.front().Enabled);
  gen=std::make_shared<CreatureEventAIGeneration>();gen->scripts[1][0]=999;
  assert(!old.expired());assert(first.front().Event.action[0]->at(0)==123);
 }
 assert(old.expired());assert(ManTech::MemoryLedger::Read(ManTech::MemoryKind::EventHolders).count==0);
 std::cout<<"Actual Turtle EventAI definitions/holders: shared events and scripts survive reload, independent timers, relocation and destruction balanced\\n";
}
'''
(t/'event_lifetime_tests.cpp').write_text(prefix+fragment+generation+test)
print('Prepared actual proposed-code chat and EventAI fixtures plus donor account/shuffle tests.')
