#include <iostream>
#include <optional>
#include <string>
using uint32=unsigned;
struct ObjectGuid{unsigned id=0;bool IsEmpty()const{return !id;}};
namespace ai{
#include "ModuleGuildShareTarget.inc"
}
using ai::GuildShareTarget;
struct Event{};struct Player;
struct Map{Player*receiver=nullptr;Player*GetPlayer(ObjectGuid);};
struct Player{ObjectGuid guid;Map*map=nullptr;bool alive=true,world=true,teleport=false,combat=false;unsigned guild=1;bool IsAlive(){return alive;}bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}bool IsInCombat(){return combat;}unsigned GetGuildId(){return guild;}Map*GetMap(){return map;}};
Player*Map::GetPlayer(ObjectGuid g){return receiver&&receiver->guid.id==g.id?receiver:nullptr;}
struct PlayerbotAI{static bool IsSafe(Player*a,Player*b){return a&&b&&a->map&&a->map==b->map&&a->world&&b->world&&!a->teleport&&!b->teleport;}};
struct PlayerbotAIStorage{Player*registered=nullptr;PlayerbotAI value;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage x;return x;}PlayerbotAI*GetAI(Player*p){return p==registered?&value:nullptr;}};
namespace TortoiseBots{struct BotWorldActions{inline static bool map=false;static BotWorldActions&Instance(){static BotWorldActions x;return x;}std::optional<bool>Defer(Player*,std::string const&,Event const&){if(map)return false;return std::nullopt;}};}
struct GuildShareItemAction{Player*bot;GuildShareTarget cached,fresh;unsigned resets=0;std::string getName(){return "guild share item";}bool Execute(Event&);};
#define RESET_AI_VALUE(T,n)do{cached=fresh;++resets;}while(0)
#define AI_VALUE(T,n) cached
#include "ModuleGuildRecipientGate.inc"
 return true;
}
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Map map,other;Player bot{{1},&map},receiver{{2},&map};map.receiver=&receiver;PlayerbotAIStorage::Instance().registered=&receiver;GuildShareItemAction action;action.bot=&bot;action.fresh={{2},100,5};action.cached={{999},200,10};Event event;
 TortoiseBots::BotWorldActions::map=true;CHECK(!action.Execute(event)&&action.resets==0);TortoiseBots::BotWorldActions::map=false;
 CHECK(action.Execute(event)&&action.resets==1&&action.cached.receiverGuid.id==2&&action.cached.amount==5);
 map.receiver=nullptr;CHECK(!action.Execute(event));map.receiver=&receiver;
 receiver.map=&other;CHECK(!action.Execute(event));receiver.map=&map;
 receiver.guild=2;CHECK(!action.Execute(event));receiver.guild=1;
 receiver.teleport=true;CHECK(!action.Execute(event));receiver.teleport=false;
 receiver.world=false;CHECK(!action.Execute(event));receiver.world=true;
 receiver.alive=false;CHECK(!action.Execute(event));receiver.alive=true;
 receiver.combat=true;CHECK(!action.Execute(event));receiver.combat=false;
 PlayerbotAIStorage::Instance().registered=nullptr;CHECK(!action.Execute(event));PlayerbotAIStorage::Instance().registered=&receiver;
 bot.map=nullptr;CHECK(!action.Execute(event));bot.map=&map;
 bot.guild=0;CHECK(!action.Execute(event));bot.guild=1;
 action.fresh={};CHECK(!action.Execute(event));
 std::cout<<"Guild recipient gate checks passed: copied GUID, live decision refresh, no map mutation and transfer/logout/reclaim/guild rejection\n";
}
