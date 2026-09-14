#include <atomic>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <ctime>
#include "Event.h"
struct Player {ObjectGuid guid;ObjectGuid GetObjectGuid(){return guid;}};
std::map<ObjectGuid,Player*> players;
struct Accessor{Player* FindPlayer(ObjectGuid guid){auto it=players.find(guid);return it==players.end()?nullptr:it->second;}}sObjectAccessor;
#include "ModuleEventOwner.inc"
struct Action{};
int executed=0;
struct Engine{bool ListenAndExecute(Action*,Event&);};struct ReactionEngine{bool ListenAndExecute(Action*,Event&);};
#include "ModuleEventExecuteGate.inc"
 ++executed;return true;}
#include "ModuleEventReactionGate.inc"
 ++executed;return true;}
struct Trigger {
 Event externalEvent;bool triggered=false;std::string getName(){return "test";}
 virtual void ExternalEvent(WorldPacket&,Player*){}virtual void ExternalEvent(std::string,Player*){}virtual Event Check(){return externalEvent;}virtual void Reset(){triggered=false;externalEvent=Event();}
#include "ModuleEventForce.inc"
};
struct PacketTrigger:Trigger {
#include "ModuleEventPacketTrigger.inc"
};
struct ChatTrigger:Trigger {
#include "ModuleEventChatTrigger.inc"
};
using uint32=unsigned;constexpr uint32 CHAT_MSG_WHISPER=1;
#include "ModuleChatRequester.inc"
unsigned parsedCommands=0;
struct ExternalEventHelper{explicit ExternalEventHelper(void*){}bool ParseChatCommand(std::string const&,Player*){++parsedCommands;return true;}};
struct PlayerbotAI {std::weak_ptr<int> pendingWorldCommands;bool EnterWorldControl(std::weak_ptr<int>&,std::string const&,void(PlayerbotAI::*)()){return true;}void*aiObjectContext=nullptr;std::queue<ChatCommandHolder> chatCommands;void HandleCommands();};
#include "ModuleChatRequesterDrain.inc"
int main(){bool fail=false;Player p{{1}},replacement{{1}};players[p.guid]=&p;WorldPacket packet;packet.payload=42;Action action;Engine engine;ReactionEngine reaction;
 Event original("chat",std::string("follow"),&p);Event copy=original;Event assigned;assigned=copy;
 PacketTrigger packets;ChatTrigger chat;Trigger forced;packets.ExternalEvent(packet,&p);chat.ExternalEvent("follow",&p);forced.ExternalEventForce("stay",&p);
 if(original.GetOwner()!=&p||original.HasExpiredOwner()||copy.GetParam()!="follow"||packets.Check().GetPacket().payload!=42)fail=true;
 players[p.guid]=&replacement;if(original.GetOwner()!=nullptr||!original.HasExpiredOwner())fail=true;players[p.guid]=&p;
 PlayerbotAI ai;
 ai.chatCommands.push(ChatCommandHolder("delayed",&p,CHAT_MSG_WHISPER,time(nullptr)+5000));
 ai.chatCommands.push(ChatCommandHolder("immediate",&p));
 Event::InvalidateOwner(&p); // Native logout/reclaim precedes any pointer reuse.
 ai.HandleCommands();if(!ai.chatCommands.empty()||parsedCommands)fail=true;
 Event fresh("chat",std::string("follow"),&p); // Deliberately reuse the same address and GUID.
 if(fresh.HasExpiredOwner()||fresh.GetOwner()!=&p||!original.HasExpiredOwner()||!copy.HasExpiredOwner()||!assigned.HasExpiredOwner()||!packets.Check().HasExpiredOwner()||!chat.Check().HasExpiredOwner()||!forced.Check().HasExpiredOwner())fail=true;
 if(engine.ListenAndExecute(&action,original)||reaction.ListenAndExecute(&action,copy)||executed)fail=true;
 if(!engine.ListenAndExecute(&action,fresh)||executed!=1)fail=true;
 ai.chatCommands.push(ChatCommandHolder("current",&p));ai.HandleCommands();if(parsedCommands!=1||!ai.chatCommands.empty())fail=true;
 Event automatic("combat");if(automatic.HasExpiredOwner()||!engine.ListenAndExecute(&action,automatic))fail=true;
 packets.Reset();chat.Reset();if(!(!packets.Check())||!(!chat.Check()))fail=true;
 std::atomic<bool> concurrentFail=false;std::vector<std::thread>workers;
 for(unsigned n=0;n<8;++n)workers.emplace_back([&]{for(unsigned k=0;k<100;++k){Event event("test",std::string("x"),&p);Event::InvalidateOwner(&p);if(!event.HasExpiredOwner())concurrentFail=true;}});
 for(auto& worker:workers)worker.join();
 Event::InvalidateOwner(&p);if(!ai::eventOwners.empty()||concurrentFail)fail=true;
 players.clear();if(fresh.GetOwner()!=nullptr||!fresh.HasExpiredOwner())fail=true;
 if(fail){std::cerr<<"Native event owner lifetime/trigger/execution gate failed\n";return 1;}
 std::cout<<"Native event snapshots revoke copied/queued/reaction owners, including GUID/address reuse; automatic events survive\n";
}
