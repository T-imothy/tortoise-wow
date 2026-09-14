#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using ObjectGuid=unsigned;using uint32=unsigned;using uint8=unsigned char;
constexpr unsigned PLAYER_FLAGS=1,PLAYER_FLAGS_GHOST=2,CORPSE_RESURRECTABLE_PVP=1,STATUS_IN_PROGRESS=1;
constexpr float CORPSE_RECLAIM_RADIUS=39;
#define DETAIL_LOG(...) ((void)0)
struct Player;
struct Corpse {bool near=true;unsigned type=0;time_t time=0;time_t GetGhostTime(){return time;}unsigned GetType(){return type;}bool IsWithinDistInMap(Player*,float,bool){return near;}float GetPositionX(){return 1;}float GetPositionY(){return 2;}float GetPositionZ(){return 3;}unsigned GetMapId(){return 0;}};
struct BattleGround {unsigned status=STATUS_IN_PROGRESS;unsigned GetStatus()const{return status;}};
struct WorldSafeLocsEntry {unsigned ID=1,map_id=0;float x=1,y=2,z=3;};
struct Camera {unsigned updates=0;void UpdateVisibilityForOwner(){++updates;}};
struct Player {bool alive=false,ghost=true,refuse=false;unsigned delay=0,bones=0,repairs=0,visibility=0,teleports=0;float percent=0;Corpse*corpse=nullptr;BattleGround*bg=nullptr;Camera camera;std::vector<std::string>order;
 bool IsAlive(){return alive;}bool HasFlag(unsigned,unsigned){return ghost;}Corpse*GetCorpse(){return corpse;}unsigned GetCorpseReclaimDelay(bool){return delay;}BattleGround*GetBattleGround(){return bg;}bool InBattleGround(){return bg!=nullptr;}void ResurrectPlayer(float n,bool=false){order.push_back("resurrect");percent=n;if(!refuse)alive=true;}void SpawnCorpseBones(){order.push_back("bones");++bones;corpse=nullptr;}void DurabilityLossAll(float,bool){order.push_back("durability");++repairs;}float GetPositionX(){return 4;}float GetPositionY(){return 5;}float GetPositionZ(){return 6;}unsigned GetMapId(){return 0;}unsigned GetTeam(){return 0;}float GetOrientation(){return 0;}void TeleportTo(unsigned,float,float,float,float){++teleports;}Camera&GetCamera(){return camera;}void UpdateObjectVisibility(){++visibility;}
 bool fellThrough=false;void EntryRecovery(){struct Entry{unsigned destination=1;}e;auto*entrance=&e;unsigned TeleOptions=0;
#include "NativeEntryResurrection.inc"
 fellThrough=true;
 }
 void TeleportTo(unsigned,unsigned){++teleports;}
};
struct ObjectMgr {WorldSafeLocsEntry corpseGrave,ghostGrave;bool missing=false,same=false;WorldSafeLocsEntry const*GetClosestGraveYard(float x,float,float,unsigned,unsigned){return missing?nullptr:((x==1||same)?&corpseGrave:&ghostGrave);}float GetWorldSafeLocFacing(unsigned){return 0;}}sObjectMgr;
struct WorldPacket {WorldPacket&operator>>(ObjectGuid&g){g=1;return *this;}};
struct WorldSession {Player*_player;Player*GetPlayer(){return _player;}void HandleReclaimCorpseOpcode(WorldPacket&);void SendSpiritResurrect();};
#include "NativeCorpseReclaim.inc"
#include "NativeSpiritResurrection.inc"
void Check(bool ok,char const*msg){if(!ok){std::cerr<<msg<<'\n';std::exit(1);}}
int main(){Corpse corpse;Player p;WorldSession s{&p};WorldPacket packet;p.corpse=&corpse;p.refuse=true;s.HandleReclaimCorpseOpcode(packet);Check(!p.alive&&!p.bones&&p.corpse==&corpse,"refused reclaim preserves corpse");p.refuse=false;s.HandleReclaimCorpseOpcode(packet);Check(p.alive&&p.bones==1&&p.percent==.5f,"normal reclaim accepted");
 p=Player{};p.corpse=&corpse;BattleGround bg;p.bg=&bg;bg.status=0;s.HandleReclaimCorpseOpcode(packet);Check(p.order.empty(),"BG preparation retains reclaim exclusion");bg.status=1;s.HandleReclaimCorpseOpcode(packet);Check(p.alive&&p.percent==1.0f,"active BG native health preserved");
 p=Player{};p.corpse=&corpse;corpse.near=false;s.HandleReclaimCorpseOpcode(packet);Check(p.order.empty(),"distant corpse remains rejected");corpse.near=true;corpse.time=time(nullptr);p.delay=30;s.HandleReclaimCorpseOpcode(packet);Check(p.order.empty(),"reclaim delay remains native");corpse.time=0;
 p=Player{};p.corpse=&corpse;p.refuse=true;s.SendSpiritResurrect();Check(!p.alive&&!p.repairs&&!p.bones&&!p.teleports&&!p.visibility&&p.corpse==&corpse,"refused spirit resurrection has no follow-up effects");p.refuse=false;s.SendSpiritResurrect();Check(p.alive&&p.repairs==1&&p.bones==1&&p.teleports==1,"accepted healer retains native corpse graveyard relocation");Check((p.order==std::vector<std::string>{"resurrect","resurrect","durability","bones"}),"native post-acceptance ordering retained");
 p=Player{};p.corpse=&corpse;sObjectMgr.same=true;s.SendSpiritResurrect();Check(!p.teleports&&p.visibility==1&&p.camera.updates==1,"same graveyard refreshes native visibility");
 p=Player{};p.corpse=&corpse;p.refuse=true;p.EntryRecovery();Check(p.fellThrough&&!p.bones&&!p.teleports,"refused dungeon recovery falls through to ghost route");p.refuse=false;p.fellThrough=false;p.EntryRecovery();Check(!p.fellThrough&&p.bones==1&&p.teleports==1,"accepted dungeon recovery retains entrance teleport");
 std::cout<<"Native resurrection acceptance and rejected cleanup contracts passed\n";
}

