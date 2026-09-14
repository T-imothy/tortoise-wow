"""Compile the actual native trade helper against controlled lifecycle/policy fixtures."""
from pathlib import Path
import argparse,subprocess
p=argparse.ArgumentParser();p.add_argument('--root',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
a.output.mkdir(parents=True,exist_ok=True)
s=(a.root/'src/game/Objects/Player.cpp').read_text(encoding='utf-8')
body=s[s.index('bool Player::BeginTradeWith('):s.index('\nUpdateMask Player::updateVisualBits;')]
fixture=r'''
#include <cassert>
#include <cstdint>
#include <iostream>
using uint32=uint32_t;using ObjectGuid=uint64_t;
enum {UNIT_STAT_STUNNED=1,UNIT_STAT_PENDING_STUNNED=2,TRADE_DISTANCE=10,CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_TRADE,SMSG_TRADE_STATUS,TRADE_STATUS_BEGIN_TRADE};
struct WorldPacket {WorldPacket(int,int){} template<class T>WorldPacket& operator<<(T){return *this;}};
struct Session {bool banned=false,logout=false;int packets=0;bool IsFingerprintBanned(){return banned;}bool isLogingOut(){return logout;}void SendPacket(WorldPacket*){++packets;}};
struct Player;
struct TradeData {Player* owner;Player* other;int delay=0;TradeData(Player*a,Player*b):owner(a),other(b){}void SetScamPreventionDelay(int x){delay=x;}};
struct Eluna {bool allowed=true;int calls=0;bool OnTradeInit(Player*,Player*){++calls;return allowed;}};
struct {bool cross=false;bool getConfig(int){return cross;}}sWorld;
struct Player {enum class HardcoreInteractionResult {Allowed,Denied};
 Session own;Session* session=&own;TradeData* m_trade=nullptr;bool alive=true,taxi=false;int state=0,map=1,team=0;float distance=0;bool hardcore=true;Eluna lua;bool hasLua=true;
 ~Player(){delete m_trade;} Session* GetSession(){return session;}bool IsAlive(){return alive;}bool HasUnitState(int x){return state&x;}bool IsTaxiFlying(){return taxi;}int FindMap(){return map;}int GetMap(){assert(map);return map;}float GetDistance3dToCenter(Player*){return distance;}int GetTeam(){return team;}
 HardcoreInteractionResult HandleHardcoreInteraction(Player*,bool trade){assert(trade);return hardcore?HardcoreInteractionResult::Allowed:HardcoreInteractionResult::Denied;}Eluna* GetEluna(){return hasLua?&lua:nullptr;}ObjectGuid GetObjectGuid(){return 1;}bool BeginTradeWith(Player*);
};
'''
tests=r'''
int main(){int cases=0;
 for(int test=0;test<24;++test){Player a,b;Player* target=&b;sWorld.cross=false;bool expected=false;
  switch(test){
  case 0:target=nullptr;break;case 1:target=&a;break;
  case 2:a.session=nullptr;break;case 3:b.session=nullptr;break;
  case 4:a.own.banned=true;break;
  case 5:a.m_trade=new TradeData(&a,&b);break;case 6:b.m_trade=new TradeData(&b,&a);break;
  case 7:a.alive=false;break;case 8:b.alive=false;break;
  case 9:a.state=UNIT_STAT_STUNNED;break;case 10:b.state=UNIT_STAT_PENDING_STUNNED;break;
  case 11:a.own.logout=true;break;case 12:b.own.logout=true;break;
  case 13:a.taxi=true;break;case 14:b.taxi=true;break;
  case 15:a.map=0;break;case 16:b.map=0;break;case 17:b.map=2;break;
  case 18:a.distance=11;break;case 19:b.team=1;break;
  case 20:a.hardcore=false;break;
  case 21:a.lua.allowed=false;
#ifndef ENABLE_ELUNA
   expected=true;
#endif
   break;
  case 22:expected=true;break;case 23:b.team=1;sWorld.cross=true;a.hasLua=false;expected=true;break;
  }
  auto oldA=a.m_trade;auto oldB=b.m_trade;
  assert(a.BeginTradeWith(target)==expected);
  if(expected){assert(a.m_trade&&b.m_trade);assert(a.m_trade->other==&b&&b.m_trade->other==&a);assert(a.m_trade->delay==200&&b.m_trade->delay==200);assert(b.own.packets==1);auto x=a.m_trade;auto y=b.m_trade;assert(!a.BeginTradeWith(&b));assert(a.m_trade==x&&b.m_trade==y&&b.own.packets==1);}
  else {assert(a.m_trade==oldA&&b.m_trade==oldB);assert(b.own.packets==0);}
  ++cases;
 }
 std::cout<<"PASS "<<cases<<" native trade initiation cases, including unchanged state on rejection and repeated initiation\n";
}
'''
src=a.output/'NativeTradeHelperTest.cpp';src.write_text(fixture+body+tests)
for enabled in (False,True):
 exe=a.output/('trade-eluna.exe' if enabled else 'trade.exe')
 cmd=['cl.exe','/nologo','/std:c++17','/EHsc','/W4',str(src),'/Fe:'+str(exe),'/Fo:'+str(a.output/'trade.obj')]
 if enabled:cmd.insert(1,'/DENABLE_ELUNA')
 subprocess.run(cmd,check=True,cwd=a.output)
 subprocess.run([str(exe)],check=True,cwd=a.output)
