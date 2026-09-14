#include <algorithm>
#include <cstdlib>
#include <iostream>
using uint32=unsigned;
constexpr unsigned MINUTE=60,IN_MILLISECONDS=1000;
namespace ai {
enum class TravelStatus {TRAVEL_STATUS_NONE,TRAVEL_STATUS_COOLDOWN};
struct TravelTarget {TravelStatus status=TravelStatus::TRAVEL_STATUS_NONE;unsigned expiry=0;void SetStatus(TravelStatus s){status=s;}void SetExpireIn(unsigned n){expiry=n;}};
struct TravelMgr {void SetNullTravelTarget(TravelTarget*t){t->status=TravelStatus::TRAVEL_STATUS_NONE;t->expiry=0;}};
}
namespace MaNGOS {template<class T>struct Singleton {static T&Instance(){static T s;return s;}};}
struct Context {ai::TravelTarget target;bool missing=false;struct Value {ai::TravelTarget*p;ai::TravelTarget*Get(){return p;}}value;template<class T>Value*GetValue(char const*){value.p=missing?nullptr:&target;return &value;}};
struct Guid {bool empty=true;bool IsEmpty()const{return empty;}};
struct Map {bool dungeon=false;bool IsDungeon(){return dungeon;}};
struct Area {unsigned Id=1;};
namespace ai {enum class TravelDestinationPurpose{GenericRpg,Grind};struct WorldPosition {Area area;bool known=true;unsigned getMapId()const{return 1;}float getX()const{return 1;}float getY()const{return 2;}float getZ()const{return 3;}Area const*GetArea()const{return known?&area:nullptr;}};}
struct Player {bool controlled=true,alive=true,teleport=false,combat=false,taxi=false,bg=false,queued=false,group=false,accept=true;uint32 level=10,teleports=0,binds=0;Map map;
 bool IsAlive(){return alive;}uint32 GetLevel(){return level;}bool IsBeingTeleported(){return teleport;}bool IsInCombat(){return combat;}bool IsTaxiFlying(){return taxi;}bool InBattleGround(){return bg;}bool InBattleGroundQueue(){return queued;}bool GetGroup(){return group;}Map*GetMap(){return &map;}uint32 GetGUIDLow(){return 1;}uint32 GetObjectGuid(){return 1;}float GetOrientation(){return 0;}bool TeleportTo(unsigned,float,float,float,float,unsigned){++teleports;return accept;}void SetHomebindToLocation(ai::WorldPosition const&,unsigned){++binds;}};
struct AI {Context context;Context*GetAiObjectContext(){return &context;}bool master=false;unsigned resets=0;bool HasActivePlayerMaster(){return master;}void Reset(bool){++resets;context.target={};}};
struct PlayerbotAIStorage {AI*ai=nullptr;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}AI*GetAI(Player*){return ai;}};
struct Facade {bool pinned=false;bool IsPinnedBot(uint32){return pinned;}}sRandomBotFacade;
struct Config {uint32 randomBotTeleportDistance=1000;}sPlayerbotAIConfig;
namespace TortoiseBots {
enum class RandomBotDestination{Level,LocalGrind,Rpg};
struct BotActivityLeaseManager {bool available=true;static BotActivityLeaseManager&Instance(){static BotActivityLeaseManager s;return s;}bool IsAvailableForBackground(uint32){return available;}};
struct Record {bool random=true;Guid masterGuid;};
struct BotManager {Record record;bool IsControllableBot(Player*p){return p->controlled;}Record*FindBot(uint32){return &record;}bool RelocateRandomBot(Player*,RandomBotDestination);};
ai::WorldPosition point;bool found=true;ai::TravelDestinationPurpose purpose;float distance=0;bool inn=false,checked=false;
ai::WorldPosition const*PickLevelFittingPoint(Player*,ai::TravelDestinationPurpose p,float d,bool i,bool c){purpose=p;distance=d;inn=i;checked=c;return found?&point:nullptr;}
#include "ModuleRandomRelocation.inc"
}
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){using namespace TortoiseBots;BotManager manager;Player bot;AI ai;PlayerbotAIStorage::Instance().ai=&ai;
 for(bool Player::*flag:{&Player::teleport,&Player::combat,&Player::taxi,&Player::bg,&Player::queued,&Player::group}){bot.*flag=true;Check(!manager.RelocateRandomBot(&bot,RandomBotDestination::Level),"busy bot cannot relocate");bot.*flag=false;}
 manager.record.random=false;Check(!manager.RelocateRandomBot(&bot,RandomBotDestination::Level),"owned character preserved");manager.record.random=true;
 ai.master=true;Check(!manager.RelocateRandomBot(&bot,RandomBotDestination::Level),"active master preserved");ai.master=false;
 BotActivityLeaseManager::Instance().available=false;Check(!manager.RelocateRandomBot(&bot,RandomBotDestination::Level),"other service lease preserved");BotActivityLeaseManager::Instance().available=true;
 found=false;Check(!manager.RelocateRandomBot(&bot,RandomBotDestination::Rpg)&&!bot.binds&&!bot.teleports,"missing destination preserves location and home bind");found=true;
 ai.context.target.expiry=123;
 bot.accept=false;Check(!manager.RelocateRandomBot(&bot,RandomBotDestination::Rpg)&&!bot.binds&&!ai.resets&&ai.context.target.expiry==123,"native rejection preserves bind and AI");bot.accept=true;
 Check(manager.RelocateRandomBot(&bot,RandomBotDestination::Rpg)&&purpose==ai::TravelDestinationPurpose::GenericRpg&&inn&&checked&&distance==0&&bot.binds==1&&ai.resets==1,"RPG uses validated inn and binds only after acceptance");
 Check(ai.context.target.status==ai::TravelStatus::TRAVEL_STATUS_COOLDOWN&&ai.context.target.expiry==600000,"accepted RPG relocation restores ten-minute dwell after reset");
 Check(manager.RelocateRandomBot(&bot,RandomBotDestination::LocalGrind)&&purpose==ai::TravelDestinationPurpose::Grind&&!inn&&checked&&distance==1000&&bot.binds==1,"local grind is a distinct native destination query");
 Check(manager.RelocateRandomBot(&bot,RandomBotDestination::Level)&&purpose==ai::TravelDestinationPurpose::Grind&&distance==0,"level relocation may choose other zones");
 Check(ai.context.target.status==ai::TravelStatus::TRAVEL_STATUS_NONE&&ai.context.target.expiry==0,"grind relocations do not inherit inn cooldown");
 ai.context.missing=true;Check(manager.RelocateRandomBot(&bot,RandomBotDestination::Rpg),"missing optional travel target retains accepted native relocation");
 std::cout<<"Native random relocation eligibility, destination purpose, rejection and home bind ordering passed\n";
}
