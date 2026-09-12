#include <map>
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <cstdlib>
using uint32=std::uint32_t;using ObjectGuid=uint32;
#define CHECK(x) do {if(!(x)){std::cerr<<__LINE__<<": " #x<<'\n';std::exit(1);}}while(0)
std::vector<std::string> events; bool aiAttached=true;
class WorldSession;
struct Player {WorldSession* session=nullptr;void SetSession(WorldSession*s){events.push_back("attach");session=s;}};
struct MasterPlayer {void SetSession(WorldSession*){events.push_back("master");}};
enum class SessionTransport {Headless,Network};
class WorldSession {public:Player* player=nullptr;MasterPlayer* master=nullptr;SessionTransport transport=SessionTransport::Headless;bool tracked=false;
    ~WorldSession(){if(tracked){CHECK(!aiAttached);CHECK(player==nullptr);events.push_back("delete");}}
    Player* GetPlayer(){return player;}MasterPlayer* GetMasterPlayer(){return master;}
    SessionTransport GetTransport(){return transport;}void SetMasterPlayer(MasterPlayer*m){master=m;}
    void SetPlayer(Player*p){player=p;events.push_back("detach");}
};
constexpr int PLAYERHOOK_ON_RELEASE_TO_CLIENT=1;
class PlayerScript {public:void OnReleaseToClient(Player*p){CHECK(p&&p->session&&p->session->transport==SessionTransport::Headless);CHECK(aiAttached);aiAttached=false;events.push_back("release");}};
template<class T>struct ScriptRegistry{template<class F>static void ForEachEnabledHook(int hook,F f){CHECK(hook==PLAYERHOOK_ON_RELEASE_TO_CLIENT);T script;f(&script);}};
class HeadlessSessionMgr {public:struct SessionEntry{WorldSession*session;uint32 accountId;};std::map<ObjectGuid,SessionEntry> m_sessions;
    bool ReclaimForNetwork(ObjectGuid,WorldSession*,WorldSession*,uint32);};
#include "NativeHeadlessReclaim.inc"
int main()
{
    HeadlessSessionMgr mgr;Player player;MasterPlayer master;WorldSession replacement,wrong;
    replacement.transport=SessionTransport::Network;
    auto* old=new WorldSession;old->player=&player;old->master=&master;old->tracked=true;player.session=old;
    mgr.m_sessions[7]={old,3};
    CHECK(!mgr.ReclaimForNetwork(8,old,&replacement,3));
    CHECK(!mgr.ReclaimForNetwork(7,nullptr,&replacement,3));
    CHECK(!mgr.ReclaimForNetwork(7,old,nullptr,3));
    CHECK(!mgr.ReclaimForNetwork(7,old,old,3));
    CHECK(!mgr.ReclaimForNetwork(7,&wrong,&replacement,3));
    CHECK(!mgr.ReclaimForNetwork(7,old,&replacement,4));
    old->transport=SessionTransport::Network;CHECK(!mgr.ReclaimForNetwork(7,old,&replacement,3));old->transport=SessionTransport::Headless;
    old->player=nullptr;CHECK(!mgr.ReclaimForNetwork(7,old,&replacement,3));old->player=&player;
    CHECK(events.empty()&&aiAttached&&mgr.m_sessions.size()==1);
    CHECK(mgr.ReclaimForNetwork(7,old,&replacement,3));
    CHECK((events==std::vector<std::string>{"release","master","attach","detach","delete"}));
    CHECK(player.session==&replacement&&!aiAttached&&mgr.m_sessions.empty());
    CHECK(!mgr.ReclaimForNetwork(7,nullptr,&replacement,3));
    std::cout<<"Native headless reclaim validation and AI-release-before-session-transfer ordering passed\n";
}
