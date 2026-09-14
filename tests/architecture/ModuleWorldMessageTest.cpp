#include <cstdlib>
#include <iostream>
#include <functional>
#include <memory>
#include <string>
#include <vector>
struct Player{std::shared_ptr<int> life=std::make_shared<int>(0);};
struct Event{Player*p;std::weak_ptr<int>life;Event(std::string,std::string,Player*x):p(x),life(x->life){}Player*getOwner(){return life.expired()?nullptr:p;}};
enum class PlayerbotSecurityLevel{Talk,Full};
struct PlayerbotAI;
namespace TortoiseBots {struct BotWorldActions{static inline bool map=false,accept=true;static inline std::vector<std::function<void(PlayerbotAI&)>>queue;static bool IsMapExecution(){return map;}static BotWorldActions&Instance(){static BotWorldActions a;return a;}bool EnqueueContinuation(Player*,std::string const&,Event const&,std::function<void(PlayerbotAI&)>f){if(!accept)return false;queue.push_back(std::move(f));return true;}};}
struct PlayerbotAI{Player*bot=nullptr,*recipient=nullptr;unsigned delivered=0;std::string message;PlayerbotSecurityLevel security=PlayerbotSecurityLevel::Talk;bool privacy=false,repeat=false,silent=false,facing=false;
 bool TellPlayerNoFacing(Player*,std::string,PlayerbotSecurityLevel,bool,bool,bool);
 bool TellPlayer(Player*,std::string,PlayerbotSecurityLevel,bool,bool);
 bool Delivered(Player*p,std::string text,PlayerbotSecurityLevel level,bool priv,bool noRepeat,bool ignoreSilent,bool face){++delivered;recipient=p;message=text;security=level;privacy=priv;repeat=noRepeat;silent=ignoreSilent;facing=face;return true;}
};
#include "ModuleWorldMessageNoFacing.inc"
 return Delivered(player,text,securityLevel,isPrivate,noRepeat,ignoreSilent,false);
}
#include "ModuleWorldMessageFacing.inc"
 return Delivered(player,text,securityLevel,isPrivate,true,ignoreSilent,true);
}
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){using Q=TortoiseBots::BotWorldActions;Player bot,recipient;PlayerbotAI ai;ai.bot=&bot;Q::map=true;
 Check(!ai.TellPlayerNoFacing(&recipient,"copied text",PlayerbotSecurityLevel::Full,true,false,true)&&!ai.delivered&&Q::queue.size()==1,"map admission cannot deliver or claim completion");
 Q::map=false;Q::queue.front()(ai);Q::queue.clear();Check(ai.delivered==1&&ai.message=="copied text"&&ai.security==PlayerbotSecurityLevel::Full&&ai.privacy&&!ai.repeat&&ai.silent&&!ai.facing,"world delivery preserves every option");
 Q::map=true;Check(!ai.TellPlayer(&recipient,"face",PlayerbotSecurityLevel::Talk,false,true),"facing reply deferred");Q::map=false;Q::queue.front()(ai);Q::queue.clear();Check(ai.delivered==2&&ai.facing&&ai.repeat&&ai.silent&&!ai.privacy,"facing and ignoreSilent retained");
 Q::map=true;ai.TellPlayer(&recipient,"expired",PlayerbotSecurityLevel::Talk,false,false);recipient.life.reset();Q::map=false;Q::queue.front()(ai);Q::queue.clear();Check(ai.delivered==2,"recipient logout invalidates queued reply");
 Q::map=true;Q::accept=false;Check(!ai.TellPlayer(&recipient,"rejected",PlayerbotSecurityLevel::Talk,false,false)&&Q::queue.empty(),"full world queue must not claim delivery");Check(!ai.TellPlayer(nullptr,"null",PlayerbotSecurityLevel::Talk,false,false)&&Q::queue.empty(),"null recipient not enqueued");
 std::cout<<"World reply ownership, options, recipient lifetime and rejection passed\n";
}
