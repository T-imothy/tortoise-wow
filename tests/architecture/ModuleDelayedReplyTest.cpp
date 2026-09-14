#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>
using uint32=std::uint32_t;
enum { CMSG_MESSAGECHAT=1, CHAT_MSG_CHANNEL=2, CHAT_MSG_WHISPER=3, CHAT_MSG_SAY=4 };
struct ByteBufferException {};
struct WorldPacket {
    int opcode=9,id=0;std::vector<std::string> fields;size_t cursor=0;
    int GetOpcode()const{return opcode;}
    size_t rpos()const{return cursor;}void rpos(size_t p){cursor=p;}
    WorldPacket&operator>>(std::string&s){if(cursor>=fields.size())throw ByteBufferException{};s=fields[cursor++];return *this;}
    WorldPacket&operator>>(uint32&n){std::string s;*this>>s;n=static_cast<uint32>(std::stoul(s));return *this;}
};
using futurePackets=std::future<std::vector<std::pair<WorldPacket,uint32>>>;
struct WorldSession {
    bool headless=true;std::vector<WorldPacket> received;
    bool IsHeadless()const{return headless;}
    void QueuePacket(WorldPacket*p){std::unique_ptr<WorldPacket> owner(p);received.push_back(*p);}
};
struct Player {bool inWorld=true;WorldSession session;bool IsInWorld()const{return inWorld;}WorldSession*GetSession(){return &session;}};
class PlayerbotAI;
struct PlayerbotAIStorage {
    PlayerbotAI* ai=nullptr;
    static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}
    PlayerbotAI*GetAI(Player*)const{return ai;}
};
struct Log {void outError(char const*){}}sLog;
bool IsCommandLikeChat(std::string const&s){return !s.empty()&&(s[0]=='.'||s[0]=='!');}
class PlayerbotAI {
public:
    Player*bot;
    #include "ModuleDelayedMailboxTypes.inc"
    void SendDelayedPacket(futurePackets);
    void ProcessDelayedPackets();
};
#include "ModuleDelayedReplyMethods.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
template<class F>void WaitUntil(F condition){auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);while(!condition()){Check(std::chrono::steady_clock::now()<deadline,"async publication timed out");std::this_thread::sleep_for(std::chrono::milliseconds(1));}}
size_t Pending(PlayerbotAI&ai){std::lock_guard<std::mutex>lock(ai.delayedPacketMailbox->mutex);return ai.delayedPacketMailbox->packets.size();}
int main(){
    Player bot;auto ai=std::make_unique<PlayerbotAI>();ai->bot=&bot;PlayerbotAIStorage::Instance().ai=ai.get();
    std::promise<std::vector<std::pair<WorldPacket,uint32>>> replies;
    ai->SendDelayedPacket(replies.get_future());
    replies.set_value({{{9,1,{}},0},{{9,2,{}},0}});
    WaitUntil([&]{return Pending(*ai)==2;});
    Check(bot.session.received.empty(),"worker never queues directly to WorldSession");
    ai->ProcessDelayedPackets();Check(bot.session.received.size()==2&&bot.session.received[0].id==1&&bot.session.received[1].id==2,"owner dispatch preserves reply sequence");
    std::promise<std::vector<std::pair<WorldPacket,uint32>>> slow;
    ai->SendDelayedPacket(slow.get_future());
    std::weak_ptr<PlayerbotAI::DelayedPacketMailbox> oldMailbox=ai->delayedPacketMailbox;
    ai.reset();Check(oldMailbox.expired(),"blocked worker cannot keep AI mailbox alive");
    ai=std::make_unique<PlayerbotAI>();ai->bot=&bot;PlayerbotAIStorage::Instance().ai=ai.get();
    slow.set_value({{{9,99,{}},0}});
    // Reused Player and session addresses cannot recover an expired mailbox.
    Check(oldMailbox.expired()&&Pending(*ai)==0,"old login response cannot reach replacement AI");
    auto add=[&](WorldPacket packet){ai->delayedPacketMailbox->packets.push_back(std::make_unique<WorldPacket>(std::move(packet)));};
    add({CMSG_MESSAGECHAT,10,{"4","0","hello"}});
    add({CMSG_MESSAGECHAT,11,{"3","0","friend",".server exit"}});
    add({CMSG_MESSAGECHAT,12,{"2","0","world","!command"}});
    add({CMSG_MESSAGECHAT,13,{"4"}});
    ai->ProcessDelayedPackets();Check(bot.session.received.size()==3&&bot.session.received.back().id==10&&bot.session.received.back().rpos()==0,"chat filtering rejects commands/malformed payload and restores read cursor");
    add({9,14,{}});bot.session.headless=false;ai->ProcessDelayedPackets();Check(bot.session.received.size()==3,"human reclaim rejects queued replies");bot.session.headless=true;
    add({9,15,{}});PlayerbotAIStorage::Instance().ai=nullptr;ai->ProcessDelayedPackets();Check(bot.session.received.size()==3,"unpublished AI cannot dispatch queued replies");
    std::cout<<"Delayed reply lifetime, owner delivery, reclaim and command filtering checks passed\n";
}
