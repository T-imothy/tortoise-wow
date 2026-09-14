#include <ctime>
#include <iostream>
time_t now=100;
time_t TestNow(time_t*){return now;}
#define time TestNow
struct WorldTimer{static unsigned getMSTime(){return 123;}};
struct PacketFilter{bool world=true;bool ProcessLogout(){return world;}};
struct Player{bool stunned=false;};
struct Session{time_t _logoutTime=0;bool m_playerLoading=false,m_headlessLoginRequested=true,headless=true;unsigned m_lastUpdateTime=0;Player*_player=nullptr;bool IsHeadless(){return headless;}bool isLogingOut(){return _logoutTime!=0;}
#include "NativeLogoutDeadline.inc"
bool Update(PacketFilter&updater){
#include "NativeHeadlessLogoutUpdate.inc"
 return true;
}};
struct Bot{Session*session;bool stunned=true;Session*GetSession(){return session;}};
struct Config{unsigned reactDelay=100;}sPlayerbotAIConfig;
struct AI{Bot*bot;unsigned work=0,delay=0;void SetAIInternalUpdateDelay(unsigned n){delay=n;}void Update(){
#include "ModuleLogoutPause.inc"
 ++work;
}};
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player p{true};Session session;session._player=&p;PacketFilter filter;Bot bot{&session};AI ai{&bot};
 CHECK(session.Update(filter));ai.Update();CHECK(ai.work==1&&!ai.delay); // an ordinary stun is not a logout request
 session._logoutTime=now;CHECK(session.Update(filter));ai.Update();CHECK(ai.work==1&&ai.delay==100);
 now=119;CHECK(session.Update(filter));now=120;CHECK(!session.Update(filter));
 filter.world=false;CHECK(session.Update(filter));filter.world=true;session.m_playerLoading=true;CHECK(session.Update(filter));session.m_playerLoading=false;
 session._logoutTime=0;CHECK(session.Update(filter));ai.Update();CHECK(ai.work==2);
 session._player=nullptr;CHECK(!session.Update(filter));session.m_playerLoading=true;CHECK(session.Update(filter));session.m_playerLoading=false;session.m_headlessLoginRequested=false;CHECK(session.Update(filter));
 std::cout<<"Native headless logout honors request/deadline/loading/world ownership; combat stuns continue AI without teardown\n";
}
