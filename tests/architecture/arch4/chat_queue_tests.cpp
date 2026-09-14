#include <barrier>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
struct Bot;
struct ChatQueuedReply { int m_type=0,m_guid1=0,m_guid2=0;std::string m_msg,m_chanName,m_name;time_t m_time=0; };
struct ChatReplyAction { static void ChatReplyDo(Bot*,int,int,int,std::string,std::string,std::string); };
struct Bot {
    std::mutex chatRepliesMutex;
    std::queue<ChatQueuedReply> chatReplies;
    std::vector<std::string> sent;
    Bot* other=nullptr;
    void Enqueue(ChatQueuedReply reply){std::scoped_lock lock(chatRepliesMutex);chatReplies.push(std::move(reply));}
    void Update(){Bot* bot=this;
#include "chat_queue_block.inc"
    }
};
std::barrier rendezvous(2);
bool simultaneous=false;
void ChatReplyAction::ChatReplyDo(Bot* bot,int,int,int,std::string msg,std::string,std::string){
    bot->sent.push_back(msg);
    if(simultaneous){rendezvous.arrive_and_wait();bot->other->Enqueue({0,0,0,"callback","","",time(0)+300});}
}
void require(bool ok){if(!ok)std::abort();}
int main(){
    Bot a,b;
    a.Enqueue({0,0,0,"future1","","",time(0)+300});
    a.Enqueue({0,0,0,"due1","","",0});
    a.Enqueue({0,0,0,"future2","","",time(0)+300});
    a.Enqueue({0,0,0,"due2","","",0});
    a.Update();require((a.sent==std::vector<std::string>{"due1","due2"}));
    require(a.chatReplies.size()==2 && a.chatReplies.front().m_msg=="future1");
    a.chatReplies.pop();require(a.chatReplies.front().m_msg=="future2");a.chatReplies.pop();
    a.sent.clear();a.other=&b;b.other=&a;
    a.Enqueue({0,0,0,"from a","","",0});b.Enqueue({0,0,0,"from b","","",0});
    simultaneous=true;
    std::thread first([&]{a.Update();}),second([&]{b.Update();});first.join();second.join();
    require(a.sent.size()==1 && b.sent.size()==1 && a.chatReplies.size()==1 && b.chatReplies.size()==1);
    std::cout<<"Due/future ordering and simultaneous reciprocal delivery passed\n";
}
