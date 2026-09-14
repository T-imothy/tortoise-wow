from pathlib import Path
r=Path(__file__).resolve().parents[2]
import argparse, subprocess
parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
out=args.output.resolve();out.mkdir(parents=True,exist_ok=True)
mapcode=(r/'src/game/Maps/Map.cpp').read_text()
start=mapcode.index('    auto execute = [this, now](Request const& request, bool minimal)')
end=mapcode.index('    for (Request const& request : foreground)',start)
dispatch=mapcode[start:end]
module=(r/'modules/ManTechPlayerbots/playerbot/PlayerbotScripts.cpp').read_text()
start=module.index('        bool IsAIUpdateDue(Player* player, uint32 diff) override')
end=module.index('\n};',start)
hooks=module[start:end].replace(' override','')
session=(r/'src/game/WorldSession.cpp').read_text()
start=session.index('    for (bool& received : _receivedPacketType)')
end=session.index('\n',session.index('        received = false;',start))
initialization=session[start:end]
prefix=r'''
#include <cassert>
#include <cstdint>
#include <iostream>
#include <new>
#include <cstring>
#include "Maps/BackgroundAIScheduling.h"
#include "MapWork.h"
using uint32=uint32_t;using uint64=uint64_t;
#define MANTECH_DIAG_SCOPE(...)
struct ObjectGuid { uint32 id=1; uint32 GetCounter()const{return id;} };
struct Map;
struct PlayerbotAI {
 uint32 delay=0,calls=0,minimalDelay=0,decisions=0; bool simulateIdle=false,legacyYield=false; bool transition=false,master=false,lastMinimal=false;
 void (*onUpdate)()=nullptr;
 bool HasPendingTransition()const{return transition;}
 bool HasRealPlayerMaster()const{return master;}
 uint32 GetAIInternalUpdateDelay()const{return delay;}
 uint32 GetBackgroundMinimalDelay()const{return minimalDelay;}
 void AdvanceBackgroundMinimalDelay(uint32 elapsed){minimalDelay=minimalDelay>elapsed?minimalDelay-elapsed:0;}
 void DeferBackgroundMinimalUpdate(uint32 d){minimalDelay=d;}
 void AdvanceMinimalUpdateDelay(uint32 elapsed){delay=delay>elapsed?delay-elapsed:0;}
 void SetNextCheckDelay(uint32 d){delay=d;}
 void UpdateAI(uint32 elapsed,bool minimal){++calls;lastMinimal=minimal;AdvanceMinimalUpdateDelay(elapsed);if(onUpdate)onUpdate();
  if(simulateIdle&&!delay){if(!minimal){++decisions;delay=1000;}else if(legacyYield)delay=1000;}
 }
};
struct Player {
 Map* map=nullptr; ObjectGuid guid; PlayerbotAI* ai=nullptr;
 uint64 generation=1; bool world=true,teleport=false,combat=false,responsive=false;
 uint32 consumed=0,clock=0,dueAge=0;
 Map* FindMap()const{return map;}
 bool IsBeingTeleported()const{return teleport;}
 bool IsInWorld()const{return world;}
 bool IsInCombat()const{return combat;}
 uint32 GetMapId()const{return 0;} uint32 GetInstanceId()const{return 1;}
 uint64 GetMapWorkGeneration()const{return generation;}
 uint32 GetGUIDLow()const{return guid.id;} ObjectGuid GetObjectGuid()const{return guid;}
 void ConsumeAIElapsed(uint32 now){clock=now;++consumed;}
 void ClearBackgroundAIDueAge(){dueAge=0;}
};
PlayerbotAI* GetBotAI(Player* p){return p->ai;}
struct Stamp { uint64 generation=1; bool Matches(uint32 map,uint32 instance,uint64 gen,bool world)const{return world&&map==0&&instance==1&&gen==generation;} };
struct Request { ObjectGuid guid; Stamp stamp; uint32 elapsed; };
struct ExecutionWatch { enum {BotAI}; static void Set(int,uint32,uint32,uint32){} };
namespace ai { namespace WorldActions {struct MapScope{};} }
struct Config {int GetIntDefault(const char*,int d){return d;}} sConfig;
struct AIConfig{bool enabled=true;uint32 passiveDelay=2000,reactDelay=100;}sPlayerbotAIConfig;
struct Map {
 Player* p=nullptr; uint32 m_aiStale=0,m_aiUpdates=0;
 Player* GetPlayer(ObjectGuid guid){return p&&p->guid.id==guid.id&&p->map==this?p:nullptr;}
 uint32 GetId(){return 0;}uint32 GetInstanceId(){return 1;}
 bool IsResponsivePlayer(Player* p){return p->responsive;}
 bool IsAutonomousActivePlayer(Player* p){return p->combat;}
 void Run(Request const&,bool);
};
struct Hooks {
'''
middle=r'''
} hooks;
void Script_UpdateAI(Player* p,uint32 elapsed,bool minimal){hooks.OnAIUpdate(p,elapsed,minimal);}
void Map::Run(Request const& request,bool minimal){uint32 const now=5000;
'''
tests=r'''
 execute(request,minimal);
}
Player* changing=nullptr;
void Transfer(){++changing->generation;changing->map=nullptr;}
void EnterCombat(){changing->combat=true;}
struct SessionFlags {bool _receivedPacketType[8];SessionFlags(){ SESSION_INITIALIZATION }};
int main(){
 alignas(SessionFlags) unsigned char storage[sizeof(SessionFlags)];
 std::memset(storage,0xff,sizeof(storage));
 auto* flags=new(storage) SessionFlags;
 for(bool received:flags->_receivedPacketType)assert(!received);
 flags->_receivedPacketType[2]=true;assert(flags->_receivedPacketType[2]);
 flags->~SessionFlags();
 // Every GUID gets a full autonomous turn even with no humans present.
 for(uint32 avg:{0u,10u,120u,250u,400u,1000u})for(bool humans:{false,true}){
  uint32 n=BackgroundAI::FullCadence(avg,humans);
  for(uint32 guid=1;guid<=10000;++guid){uint32 full=0;for(uint32 tick=0;tick<n;++tick)full+=IsStaggeredMapWorkDue(tick,guid,n);assert(full==1);}
 }
 assert(BackgroundAI::FullCadence(250,false)==75);
 assert(BackgroundAI::FullCadence(250,true)==25);
 assert(BackgroundAI::NextMinimalDelay(9000,2000,100,7,4000)==9000);
 assert(BackgroundAI::NextMinimalDelay(0,2000,100,7,0)==2000);
 for(uint32 guid=1;guid<=10000;++guid){auto d=BackgroundAI::NextMinimalDelay(0,2000,100,guid,4000);assert(d>=2000&&d<=6000);}
 Map map;PlayerbotAI bot;Player player;player.map=&map;player.ai=&bot;map.p=&player;changing=&player;
 Request request{player.guid,{},400};
 // Actual module due hook: not-due time is consumed once; deferred due probes
 // must not consume it until the actual admitted update executes.
 bot.delay=1000;assert(!hooks.IsAIUpdateDue(&player,300));assert(bot.delay==700);
 assert(hooks.IsAIUpdateDue(&player,700));assert(bot.delay==700);
 assert(hooks.IsAIUpdateDue(&player,900));assert(bot.delay==700);
 request.elapsed=900;map.Run(request,false);assert(bot.delay==0&&!bot.lastMinimal&&bot.calls==1);
 // Actual native dispatcher + module hook apply the minimal floor.
 map.Run(request,true);assert(bot.lastMinimal&&bot.delay==0&&bot.minimalDelay>=2000&&bot.minimalDelay<=6000);
 // Combat/player interest promoted after snapshot, without an idle floor.
 bot.delay=0;player.combat=true;map.Run(request,true);assert(!bot.lastMinimal&&bot.delay==0);
 player.combat=false;player.responsive=true;map.Run(request,true);assert(!bot.lastMinimal);
 player.responsive=false;
 // Map transfer/teleport/unlink do not execute or consume a deferred clock.
 auto calls=bot.calls,consumed=player.consumed;
 ++player.generation;map.Run(request,true);assert(bot.calls==calls&&player.consumed==consumed&&map.m_aiStale==1);
 --player.generation;player.teleport=true;map.Run(request,true);assert(bot.calls==calls&&player.consumed==consumed);
 player.teleport=false;player.world=false;map.Run(request,true);assert(bot.calls==calls);player.world=true;
 // Actual post-update rescheduling does not touch a transferred AI or combat
 // state that changed during UpdateAI itself.
 bot.delay=0;bot.onUpdate=EnterCombat;map.Run(request,true);assert(bot.delay==0);player.combat=false;
 bot.onUpdate=Transfer;map.Run(request,true);assert(bot.delay==0&&player.map==nullptr);
 // Reproduce the deployed timer collision using its actual owner hooks and
 // the native countdown/CanUpdate/Yield contract. Full opportunities alone
 // are insufficient: count full decisions after the timer gate instead.
 for(uint32 passive:{2000u,10000u}) {
 sPlayerbotAIConfig.passiveDelay=passive;
 uint32 oldStarved=0,newStarved=0;
 for(uint32 guid=1;guid<=10000;++guid){
  Player oldPlayer,newPlayer;Map oldMap,newMap;PlayerbotAI oldAI,newAI;
  oldPlayer.map=&oldMap;oldPlayer.ai=&oldAI;oldPlayer.guid.id=guid;oldMap.p=&oldPlayer;
  newPlayer.map=&newMap;newPlayer.ai=&newAI;newPlayer.guid.id=guid;newMap.p=&newPlayer;
  oldAI.simulateIdle=newAI.simulateIdle=true;oldAI.legacyYield=true;
  for(uint32 tick=1;tick<=3000;++tick){
   bool full=IsStaggeredMapWorkDue(tick,guid,BackgroundAI::FullCadence(100,false));
   if(full||legacyHooks.IsAIUpdateDue(&oldPlayer,100))legacyHooks.OnAIUpdate(&oldPlayer,100,!full);
   if(full||hooks.IsAIUpdateDue(&newPlayer,100))hooks.OnAIUpdate(&newPlayer,100,!full);
  }
  oldStarved+=oldAI.decisions==0;newStarved+=newAI.decisions==0;
  assert(newAI.decisions>=90);
 }
 assert(oldStarved>1000&&newStarved==0);
 std::cout<<"Passive="<<passive<<"ms: old starved="<<oldStarved<<"/10000; corrected="<<newStarved<<"/10000 over five simulated minutes\n";
 }
 sPlayerbotAIConfig.passiveDelay=2000;
 // Legitimate action/cast delays survive a full update even when the separate
 // minimal throttle is longer. Each elapsed interval is consumed exactly once.
 Player timedPlayer;Map timedMap;PlayerbotAI timedAI;timedPlayer.map=&timedMap;timedMap.p=&timedPlayer;timedPlayer.ai=&timedAI;
 timedAI.delay=5000;timedAI.minimalDelay=9000;
 hooks.OnAIUpdate(&timedPlayer,3000,false);assert(timedAI.delay==2000&&timedAI.minimalDelay==6000);
 assert(!hooks.IsAIUpdateDue(&timedPlayer,1000));assert(timedAI.delay==1000&&timedAI.minimalDelay==5000);
 hooks.OnAIUpdate(&timedPlayer,1000,false);assert(timedAI.delay==0&&timedAI.minimalDelay==4000);
 std::cout<<"Native five-second action delay retained with independent minimal throttle.\n";
 std::cout<<"PASS: native packet flags clear on dirty allocation; 10k GUID full-turn fairness; due/deferred timer accounting; minimal floors; combat/player promotion; stale/teleport/unlink; transfer during AI\n";
}
'''
legacy = (r/'tests/architecture/fixtures/Build83BackgroundHooks.inc').read_text().replace(' override','')
aiCode=(r/'modules/ManTechPlayerbots/playerbot/PlayerbotAI.cpp').read_text()
assert 'if (!minimal)\n            YieldAIInternalThread(min);' in aiCode
assert 'backgroundMinimalDelay = 0;\n    reactionEngine->Reset();' in aiCode
legacyClass='struct LegacyHooks {\n'+legacy+'\n} legacyHooks;\n'
(out/'test.cpp').write_text((prefix+hooks+middle+dispatch+tests).replace('SESSION_INITIALIZATION',initialization).replace('int main(){',legacyClass+'int main(){'))
print(out/'test.cpp')

subprocess.run(['cl','/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG','/I'+str(r/'src/game'),'/I'+str(r/'src/shared'),'test.cpp','/Fe:test.exe'],cwd=out,check=True)
subprocess.run([str(out/'test.exe')],cwd=out,check=True,timeout=45)
