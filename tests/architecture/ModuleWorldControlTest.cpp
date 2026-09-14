#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <list>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <stdexcept>
struct Event{};struct PlayerbotAI;
namespace TortoiseBots{struct BotWorldActions{
 inline static bool map=false;bool accept=true;std::deque<std::function<void(PlayerbotAI&)>>pending;
 static BotWorldActions&Instance(){static BotWorldActions x;return x;}static bool IsMapExecution(){return map;}
 template<class P>bool EnqueueContinuation(P*,std::string const&,Event const&,std::function<void(PlayerbotAI&)>f){if(!accept)return false;pending.push_back(std::move(f));return true;}
 void Drain(PlayerbotAI&ai){struct Restore{bool before;~Restore(){map=before;}}restore{map};map=false;auto batch=std::move(pending);pending.clear();for(auto&f:batch)f(ai);}
};}
std::vector<int>seen;
struct Session{bool logout=false;bool isLogingOut(){return logout;}};
struct Player{Session session;bool world=true,teleport=false;bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}Session*GetSession(){return &session;}char const*GetName(){return "fixture";}};
struct ExternalEventHelper{explicit ExternalEventHelper(void*){}};
struct PacketHelper{int id,packets=0;bool HasPackets(){return packets!=0;}void Handle(ExternalEventHelper&){if(TortoiseBots::BotWorldActions::map)throw std::runtime_error("map packet handler");if(packets){seen.push_back(id);packets=0;}}};
struct ChatQueuedReply{time_t m_time=0;int m_type=4,m_guid1=0,m_guid2=0;std::string m_msg,m_chanName,m_name;};
struct ChatReplyAction{static void ChatReplyDo(Player*,int id,int,int,std::string const&,std::string const&,std::string const&){if(TortoiseBots::BotWorldActions::map)throw std::runtime_error("map chat reply");seen.push_back(id);}};
struct Config{unsigned reactDelay=100;}sPlayerbotAIConfig;
#define SC_PHASE(...)
struct PlayerbotAI{
 Player*bot;void*aiObjectContext=nullptr;std::weak_ptr<int>pendingWorldControl,pendingCommands;
 std::mutex chatRepliesMutex;std::queue<ChatQueuedReply>chatReplies;
 PacketHelper botOutgoingPacketHandlers{1},masterIncomingPacketHandlers{2},masterOutgoingPacketHandlers{3};
 unsigned delay=0,commands=0;
 void SetAIInternalUpdateDelay(unsigned d){delay=d;}
 bool EnterWorldControl(std::weak_ptr<int>&,std::string const&,void(PlayerbotAI::*)());
 void ProcessWorldControl();
 void Commands(){if(EnterWorldControl(pendingCommands,"commands",&PlayerbotAI::Commands))++commands;}
};
#include "ModuleWorldControl.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player bot;PlayerbotAI ai;ai.bot=&bot;auto&q=TortoiseBots::BotWorldActions::Instance();
 TortoiseBots::BotWorldActions::map=true;ai.ProcessWorldControl();CHECK(q.pending.empty());
 ai.botOutgoingPacketHandlers.packets=1;ai.masterIncomingPacketHandlers.packets=1;ai.masterOutgoingPacketHandlers.packets=1;ai.chatReplies.push({});
 ai.ProcessWorldControl();ai.ProcessWorldControl();CHECK(q.pending.size()==1&&seen.empty());q.Drain(ai);CHECK(seen==std::vector<int>({4,1,2,3}));
 ai.Commands();ai.Commands();CHECK(q.pending.size()==1&&ai.commands==0);q.Drain(ai);CHECK(ai.commands==1);
 ai.botOutgoingPacketHandlers.packets=1;ai.ProcessWorldControl();q.pending.clear();q.accept=false;ai.ProcessWorldControl();CHECK(q.pending.empty());q.accept=true;ai.ProcessWorldControl();CHECK(q.pending.size()==1);q.Drain(ai);CHECK(seen.back()==1);
 ai.masterIncomingPacketHandlers.packets=1;ai.ProcessWorldControl();bot.teleport=true;q.Drain(ai);CHECK(ai.masterIncomingPacketHandlers.packets==1);bot.teleport=false;ai.ProcessWorldControl();q.Drain(ai);CHECK(ai.masterIncomingPacketHandlers.packets==0);
 bot.session.logout=true;ai.botOutgoingPacketHandlers.packets=1;ai.chatReplies.push({});ai.ProcessWorldControl();q.Drain(ai);CHECK(ai.delay==100&&ai.botOutgoingPacketHandlers.packets==1&&seen.back()==4);bot.session.logout=false;
 ai.ProcessWorldControl();q.Drain(ai);CHECK(ai.botOutgoingPacketHandlers.packets==0);
 ChatQueuedReply future;future.m_time=time(nullptr)+10000;ai.chatReplies.push(future);ai.chatReplies.push({});ai.ProcessWorldControl();q.Drain(ai);CHECK(ai.chatReplies.size()==1&&ai.chatReplies.front().m_time==future.m_time&&seen.back()==4);
 TortoiseBots::BotWorldActions::map=false;ai.Commands();CHECK(ai.commands==2);
 std::cout<<"Native control phase checks passed: no empty work, owner-only dispatch, original order, coalescing, refusal/retry, transfer and logout\n";
}
