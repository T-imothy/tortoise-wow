#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
using uint32=std::uint32_t;
struct ObjectGuid{uint32 value;std::string GetString()const{return std::to_string(value);}};
struct Player{bool inWorld=true,teleporting=false;bool IsInWorld()const{return inWorld;}bool IsBeingTeleported()const{return teleporting;}};
class WorldSession;
struct WorldSessionFilter{explicit WorldSessionFilter(WorldSession*){}};
class WorldSession{public:Player*player;bool loading=false,keep=true;uint32 updates=0;std::function<void()> onUpdate;
    Player*GetPlayer(){return player;}bool PlayerLoading(){return loading;}void AddActiveTime(uint32){}
    bool Update(WorldSessionFilter&){++updates;if(onUpdate)onUpdate();return keep;}
};
struct Log{template<class...T>void outError(char const*,T...){}}sLog;
struct HeadlessSessionMgr{
    struct SessionEntry{WorldSession*session;ObjectGuid characterGuid;uint32 outOfWorldElapsed=0;};
    std::map<uint32,SessionEntry>m_sessions;std::vector<uint32>removed;
    void Update(uint32);
    void DestroySession(SessionEntry&e,bool save,bool clear){if(!save||!clear||m_sessions.count(e.characterGuid.value))std::abort();removed.push_back(e.characterGuid.value);}
};
#include "NativeHeadlessStranded.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){
    HeadlessSessionMgr mgr;Player p;WorldSession session;session.player=&p;
    auto add=[&]{mgr.m_sessions[1]={&session,{1},0};mgr.removed.clear();};add();
    p.inWorld=false;mgr.Update(4999);Check(mgr.removed.empty(),"grace period retains transient gap");mgr.Update(1);Check(mgr.removed==std::vector<uint32>({1}),"five second deadline uses normal native teardown");
    add();p.inWorld=true;mgr.Update(10000);Check(mgr.removed.empty(),"in-world player retained");
    p.inWorld=false;mgr.Update(4000);p.teleporting=true;mgr.Update(10000);p.teleporting=false;mgr.Update(1000);Check(mgr.removed.empty()&&mgr.m_sessions.at(1).outOfWorldElapsed==1000,"teleport resets stale grace time");
    session.loading=true;mgr.Update(10000);session.loading=false;mgr.Update(4000);Check(mgr.removed.empty(),"loading resets grace period");
    session.onUpdate=[&]{p.inWorld=true;};mgr.Update(1000);Check(mgr.removed.empty()&&mgr.m_sessions.at(1).outOfWorldElapsed==0,"native packet recovery is observed before expiry");session.onUpdate={};
    p.inWorld=false;mgr.Update(std::numeric_limits<uint32>::max());Check(mgr.removed.size()==1,"large diff saturates instead of wrapping");
    add();session.player=nullptr;mgr.Update(1);Check(mgr.removed.size()==1,"missing player uses existing immediate teardown");
    add();session.loading=true;mgr.Update(10000);Check(mgr.removed.empty(),"login without materialized player retained");session.loading=false;session.player=&p;
    session.keep=false;mgr.Update(1);Check(mgr.removed.size()==1,"session stop request still wins immediately");
    std::cout<<"Native Headless stranded deadline, loading, teleport, packet recovery and teardown checks passed\n";
}
