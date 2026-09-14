from pathlib import Path
import argparse, subprocess
r=Path(__file__).resolve().parents[2]
p=argparse.ArgumentParser(); p.add_argument('--output',type=Path,required=True); a=p.parse_args()
out=a.output.resolve();out.mkdir(parents=True,exist_ok=True)
prefix=r'''
#include <map>
#include <set>
#include <memory>
#include <vector>
#include <functional>
#include <cassert>
#include <iostream>
#define MANTECH_DIAG_SCOPE(...)
using ObjectGuid=int;
struct WorldPacket {int opcode=1,payload=99;};
std::vector<int> delivered,checks,lookups;
int wrappers=0;
std::function<void(int)> onSend;
struct Social {int id=0;std::set<int> ignored;bool HasIgnore(int guid){checks.push_back(id);return ignored.count(guid);}};
struct Session {int id=0;void SendPacket(WorldPacket* p){assert(p->payload==99);delivered.push_back(id);if(onSend)onSend(id);}};
struct Player {Social social;Session session;Social* GetSocial(){return &social;}Session* GetSession(){return &session;}};
struct MasterPlayer:Player {};
struct Accessor {
 std::map<int,Player> players;std::map<int,MasterPlayer> masters;
 Player* FindPlayerNotInWorld(int id){lookups.push_back(id);auto i=players.find(id);return i==players.end()?nullptr:&i->second;}
 MasterPlayer* FindMasterPlayer(int id){lookups.push_back(-id);auto i=masters.find(id);return i==masters.end()?nullptr:&i->second;}
} sObjectAccessor;
struct Abstract {virtual ~Abstract()=default;virtual Social* GetSocial()=0;virtual Session* GetSession()=0;};
template<class T>struct Wrapper:Abstract {T& p;explicit Wrapper(T* v):p(*v){++wrappers;}Social* GetSocial()override{return p.GetSocial();}Session* GetSession()override{return p.GetSession();}};
using PlayerPointer=std::shared_ptr<Abstract>;
struct Base {
 bool m_area_dependant=true;std::map<int,int> m_players;
 PlayerPointer GetPlayer(int id){if(m_area_dependant){auto* p=sObjectAccessor.FindPlayerNotInWorld(id);return PlayerPointer(p?new Wrapper<Player>(p):nullptr);}auto* p=sObjectAccessor.FindMasterPlayer(id);return PlayerPointer(p?new Wrapper<MasterPlayer>(p):nullptr);}
};
struct Before:Base {void SendToAll(WorldPacket*,ObjectGuid);};
struct After:Base {void SendToAll(WorldPacket*,ObjectGuid);};
'''
test=r'''
struct Result {std::vector<int> sent,social,looked;int allocated;};
template<class C>Result run(bool area,int sender,int count,bool depart,bool ignore,int repeats){
 sObjectAccessor.players.clear();sObjectAccessor.masters.clear();delivered.clear();checks.clear();lookups.clear();wrappers=0;onSend={};
 C c;c.m_area_dependant=area;
 for(int i=1;i<=count;++i){c.m_players[i]=0;auto& p=sObjectAccessor.players[i];p.social.id=i;p.session.id=i;auto& m=sObjectAccessor.masters[i];m.social.id=i+100000;m.session.id=i+100000;if(ignore&&i%2==0){p.social.ignored.insert(sender);m.social.ignored.insert(sender);}}
 c.m_players[count+1]=0; // A stale membership must not deliver or crash.
 if(depart)onSend=[=](int id){if(id==(area?1:100001)){sObjectAccessor.players.erase(3);sObjectAccessor.masters.erase(3);}};
 WorldPacket packet;
 for(int i=0;i<repeats;++i){packet.opcode=i;c.SendToAll(&packet,sender);assert(packet.payload==99);}
 return {delivered,checks,lookups,wrappers};
}
int main(){
 int cases=0;
 for(bool area:{false,true})for(int sender:{0,7})for(bool depart:{false,true})for(bool ignore:{false,true})for(int repeats:{1,3}){
  auto before=run<Before>(area,sender,5,depart,ignore,repeats);auto after=run<After>(area,sender,5,depart,ignore,repeats);
  assert(before.sent==after.sent&&before.social==after.social&&before.looked==after.looked);assert(before.allocated>0&&after.allocated==0);++cases;
 }
 for(bool area:{false,true}){auto before=run<Before>(area,7,10000,false,false,1);auto after=run<After>(area,7,10000,false,false,1);assert(before.sent==after.sent&&after.sent.size()==10000);assert(before.allocated==10000&&after.allocated==0);}
 std::cout<<"PASS "<<cases<<" delivery/order/ignore/live-lookup cases; both native player variants; 10000-recipient delivery with zero temporary wrappers\n";
}
'''
def extract(s,klass):
 start=s.index('void Channel::SendToAll(');end=s.index('\n}\n',start)+3
 return s[start:end].replace('Channel::','%s::'%klass)
old=(r/'tests/architecture/ChannelFanoutReference.inc').read_text(encoding='utf-8')
new=(r/'src/game/Chat/Channel.cpp').read_text(encoding='utf-8')
(out/'fanout.cpp').write_text(prefix+extract(old,'Before')+extract(new,'After')+test,encoding='utf-8')
subprocess.run(['cl','/nologo','/std:c++17','/EHsc','/O2','/UNDEBUG','fanout.cpp','/Fe:fanout.exe'],cwd=out,check=True)
subprocess.run([str(out/'fanout.exe')],cwd=out,check=True,timeout=30)
