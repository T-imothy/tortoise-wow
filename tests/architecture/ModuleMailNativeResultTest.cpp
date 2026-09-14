#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using uint32=unsigned;using ObjectGuid=unsigned;
struct Item{unsigned count=1;unsigned GetCount(){return count;}};
struct Attachment{unsigned item_guid;};
struct Mail{unsigned messageID=1,money=0;std::string subject="fixture";std::vector<Attachment> items;};
struct MasterPlayer{Mail mail;bool present=true;std::map<unsigned,std::unique_ptr<Item>> inventory;Mail*GetMail(unsigned){return present?&mail:nullptr;}Item*GetMItem(unsigned guid){auto i=inventory.find(guid);return i==inventory.end()?nullptr:i->second.get();}};
struct WorldPacket{std::vector<unsigned> values;WorldPacket&operator<<(unsigned v){values.push_back(v);return *this;}};
struct Session{MasterPlayer*owner;bool moneyAccepted=true,itemAccepted=true;unsigned moneyCalls=0,itemCalls=0;
 void HandleMailTakeMoney(WorldPacket&p){++moneyCalls;if(p.values.size()!=2)throw 1;if(moneyAccepted)owner->mail.money=0;}
 void HandleMailTakeItem(WorldPacket&p){++itemCalls;if(p.values.size()!=2)throw 1;if(itemAccepted){auto guid=owner->mail.items.front().item_guid;owner->inventory.erase(guid);owner->mail.items.erase(owner->mail.items.begin());}}
};
struct Player{MasterPlayer owner;Session session{&owner};bool bags=true;Session*GetSession(){return &session;}};
MasterPlayer*GetMailOwner(Player*p){return p?&p->owner:nullptr;}
enum class PlayerbotSecurityLevel{PLAYERBOT_SECURITY_ALLOW_ALL};
struct PlayerbotAI{Player*bot;bool master=false;std::vector<std::string> messages;Player*GetBot(){return bot;}bool HasActivePlayerMaster(){return master;}template<class...T>void TellPlayer(Player*,std::string text,T...){messages.push_back(text);}void TellError(Player*,std::string text){messages.push_back(text);}};
struct Event{std::string source="rpg action";auto GetSource(){return source;}};
struct ChatHelper{static std::string formatMoney(unsigned n){return std::to_string(n);}static std::string formatItem(Item*i,unsigned n){if(!i)throw 2;return "item "+std::to_string(n);}};
struct MailProcessor{virtual bool After(Player*,PlayerbotAI*){return true;}virtual bool Process(Player*,int,Mail*,PlayerbotAI*,Event&)=0;unsigned deleted=0;unsigned FindMailbox(PlayerbotAI*){return 9;}void RemoveMail(Player*p,unsigned,unsigned){++deleted;p->owner.present=false;}};
struct TakeMailProcessor:MailProcessor{unsigned copper=0;std::vector<std::string> items;bool CheckBagSpace(Player*p){return p->bags;}
#include "ModuleMailCollect.inc"
};
bool Dispatch(MailProcessor*processor,Player*requester,PlayerbotAI*ai,Event&event,std::map<int,Mail*> filtered){
#include "ModuleMailDispatchResult.inc"
struct RejectProcessor:MailProcessor{unsigned count=0,after=0,allow=0;bool Process(Player*,int,Mail*,PlayerbotAI*,Event&)override{return count++<allow;}bool After(Player*,PlayerbotAI*)override{++after;return true;}};
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player p;PlayerbotAI ai{&p};TakeMailProcessor take;Event event;auto&mail=p.owner.mail;
 mail.money=75;p.session.moneyAccepted=false;CHECK(!take.Process(&p,0,&mail,&ai,event));CHECK(take.copper==0&&take.deleted==0&&ai.messages.empty());
 p.session.moneyAccepted=true;p.bags=false;CHECK(take.Process(&p,0,&mail,&ai,event));CHECK(take.copper==75&&take.deleted==1); // money needs no bag space
 p.owner.present=true;p.bags=true;mail.items={{10},{11}};p.owner.inventory[10]=std::make_unique<Item>();p.owner.inventory[11]=std::make_unique<Item>();p.session.itemAccepted=false;
 CHECK(!take.Process(&p,0,&mail,&ai,event));CHECK(p.session.itemCalls==1&&take.items.empty()&&mail.items.size()==2&&take.deleted==1);
 p.session.itemAccepted=true;CHECK(take.Process(&p,0,&mail,&ai,event));CHECK(take.items.size()==2&&p.owner.inventory.empty()&&p.session.itemCalls==3&&take.deleted==2);
 p.owner.present=true;mail.money=100;p.session.moneyAccepted=false;event.source="chat";CHECK(!take.Process(&p,0,&mail,&ai,event));CHECK(ai.messages.empty());
 p.session.moneyAccepted=true;ai.master=true;CHECK(take.Process(&p,0,&mail,&ai,event));CHECK(ai.messages.size()==1&&take.deleted==2&&p.owner.present);
 mail.items={{12}};p.owner.inventory[12]=std::make_unique<Item>();p.session.itemAccepted=false;CHECK(!take.Process(&p,0,&mail,&ai,event));CHECK(ai.messages.size()==1);
 p.session.itemAccepted=true;CHECK(take.Process(&p,0,&mail,&ai,event));CHECK(ai.messages.size()==2&&p.owner.inventory.empty());
 RejectProcessor rejected;CHECK(!Dispatch(&rejected,&p,&ai,event,{{1,&mail}})&&rejected.after==1);
 RejectProcessor partial;partial.allow=1;CHECK(Dispatch(&partial,&p,&ai,event,{{1,&mail},{2,&mail}})&&partial.count==2&&partial.after==1);
 RejectProcessor empty;CHECK(!Dispatch(&empty,&p,&ai,event,{})&&empty.after==1);
 std::cout<<"Native mail rejection, attachment order, post-merge lifetime, money-only collection and reporting passed\n";
}
