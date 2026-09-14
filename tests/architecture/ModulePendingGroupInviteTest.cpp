#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
struct Group{unsigned leader=2;unsigned GetLeaderGuid(){return leader;}};
struct Player{Group*invite=nullptr;Group*GetGroupInvite(){return invite;}unsigned GetObjectGuid(){return 1;}};
struct PlayerbotAI{Player*bot;};
struct Event{std::string source;Event(std::string s=""):source(s){}std::string getSource(){return source;}explicit operator bool()const{return !source.empty();}};
namespace ai {
class Trigger{public:Trigger(PlayerbotAI*a,std::string n):bot(a->bot),name(n){}virtual ~Trigger()=default;virtual bool IsActive(){return false;}Event Check();void Reset(){triggered=false;externalEvent=Event();}std::string getName(){return name;}protected:Player*bot;std::string name;bool triggered=false;Event externalEvent;};
#include "ModulePendingGroupInviteCheck.inc"
}
#include "ModulePendingGroupInviteType.inc"
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){Player bot;PlayerbotAI ai{&bot};Group first,second;auto trigger=std::make_unique<ai::GroupInvitationTrigger>(&ai);
 Check(!trigger->Check(),"no native invite means no action");bot.invite=&first;
 Check(bool(trigger->Check()),"native invite triggers without relying on packet arrival");
 trigger->Reset();trigger=std::make_unique<ai::GroupInvitationTrigger>(&ai);
 Check(bool(trigger->Check()),"class strategy rebuild cannot lose the still-pending invitation");
 for(int i=0;i<4;++i){trigger->Reset();Check(bool(trigger->Check()),"deferred or discarded decisions retain native intent");}
 bot.invite=nullptr;trigger->Reset();Check(!trigger->Check(),"native accept/decline/cancel ends retries");
 bot.invite=&second;trigger->Reset();Check(bool(trigger->Check()),"new leader invitation uses current native state");
 second.leader=bot.GetObjectGuid();trigger->Reset();Check(!trigger->Check(),"native group leader cannot try accepting their own pending group");
 bot.invite=nullptr;trigger=std::make_unique<ai::GroupInvitationTrigger>(&ai);Check(!trigger->Check(),"canceled invitation cannot revive across graph rebuild");
 std::cout<<"Native pending invitations survive strategy rebuild and end with core cancellation\n";
}
