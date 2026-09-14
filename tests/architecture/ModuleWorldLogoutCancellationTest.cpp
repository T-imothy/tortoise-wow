#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
struct WorldPacket{};struct Event{};struct Session{bool logging=false,due=false;unsigned cancels=0;bool isLogingOut(){return logging;}bool ShouldLogOut(time_t){return due;}void HandleLogoutCancelOpcode(WorldPacket&){++cancels;logging=false;}};
struct Player{Session session;bool combat=false,safe=true;float distance=1;Session*GetSession(){return &session;}};
struct PlayerbotAI{Player*bot;Player*master=nullptr;std::weak_ptr<int>pendingLogoutCancellation[2];unsigned tells=0;void CancelLogout(bool);Player*GetMaster(){return master;}bool IsSafe(Player*p){return p&&p->safe;}void TellPlayer(Player*,std::string){++tells;}};
namespace TortoiseBots{struct BotWorldActions{inline static bool map=false;bool accept=true;std::deque<std::function<void(PlayerbotAI&)>>queue;static bool IsMapExecution(){return map;}static BotWorldActions&Instance(){static BotWorldActions x;return x;}bool EnqueueContinuation(Player*,std::string const&,Event,std::function<void(PlayerbotAI&)>f){if(!accept)return false;queue.push_back(std::move(f));return true;}void Drain(PlayerbotAI&ai){map=false;auto batch=std::move(queue);queue.clear();for(auto&f:batch)f(ai);map=true;}};}
struct Facade{bool IsInCombat(Player*p){return p->combat;}float getDistance2d(Player*,Player*p){return p->distance;}}sServerFacade;
#define BOT_TEXT(x)std::string(x)
#include "ModuleWorldLogoutCancellation.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player bot,master;PlayerbotAI ai{&bot,&master};auto&q=TortoiseBots::BotWorldActions::Instance();q.map=true;
 ai.CancelLogout(false);CHECK(q.queue.empty());bot.session.logging=true;master.combat=true;
 ai.CancelLogout(false);ai.CancelLogout(false);CHECK(q.queue.size()==1&&bot.session.cancels==0);q.Drain(ai);CHECK(bot.session.cancels==1&&ai.tells==1);
 bot.session.logging=true;master.safe=false;ai.CancelLogout(false);q.Drain(ai);CHECK(bot.session.logging&&bot.session.cancels==1);
 master.safe=true;master.distance=31;ai.CancelLogout(false);q.Drain(ai);CHECK(bot.session.logging);master.distance=1;master.combat=false;
 ai.CancelLogout(false);ai.CancelLogout(true);CHECK(q.queue.size()==2);q.Drain(ai);CHECK(!bot.session.logging&&bot.session.cancels==2);
 bot.session.logging=true;bot.session.due=true;ai.CancelLogout(true);q.Drain(ai);CHECK(bot.session.logging);bot.session.due=false;
 q.accept=false;ai.CancelLogout(true);CHECK(q.queue.empty());q.accept=true;ai.CancelLogout(true);CHECK(q.queue.size()==1);q.queue.clear();ai.CancelLogout(true);CHECK(q.queue.size()==1);q.Drain(ai);CHECK(!bot.session.logging);
 bot.session.logging=true;bot.combat=true;ai.master=nullptr;ai.CancelLogout(false);q.Drain(ai);CHECK(!bot.session.logging);
 std::cout<<"Native logout cancellation passed: world ownership, local combat, explicit reset, coalescing, rejection/discard retry and due-logout preservation\n";
}
