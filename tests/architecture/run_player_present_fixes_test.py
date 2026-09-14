from pathlib import Path
import subprocess,argparse,re
p=argparse.ArgumentParser();p.add_argument('--root',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
r=a.root;m=r/'modules/ManTechPlayerbots/playerbot';out=a.output.resolve();out.mkdir(parents=True,exist_ok=True)
def body(s,needle):
 start=s.index(needle); opening=s.index('{',start);depth=1;i=opening+1
 while depth:
  if s[i]=='{':depth+=1
  if s[i]=='}':depth-=1
  i+=1
 return s[start:i]
def run(name,code,includes=()):
 (out/(name+'.cpp')).write_text(code)
 subprocess.run(['cl','/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG',*['/I'+str(x) for x in includes],name+'.cpp','/Fe:'+name+'.exe'],cwd=out,check=True)
 subprocess.run([str(out/(name+'.exe'))],cwd=out,check=True,timeout=45)
ai=(m/'PlayerbotAI.cpp').read_text();h=(m/'PlayerbotAI.h').read_text()
(out/'ModulePacketTypes.inc').write_text(body(h,'class PacketHandlingHelper')+';')
(out/'ModulePacketMethods.inc').write_text('\n'.join(body(ai,'void PacketHandlingHelper::'+n) for n in ['AddHandler','Handle','AddPacket']))
packet=(r/'tests/architecture/ModulePacketDispatchTest.cpp').read_text().replace('getOpcode()','GetOpcode()')
run('packet',packet)
# Hold the actual queue mutex to prove unregistered movement packets bypass it.
(out/'ModulePacketPublic.inc').write_text((body(h,'class PacketHandlingHelper')+';').replace('private:','public:'))
run('packet_filter',r'''
#include <atomic>
#include <cstdint>
#include <cassert>
#include <chrono>
#include <future>
#include <map>
#include <memory>
#include <mutex>
#include <stack>
#include <string>
#include <iostream>
using uint16=uint16_t;constexpr uint16 MSG_RAID_READY_CHECK=3;
struct WorldPacket{uint16 opcode;bool empty()const{return false;}uint16 GetOpcode()const{return opcode;}};
struct ExternalEventHelper{bool HandlePacket(std::map<uint16,std::string>const&,WorldPacket const&){return true;}};
#include "ModulePacketPublic.inc"
#include "ModulePacketMethods.inc"
int main(){PacketHandlingHelper p;p.AddHandler(1,"normal");
 std::unique_lock lock(p.m_botPacketMutex);
 auto f=std::async(std::launch::async,[&]{for(int i=0;i<100000;++i)p.AddPacket({99});});
 auto result=f.wait_for(std::chrono::seconds(2));lock.unlock();f.get();assert(result==std::future_status::ready);assert(p.queue.empty());
 std::cout<<"PASS 100000 unhandled packets bypass the held queue lock without allocating queued packets\n";
}
''')
mapcode=(r/'src/game/Maps/Map.cpp').read_text();predicate=body(mapcode,'bool Map::IsAutonomousActivePlayer')
native=r'''
#include <cassert>
#include <iostream>
constexpr int PACKET_PROCESS_SPELLS=0;
struct Spline{bool final=true;bool Finalized()const{return final;}};
struct Session{bool recent=false;bool HasRecentPacket(int)const{return recent;}};
struct Player {
 bool machine=true,combat=false,casting=false,bg=false,queue=false,taxi=false,teleport=false,transport=false;
 Spline* movespline=nullptr;Session* session=nullptr;
 bool IsInCombat()const{return combat;}bool IsNonMeleeSpellCasted(bool)const{return casting;}
 bool InBattleGround()const{return bg;}bool InBattleGroundQueue()const{return queue;}
 bool IsTaxiFlying()const{return taxi;}bool IsBeingTeleported()const{return teleport;}
 bool GetTransport()const{return transport;}Session* GetSession()const{return session;}
};
struct Map{bool IsMachineDrivenPlayer(Player const*p)const{return p->machine;}bool IsAutonomousActivePlayer(Player const*)const;};
'''+predicate+r'''
int main(){Map m;Player p;assert(!m.IsAutonomousActivePlayer(nullptr));assert(!m.IsAutonomousActivePlayer(&p));
 for(auto member:{&Player::combat,&Player::casting,&Player::bg,&Player::queue,&Player::taxi,&Player::teleport,&Player::transport}){
 p.*member=true;assert(m.IsAutonomousActivePlayer(&p));p.machine=false;assert(!m.IsAutonomousActivePlayer(&p));p.machine=true;p.*member=false;}
 Spline spline;p.movespline=&spline;assert(!m.IsAutonomousActivePlayer(&p));spline.final=false;assert(m.IsAutonomousActivePlayer(&p));spline.final=true;
 Session session;p.session=&session;session.recent=true;assert(m.IsAutonomousActivePlayer(&p));session.recent=false;assert(!m.IsAutonomousActivePlayer(&p));
 std::cout<<"PASS native active classification: moving, casting, combat, taxi, teleport, transport, battleground, recent spell; idle/null/human exclusion\n";
}
'''
run('native_activity',native)
mh=(r/'src/game/MapNodes/MasterPlayer.h').read_text();mc=(r/'src/game/MapNodes/MasterPlayer.cpp').read_text()
native_mail='\n'.join(body(mh,x) for x in ['    void AddMail(','    uint32 GetMailSize()','    void PublishMailSize()'])
mailtrigger=body((m/'strategy/triggers/WorldPacketTrigger.h').read_text(),'    class MailAvailableTrigger')+';\n'+body((m/'strategy/generic/WorldPacketHandlerStrategy.cpp').read_text(),'bool MailAvailableTrigger::IsActive()')
run('mail',r'''
#include <atomic>
#include <cassert>
#include <cstdint>
#include <deque>
#include <thread>
#include <iostream>
using uint32=uint32_t;
struct Mail{};
struct Player{std::deque<Mail*>m_mail;std::atomic<uint32>m_mailSize{0};bool bg=false,combat=false;
 bool InBattleGround(){return bg;}bool IsInCombat(){return combat;}
'''+native_mail+r'''
};
struct Trigger;struct Context{Trigger* often=nullptr;Trigger* GetTrigger(const char*){return often;}};
struct PlayerbotAI{Player* bot;Context* context;bool master=false;bool GetMaster(){return master;}};
struct Trigger{PlayerbotAI*ai;Player*bot;Context*context;bool triggered=false;
 Trigger(PlayerbotAI*a,const char*):ai(a),bot(a->bot),context(a->context){}
 virtual bool IsActive(){return false;}bool IsAlreadyTriggered(){return triggered;}
};
'''+mailtrigger+r'''
int main(){Player bot;Context ctx;PlayerbotAI ai{&bot,&ctx};Trigger often(&ai,"often");ctx.often=&often;MailAvailableTrigger mail(&ai);Mail letter;
 often.triggered=true;for(int i=0;i<10000;++i)assert(!mail.IsActive());
 bot.AddMail(&letter);assert(bot.GetMailSize()==1&&mail.IsActive());
 often.triggered=false;assert(!mail.IsActive());often.triggered=true;
 ai.master=true;assert(!mail.IsActive());ai.master=false;bot.bg=true;assert(!mail.IsActive());bot.bg=false;bot.combat=true;assert(!mail.IsActive());bot.combat=false;
 bot.m_mail.clear();bot.PublishMailSize();assert(!mail.IsActive());
 std::atomic<bool>done=false;std::thread reader([&]{while(!done.load())assert(bot.GetMailSize()<=1);});
 for(int i=0;i<100000;++i){bot.AddMail(&letter);bot.m_mail.clear();bot.PublishMailSize();}done=true;reader.join();assert(bot.GetMailSize()==0);
 std::cout<<"PASS actual native mail count + trigger: empty/full, existing rate result, player group/BG/combat exclusion, concurrent count reader\n";
}
''')
# Every actual native structural mutation publishes the scalar. Check both load
# and removal paths, including the allocated soft-deleted row not owned by list.
for match in re.finditer(r'm_mail\.(?:erase\(itr\)|clear\(\)|push_back\(m\));',mc):
 assert re.match(r'\s*PublishMailSize\(\);',mc[match.end():]),match.group()
assert 'delete m;\n            continue;' in mc
strategy=(m/'strategy/generic/WorldPacketHandlerStrategy.cpp').read_text()
assert strategy.index('"often"')<strategy.index('"mail available"')
assert 'often->Check()' not in mailtrigger
run('outcomes',r'''
#include "CombatOutcomeCounters.h"
#include <cassert>
#include <iostream>
int main(){ai::diagnostics::OutcomeCounters c,empty;
 for(unsigned i=0;i<100000;++i)c.Add(i%12,"spell_check",i%256);
 c.Add(99,"new_stage",-1);c.Add(99,"new_stage",999);uint64_t n=0;
 c.Each([&](size_t cls,std::string_view stage,int result,uint64_t count){n+=count;if(stage=="other"){assert(cls==0&&result==-1&&count==2);}});assert(n==100002);
 c.values.swap(empty.values);n=0;c.Each([&](auto...){++n;});assert(n==0);
 for(int i=0;i<6;++i)c.Add(1,"travel_result",i);n=0;c.Each([&](size_t,std::string_view s,int v,uint64_t count){assert(s=="travel_result"&&v>=0&&v<6&&count==1);++n;});assert(n==6);
 std::cout<<"PASS fixed outcome accounting: 100002 selected records, bounds/unknown normalization, window swap/reset, all six travel outcomes\n";
}
''',[m])
travel=body((m/'strategy/actions/ChooseTravelTargetAction.cpp').read_text(),'bool ChooseTravelTargetAction::Execute')
for reason in range(6):assert f'return observed({reason},' in travel
combat=(m/'CombatDiagnostics.cpp').read_text()
assert combat.index('outcomeCounters.Add')<combat.index('buckets.find')
assert 'progress.size() < 128' in combat and 'guid % 256 != 0' in combat
scope=body((m/'CombatDiagnostics.h').read_text(),'    class CombatSpellNameContext')+';'
definitions='\n'.join(body(combat,n) for n in ['CombatSpellNameContext::CombatSpellNameContext','CombatSpellNameContext::~CombatSpellNameContext','std::string CombatSpellNameContext::Current'])
run('spell_context',r'''
#include <cassert>
#include <string>
#include <thread>
#include <iostream>
struct Config{bool combatDiagnosticsEnabled=true;}sPlayerbotAIConfig;
thread_local const std::string* currentSpellName=nullptr;
'''+scope+definitions+r'''
int main(){std::string a="healing wave",b="unknown rank";assert(CombatSpellNameContext::Current().empty());
 {CombatSpellNameContext one(a);assert(CombatSpellNameContext::Current()==a);
  try{CombatSpellNameContext two(b);assert(CombatSpellNameContext::Current()==b);throw 1;}catch(int){}assert(CombatSpellNameContext::Current()==a);
  std::thread other([&]{assert(CombatSpellNameContext::Current().empty());CombatSpellNameContext two(b);assert(CombatSpellNameContext::Current()==b);});other.join();assert(CombatSpellNameContext::Current()==a);
 }assert(CombatSpellNameContext::Current().empty());sPlayerbotAIConfig.combatDiagnosticsEnabled=false;{CombatSpellNameContext off(a);assert(CombatSpellNameContext::Current().empty());}
 std::cout<<"PASS requested spell context: nested lookup, exception unwinding, independent threads, disabled mode\n";
}
''')
print('PASS source contracts: native mail mutations/leak release, trigger ordering, outcome capture before detail cap, six travel branches, bounded progress cohort')
