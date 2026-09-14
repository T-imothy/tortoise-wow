#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <unordered_map>
#include <vector>
#include "BotWorldActions.h"
struct Session {bool headless=true;bool IsHeadless(){return headless;}};
struct Player{ObjectGuid guid;unsigned map=1,instance=0;uint64_t generation=1;unsigned GetMapId(){return map;}unsigned GetInstanceId(){return instance;}uint64_t GetMapWorkGeneration(){return generation;}Session session;bool world=true,teleport=false,controlled=true;ObjectGuid GetObjectGuid(){return guid;}unsigned GetGUIDLow(){return guid.value;}bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}Session*GetSession(){return &session;}};
std::map<ObjectGuid,Player*> players;
struct Accessor{Player*FindPlayer(ObjectGuid guid){auto i=players.find(guid);return i==players.end()?nullptr:i->second;}}sObjectAccessor;
#include "ModuleEventOwner.inc"
struct ByteBufferException{};
struct PlayerbotAI{unsigned calls=0;std::function<void()>callback;bool DoSpecificAction(std::string const&,Event const&,bool){++calls;if(callback)callback();return true;}};
std::map<Player*,PlayerbotAI*> ais;
struct PlayerbotAIStorage{static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage x;return x;}PlayerbotAI*GetAI(Player*p){auto i=ais.find(p);return i==ais.end()?nullptr:i->second;}};
namespace TortoiseBots{struct BotManager{static BotManager&Instance(){static BotManager x;return x;}bool IsControllableBot(Player*p){return p->controlled&&p->world&&p->session.headless;}};}
unsigned malformed=0;struct Log{template<class...T>void outError(T...){++malformed;}}sLog;
#include "ModuleWorldActions.inc"
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){auto&queue=TortoiseBots::BotWorldActions::Instance();Player bot{{1}},requester{{2}};PlayerbotAI ai;players[bot.guid]=&bot;players[requester.guid]=&requester;ais[&bot]=&ai;Event event("guild invite",std::string(),&requester);
 CHECK(!queue.Defer(&bot,"guild accept",event).has_value());
 TortoiseBots::BotWorldActions::MapScope mapScope;
 CHECK(queue.Defer(&bot,"guild accept",event)==false);queue.Drain();CHECK(ai.calls==0);
 {TortoiseBots::BotWorldActions::WorldScope owner;CHECK(!queue.Defer(&bot,"invite",event).has_value());{TortoiseBots::BotWorldActions::WorldScope nested;CHECK(!queue.Defer(&bot,"accept",event).has_value());}CHECK(!queue.Defer(&bot,"follow",event).has_value());}
 CHECK(queue.Enqueue(&bot,"guild accept",event)==true);CHECK(ai.calls==0);
 bool nested=false;ai.callback=[&]{nested=!queue.Defer(&bot,"nested",event).has_value();};queue.Drain();CHECK(ai.calls==1&&nested);ai.callback={};
 CHECK(queue.Enqueue(&bot,"guild accept",event)==true);Event::InvalidateOwner(&requester);queue.Drain();CHECK(ai.calls==1);
 Event automatic("world buff");CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);Event::InvalidateOwner(&bot);queue.Drain();CHECK(ai.calls==1);
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);bot.teleport=true;queue.Drain();CHECK(ai.calls==1);bot.teleport=false;
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);++bot.generation;queue.Drain();CHECK(ai.calls==1);
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);++bot.map;queue.Drain();CHECK(ai.calls==1);
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);++bot.instance;queue.Drain();CHECK(ai.calls==1);
 bot.teleport=true;CHECK(queue.Enqueue(&bot,"world buff",automatic)==false);bot.teleport=false;
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);bot.controlled=false;queue.Drain();CHECK(ai.calls==1);bot.controlled=true;
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);ais.clear();queue.Drain();CHECK(ai.calls==1);ais[&bot]=&ai;
 bot.session.headless=false;CHECK(queue.Enqueue(&bot,"world buff",automatic)==false);bot.session.headless=true;
 for(unsigned n=0;n<8;++n)CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);CHECK(queue.Enqueue(&bot,"world buff",automatic)==false);queue.Clear();
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);ai.callback=[&]{if(ai.calls==2)throw ByteBufferException();};queue.Drain();CHECK(ai.calls==3&&malformed==1);ai.callback={};
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);ai.callback=[] {throw std::runtime_error("test");};bool threw=false;try{queue.Drain();}catch(std::runtime_error const&){threw=true;}CHECK(threw);ai.callback={};CHECK(queue.Enqueue(&bot,"world buff",automatic));queue.Drain();
 // Bound admission and drain count independently of population.
 std::vector<Player> population(129);PlayerbotAI crowdAI;
 for(unsigned n=0;n<population.size();++n){auto&p=population[n];p.guid=ObjectGuid(100+n);players[p.guid]=&p;ais[&p]=&crowdAI;for(unsigned k=0;k<8;++k)CHECK(queue.Enqueue(&p,"world buff",automatic)==(n<128));}
 queue.Drain();CHECK(crowdAI.calls>0&&crowdAI.calls<=64);queue.Clear();
 // A slow native mutation cannot trigger an unlimited catch-up burst.
 unsigned before=ai.calls;ai.callback=[] {std::this_thread::sleep_for(std::chrono::milliseconds(6));};
 CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);CHECK(queue.Enqueue(&bot,"world buff",automatic)==true);queue.Drain();CHECK(ai.calls==before+1);queue.Clear();ai.callback={};
 // Concurrent producers share the per-bot bound; gameplay stays in the drain.
 std::atomic<unsigned>admitted=0;std::vector<std::thread>threads;before=ai.calls;
 for(unsigned n=0;n<8;++n)threads.emplace_back([&]{TortoiseBots::BotWorldActions::MapScope worker;for(unsigned k=0;k<16;++k)if(queue.Enqueue(&bot,"world buff",automatic)==true)++admitted;});
 for(auto&t:threads)t.join();CHECK(admitted==8&&ai.calls==before);queue.Drain();CHECK(ai.calls==before+8);queue.Clear();
 // Continuations use the same lifetime/domain barrier, with no named-action replay.
 unsigned resumed=0;before=ai.calls;
 CHECK(queue.EnqueueContinuation(&bot,"resume",automatic,[&](PlayerbotAI& current){if(&current==&ai&&!TortoiseBots::BotWorldActions::IsMapExecution())++resumed;}));
 queue.Drain();CHECK(resumed==1&&ai.calls==before);
 CHECK(queue.EnqueueContinuation(&bot,"resume",automatic,[&](PlayerbotAI&){++resumed;}));
 ++bot.generation;queue.Drain();CHECK(resumed==1);
 CHECK(queue.EnqueueContinuation(&bot,"resume",automatic,[&](PlayerbotAI&){++resumed;}));
 queue.Clear();queue.Drain();CHECK(resumed==1);
 Event::InvalidateOwner(&bot);Event::InvalidateOwner(&requester);for(auto&p:population)Event::InvalidateOwner(&p);
 std::cout<<"Native queued world actions preserve identity, nested order, bounds, recovery and owner-only execution\n";
}
