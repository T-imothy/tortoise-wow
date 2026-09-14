
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using uint32=std::uint32_t;using int32=std::int32_t;
enum ChatReplyType {ReplyHello=1,ReplyBye=2};
struct BotTextEntry {uint32 m_replyType;std::string m_text;std::map<int32,std::string> m_text_locales;};
struct Log{template<class...T>void outError(char const*,T...){}template<class...T>void outDetail(char const*,T...){}}sLog;
uint32 rolls=0;uint32 urand(uint32 a,uint32 b){if(a>b)std::abort();++rolls;return a;}
class PlayerbotTextMgr{public:
 std::map<std::string,std::vector<BotTextEntry>>botTexts;int32 locale=-1;
 int32 GetLocalePriority(){return locale;}
 void ReplacePlaceholders(std::string&s,std::map<std::string,std::string>const&p){for(auto const&v:p){auto at=s.find(v.first);if(at!=s.npos)s.replace(at,v.first.size(),v.second);}}
 std::string GetBotText(ChatReplyType,std::map<std::string,std::string>);
};
#include "ModuleReplySelection.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){PlayerbotTextMgr mgr;std::map<std::string,std::string> names={{"%s","friend"}};
 Check(mgr.GetBotText(ReplyHello,names).empty()&&rolls==0,"empty catalog does not select a row");
 mgr.botTexts["hello"]={{ReplyHello,"Hi",{}}};
 Check(mgr.GetBotText(ReplyHello,names).empty()&&mgr.botTexts.size()==1,"missing reply bucket remains read-only");
 mgr.botTexts["reply"]={{ReplyBye,"Bye %s",{}}};
 Check(mgr.GetBotText(ReplyHello,names).empty()&&rolls==0,"missing category cannot underflow the random index");
 Check(mgr.GetBotText(ReplyBye,names)=="Bye friend"&&rolls==1,"matching reply and placeholders preserved");
 mgr.locale=2;mgr.botTexts["reply"][0].m_text_locales[2]="Goodbye %s";
 Check(mgr.GetBotText(ReplyBye,names)=="Goodbye friend","localized reply selected");mgr.locale=3;
 Check(mgr.GetBotText(ReplyBye,names)=="Bye friend","absent locale falls back to base text");
 std::cout<<"Reply selection empty catalog/category, read-only lookup and locale checks passed\n";
}
