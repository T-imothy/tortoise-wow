#include <cstdint>
#include <type_traits>
#include <utility>
#include <functional>
#include <future>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <unordered_map>
using ObjectGuid=std::uint64_t;
struct Player {ObjectGuid guid=7;bool fieldsReady=false;ObjectGuid GetObjectGuid()const {if(!fieldsReady){std::cerr<<"GUID accessed outside initialized lifetime\n";std::exit(1);}return guid;}};
struct WorldPacket {};
struct PlayerbotAI {
    int calls[3]={};std::function<void()> onEnqueue;
    void HandleBotOutgoingPacket(WorldPacket const&){++calls[0];if(onEnqueue)onEnqueue();}
    void HandleMasterIncomingPacket(WorldPacket const&){++calls[1];}
    void HandleMasterOutgoingPacket(WorldPacket const&){++calls[2];}
};
class PlayerbotAIStorage {
public:static PlayerbotAIStorage&Instance();void SetAI(Player*,PlayerbotAI*);void RemoveAI(Player*);
#include "ModuleAIIdentityLookup.inc"

public:
enum class PacketDirection { BotOutgoing, MasterIncoming, MasterOutgoing };
void QueuePacket(Player*,WorldPacket const&,PacketDirection);
private:mutable std::mutex mutex_;std::unordered_map<ObjectGuid,PlayerbotAI*>byGuid_;std::unordered_map<Player*,PlayerbotAI*>byPlayer_;
};
template<class T,class=void>struct CanLookupAI:std::false_type{};
template<class T>struct CanLookupAI<T,std::void_t<decltype(std::declval<PlayerbotAIStorage const&>().GetAI(std::declval<T>()))>>:std::true_type{};
static_assert(CanLookupAI<Player*>::value&&CanLookupAI<ObjectGuid>::value);
static_assert(!CanLookupAI<bool>::value,"Boolean predicates must not become GUID lookups");
#include "ModuleAIIdentity.inc"
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){auto&s=PlayerbotAIStorage::Instance();Player p;PlayerbotAI a;
Check(!s.GetAI(&p)&&!s.GetAI(static_cast<Player*>(nullptr)),"constructing player has no AI");
p.fieldsReady=true;s.SetAI(&p,&a);Check(s.GetAI(&p)==&a&&s.GetAI(ObjectGuid(7))==&a,"both explicit indexes resolve");
Player replacement;replacement.fieldsReady=true;Check(!s.GetAI(&replacement),"same GUID in new player lifetime cannot inherit old AI");
p.fieldsReady=false;s.RemoveAI(&p);Check(!s.GetAI(&p)&&!s.GetAI(ObjectGuid(7)),"release requires no player dereference");s.RemoveAI(&p);
p.fieldsReady=true;s.SetAI(&p,&a);s.SetAI(&p,nullptr);Check(!s.GetAI(&p)&&!s.GetAI(ObjectGuid(7)),"clear removes both indexes");
using Direction=PlayerbotAIStorage::PacketDirection;
s.SetAI(&p,&a); WorldPacket packet;
s.QueuePacket(&p,packet,Direction::BotOutgoing);s.QueuePacket(&p,packet,Direction::MasterIncoming);s.QueuePacket(&p,packet,Direction::MasterOutgoing);
Check(a.calls[0]==1&&a.calls[1]==1&&a.calls[2]==1,"all packet directions enqueue through live registration");
std::promise<void> entered,release,removing;
auto releaseFuture=release.get_future();
a.onEnqueue=[&]{entered.set_value();releaseFuture.wait();};
auto producer=std::async(std::launch::async,[&]{s.QueuePacket(&p,packet,Direction::BotOutgoing);});
entered.get_future().wait();
auto remover=std::async(std::launch::async,[&]{removing.set_value();s.RemoveAI(&p);});
removing.get_future().wait();
Check(remover.wait_for(std::chrono::milliseconds(30))==std::future_status::timeout,"AI removal waits for active enqueue");
release.set_value();producer.get();remover.get();
s.QueuePacket(&p,packet,Direction::BotOutgoing);
Check(a.calls[0]==2,"removed AI receives no new packet");
PlayerbotAI newAi;s.SetAI(&p,&newAi);s.QueuePacket(&p,packet,Direction::BotOutgoing);
Check(a.calls[0]==2&&newAi.calls[0]==1,"reused player address dispatches only to newly published AI");s.RemoveAI(&p);
std::cout<<"Module AI identity and packet/removal lifetime checks passed\n";}
