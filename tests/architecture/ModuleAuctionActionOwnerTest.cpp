#include <future>
#include <iostream>
#include <list>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <string>
#include <thread>
using ObjectGuid=unsigned;enum{UNIT_NPC_FLAG_AUCTIONEER};
struct Unit{};Unit npc;bool nearby=true,validHouse=true,validMap=true,fail=false;
struct Player{Unit*GetNPCIfCanInteractWith(unsigned,int){return nearby?&npc:nullptr;}};
struct Event{Player*GetOwner(){return nullptr;}std::string GetParam(){return "vendor";}};
struct Random{std::mutex m_ahActionMutex;}sRandomBotFacade;
struct AI{void TellPlayerNoFacing(Player*,std::string){}};
namespace TortoiseBots{struct BotWorldActions{static BotWorldActions&Instance(){static BotWorldActions x;return x;}std::optional<bool>Defer(Player*,std::string,Event&){return std::nullopt;}};}
struct AuctionHouseEntry{}house;struct AuctionHouseObject{}auctions;
struct AuctionHouseMgr{static AuctionHouseEntry const*GetAuctionHouseEntry(Unit*){return validHouse?&house:nullptr;}};
struct AuctionMgr{AuctionHouseObject*GetAuctionsMap(AuctionHouseEntry const*){return validMap?&auctions:nullptr;}}sAuctionMgr;
struct Base{Player*bot;AI*ai;std::string getName(){return "ah";}Player*GetMaster(){return nullptr;}};
struct AhAction:Base{unsigned executed=0;bool Execute(Event&);bool ExecuteCommand(Player*,std::string,Unit*){++executed;if(fail)throw std::runtime_error("native auction failure");return true;}};
struct GuildShareAhBuyAction:Base{bool Execute(Event&);Unit*FindNearbyAuctioneer(){return nearby?&npc:nullptr;}};
#define AI_VALUE(type,name) std::list<ObjectGuid>{1}
#include "ModuleAuctionActionOwner.inc"
#include "ModuleGuildAuctionOwner.inc"
    // Inject at the first allocation/data evaluation after native house checks.
    throw std::runtime_error("guild auction allocation failure");
}
bool Unlocked(){bool free=false;std::thread check([&]{free=sRandomBotFacade.m_ahActionMutex.try_lock();if(free)sRandomBotFacade.m_ahActionMutex.unlock();});check.join();return free;}
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player bot;AI ai;Event event;AhAction action{{&bot,&ai}};GuildShareAhBuyAction guild{{&bot,&ai}};
 CHECK(action.Execute(event)&&Unlocked());fail=true;bool threw=false;try{action.Execute(event);}catch(std::runtime_error const&){threw=true;}CHECK(threw&&Unlocked());fail=false;
 validHouse=false;CHECK(!guild.Execute(event)&&Unlocked());validHouse=true;validMap=false;CHECK(!guild.Execute(event)&&Unlocked());validMap=true;
 threw=false;try{guild.Execute(event);}catch(std::runtime_error const&){threw=true;}CHECK(threw&&Unlocked());
 std::promise<void> locked,release;auto done=release.get_future();std::thread holder([&]{std::lock_guard<std::mutex>guard(sRandomBotFacade.m_ahActionMutex);locked.set_value();done.wait();});locked.get_future().wait();unsigned before=action.executed;bool rejected=!action.Execute(event)&&!guild.Execute(event)&&action.executed==before;release.set_value();holder.join();CHECK(rejected&&Unlocked());
 nearby=false;CHECK(!action.Execute(event)&&!guild.Execute(event)&&Unlocked());
 std::cout<<"Native auction actions release locks on normal/rejected/exception paths and retain nonblocking contention\n";
}
