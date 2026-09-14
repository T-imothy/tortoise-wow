#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <ctime>
using uint32=unsigned;
constexpr int HIGHGUID_PLAYER=0,MAIL_STATE_DELETED=1,MAIL_STATIONERY_AUCTION=62,MAIL_NORMAL=0,CMSG_MAIL_RETURN_TO_SENDER=1;
struct ObjectGuid{unsigned value=0;ObjectGuid()=default;ObjectGuid(unsigned n):value(n){}ObjectGuid(int,unsigned n):value(n){}explicit operator bool()const{return value!=0;}};
struct WorldPacket{std::vector<unsigned>fields;WorldPacket(int){}WorldPacket&operator<<(ObjectGuid g){fields.push_back(g.value);return *this;}WorldPacket&operator<<(unsigned n){fields.push_back(n);return *this;}};
struct Mail{unsigned messageID,sender=2;int state=0,stationery=0,messageType=0;time_t deliver_time=0;std::vector<int>items={101,102};std::string subject="mistake";};
struct MasterPlayer{std::list<Mail*>mails;auto GetMailBegin(){return mails.begin();}auto GetMailEnd(){return mails.end();}unsigned GetMailSize(){return unsigned(mails.size());}Mail*GetMail(unsigned id){for(auto*m:mails)if(m->messageID==id)return m;return nullptr;}void Remove(unsigned id){for(auto i=mails.begin();i!=mails.end();++i)if((*i)->messageID==id){delete *i;mails.erase(i);return;}}~MasterPlayer(){for(auto*m:mails)delete m;}};
struct Session{MasterPlayer owner;bool allow=true;std::vector<unsigned>called;MasterPlayer*GetMasterPlayer(){return &owner;}void HandleMailReturnToSender(WorldPacket&p){called.push_back(p.fields.at(1));if(allow&&p.fields.at(0)==77)owner.Remove(p.fields.at(1));}};
struct Player{Session session;unsigned guid=2;bool hardcore=false,alive=true,world=true,teleport=false,combat=false,bg=false;Session*GetSession(){return &session;}ObjectGuid GetObjectGuid(){return guid;}bool IsHardcore(){return hardcore;}bool IsAlive(){return alive;}bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}bool IsInCombat(){return combat;}bool InBattleGround(){return bg;}};
struct PlayerbotAI{Player*master=nullptr;Player*GetMaster(){return master;}};
struct ObjectMgr{Player*sender=nullptr;Player*GetPlayer(ObjectGuid g){return sender&&sender->guid==g.value?sender:nullptr;}unsigned GetPlayerAccountIdByGUID(ObjectGuid g){return g.value;}}sObjectMgr;
struct Config{bool random=false;bool IsInRandomAccountList(unsigned){return random;}}sPlayerbotAIConfig;
struct Event{};
namespace TortoiseBots{struct BotWorldActions{inline static bool map=false;static BotWorldActions&Instance(){static BotWorldActions x;return x;}std::optional<bool>Defer(Player*,std::string const&,Event&){return map?std::optional<bool>(false):std::nullopt;}};}
struct MailProcessor{inline static unsigned mailbox=77;static ObjectGuid FindMailbox(PlayerbotAI*){return mailbox;}};
struct CheckMailAction{Player*bot;PlayerbotAI*ai;std::string getName(){return "check mail";}bool Execute(Event&);bool isUseful();};
#include "ModuleAutomaticMailReturn.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player bot,sender;PlayerbotAI ai;sObjectMgr.sender=&sender;CheckMailAction action{&bot,&ai};Event event;auto&owner=bot.session.owner;
 auto add=[&](unsigned id){auto*m=new Mail;m->messageID=id;owner.mails.push_back(m);return m;};
 add(1);add(2)->stationery=MAIL_STATIONERY_AUCTION;add(3)->messageType=1;add(4)->subject="Item(s) you asked for";add(5)->deliver_time=time(nullptr)+3600;add(6)->items.clear();add(7)->state=MAIL_STATE_DELETED;add(8)->sender=99;
 TortoiseBots::BotWorldActions::map=true;CHECK(!action.Execute(event)&&bot.session.called.empty());TortoiseBots::BotWorldActions::map=false;
 MailProcessor::mailbox=0;CHECK(!action.Execute(event));MailProcessor::mailbox=77;
 sender.hardcore=true;CHECK(!action.Execute(event));sender.hardcore=false;sPlayerbotAIConfig.random=true;CHECK(!action.Execute(event));sPlayerbotAIConfig.random=false;
 ai.master=&sender;CHECK(!action.Execute(event));ai.master=nullptr;bot.combat=true;CHECK(!action.Execute(event));bot.combat=false;
 bot.session.allow=false;CHECK(!action.Execute(event)&&owner.GetMail(1)&&bot.session.called.size()==1);bot.session.allow=true;
 CHECK(action.Execute(event)&&!owner.GetMail(1)&&owner.GetMailSize()==7&&bot.session.called.size()==2);
 for(unsigned id=10;id<20;++id)add(id);CHECK(action.Execute(event));CHECK(!owner.GetMail(17)&&owner.GetMail(18)&&owner.GetMail(19));CHECK(action.Execute(event)&&!owner.GetMail(18)&&!owner.GetMail(19));
 CHECK(!action.Execute(event)&&owner.GetMailSize()==7);
 std::cout<<"Automatic mail return passed: native mailbox and result, deleted-object lifetime, bounded progress, auction/requested/future/hardcore/random preservation\n";
}
