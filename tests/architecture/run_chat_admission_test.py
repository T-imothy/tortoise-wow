from pathlib import Path
import argparse,subprocess
r=Path(__file__).resolve().parents[2]
p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);args=p.parse_args()
out=args.output.resolve();out.mkdir(parents=True,exist_ok=True)
before=(r/'tests/architecture/ChatAdmissionReference.inc').read_text(encoding='utf-8')
after=(r/'modules/ManTechPlayerbots/playerbot/PlayerbotAI.cpp').read_text(encoding='utf-8')
def body(s,after=False):
 start=s.index('            if (guid1 != bot->GetObjectGuid()) // do not reply to self',s.index('void PlayerbotAI::HandleBotOutgoingPacket'))
 end=s.index('            if (usesAIChat())' if after else '            if (isAiChat)',start)
 return s[start:end].replace("guid1.GetRawValue()", "uint64_t(guid1)")
prefix=r'''
#include <algorithm>
#include "playerbot/ChatPrefix.h"
#include "playerbot/ChatBroadcastSender.h"
#include <cassert>
#include <cctype>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <chrono>
using uint32=uint32_t;using ObjectGuid=uint32_t;
enum {CHAT_MSG_CHANNEL,CHAT_MSG_GUILD,CHAT_MSG_WHISPER,LANG_ADDON=99};
enum class BotState {BOT_STATE_NON_COMBAT};using ChatChannelSource=int;
#define MANGOS_ASSERT assert
struct {int llmEnabled=2,toxicLinksRepliesChance=0,thunderfuryRepliesChance=0,guildRepliesRate=100;std::string toxicLinksPrefix="toxic";bool freeBot=true,freeAlt=false;bool IsInRandomAccountList(uint32){return freeBot;}bool IsFreeAltBot(ObjectGuid){return freeAlt;}}sPlayerbotAIConfig;
int roll=0,values=0,strategies=0,names=0,accounts=0,memberships=0;bool senderReal=false;
int urand(int a,int b){return std::max(a,std::min(b,roll));}
struct Player {uint32 guid=2;bool bg=false;uint32 GetObjectGuid(){return guid;}const char* GetName(){return "Recipient";}bool InBattleGround(){return bg;}};
struct {bool GetPlayerNameByGUID(ObjectGuid,std::string& s){++names;s="Sender";return true;}uint32 GetPlayerAccountIdByGUID(ObjectGuid){++accounts;return 1;}Player* GetPlayer(ObjectGuid){static Player sender;return &sender;}}sObjectMgr;
namespace boost {namespace algorithm {bool istarts_with(std::string const& s,std::string const& p){if(s.size()<p.size())return false;for(size_t i=0;i<p.size();++i)if(std::tolower(s[i])!=std::tolower(p[i]))return false;return true;}}}
struct Helpers{std::set<uint32> ExtractAllItemIds(std::string const& s){return s.find("Hitem:19019")!=s.npos?std::set<uint32>{19019}:std::set<uint32>{};}std::set<uint32> ExtractAllQuestIds(std::string const& s){return s.find("Hquest:1")!=s.npos?std::set<uint32>{1}:std::set<uint32>{};}}helper;
struct Value {time_t value=0;time_t Get(){return value;}void Set(time_t v){value=v;}};
struct Context {Value value;template<class T>Value* GetValue(char const*,char const*){++values;return &value;}};
struct AI {Player player,master;Player* bot=&player;Context context;bool hasStrategy=false,hasMaster=false,queued=false,queuedLLM=false;
 AI(){master.guid=1;}
 bool HasStrategy(const char*,BotState){++strategies;return hasStrategy;}
 bool HasRealPlayerMaster(){return hasMaster;}Player* GetMaster(){return &master;}
 bool IsRealPlayer(Player*){return senderReal;}Context* GetAiObjectContext(){return &context;}Helpers* GetChatHelper(){return &helper;}
 ChatChannelSource GetChatChannelSource(Player*,uint32,std::string const&){return 0;}
 void QueueChatResponse(uint32,ObjectGuid,ObjectGuid,std::string const&,std::string const&,std::string const&,bool llm){queued=true;queuedLLM=llm;}
 void Old(ObjectGuid guid1,uint32 msgtype,uint32 lang,std::string message){std::string name,chanName="World";
 bool isAiChat=sPlayerbotAIConfig.llmEnabled>0&&(HasStrategy("ai chat",BotState::BOT_STATE_NON_COMBAT)||sPlayerbotAIConfig.llmEnabled==3);
 if(isAiChat&&(lang==LANG_ADDON||message.find("d:")==0))return;
'''
middle=r'''
 }
 void New(ObjectGuid guid1,uint32 msgtype,uint32 lang,std::string message){std::string name,chanName="World";
 auto usesAIChat=[this]{return sPlayerbotAIConfig.llmEnabled>0&&(sPlayerbotAIConfig.llmEnabled==3||HasStrategy("ai chat",BotState::BOT_STATE_NON_COMBAT));};
'''
tests=r'''
 }
};
int main(){
 // Compare recipient outcomes, including cooldowns, mentions, LLM, addons,
 // debug prefixes, guild gates and special-link reply paths. RNG calls move
 // after/before rejected cooldown checks; probability policy is unchanged.
 unsigned cases=0;
 for(bool free:{false,true})for(bool alt:{false,true})for(bool real:{false,true})for(int llm:{0,2,3})for(bool strategy:{false,true})
 for(bool paused:{false,true})for(bool bg:{false,true})for(bool master:{false,true})
 for(int channel:{CHAT_MSG_CHANNEL,CHAT_MSG_GUILD,CHAT_MSG_WHISPER})for(int lang:{0,int(LANG_ADDON)})
 for(int random:{0,1,20,100})for(std::string message:{"hello","Recipient hi","d:debug","toxic Hquest:1","Hitem:19019"}){
  sPlayerbotAIConfig.freeBot=free;sPlayerbotAIConfig.freeAlt=alt;senderReal=real;sPlayerbotAIConfig.llmEnabled=llm;sPlayerbotAIConfig.toxicLinksRepliesChance=25;sPlayerbotAIConfig.thunderfuryRepliesChance=25;
  roll=random;AI a,b;a.hasStrategy=b.hasStrategy=strategy;a.hasMaster=b.hasMaster=master;a.player.bg=b.player.bg=bg;
  a.context.value.value=b.context.value.value=paused?time(0)+1000:0;
  a.Old(1,channel,lang,message);b.New(1,channel,lang,message);
  assert(a.queued==b.queued&&a.queuedLLM==b.queuedLLM);
  AI cached;cached.hasStrategy=strategy;cached.hasMaster=master;cached.player.bg=bg;cached.context.value.value=paused?time(0)+1000:0;
  {ai::chat::BroadcastSenderScope sender(1,free||(alt&&!real));cached.New(1,channel,lang,message);}
  assert(a.queued==cached.queued&&a.queuedLLM==cached.queuedLLM);++cases;
 }
 sPlayerbotAIConfig.freeBot=true;sPlayerbotAIConfig.llmEnabled=2;sPlayerbotAIConfig.toxicLinksRepliesChance=0;sPlayerbotAIConfig.thunderfuryRepliesChance=0;roll=1;
 values=strategies=names=0;for(int i=0;i<10000;++i){AI a;a.Old(1,CHAT_MSG_CHANNEL,0,"hello");}
 assert(values==10000&&strategies==10000&&names==10000);
 values=strategies=names=accounts=0;for(int i=0;i<10000;++i){AI a;a.New(1,CHAT_MSG_CHANNEL,0,"hello");}
 assert(values==0&&strategies==0&&names==0&&accounts==10000);
 accounts=0;{ai::chat::BroadcastSenderScope sender(1,true);for(int i=0;i<10000;++i){AI a;a.New(1,CHAT_MSG_CHANNEL,0,"hello");}}
 assert(accounts==0);
 std::cout<<"PASS "<<cases<<" old/new recipient-policy cases; 10k rejected recipients avoid all strategy, cooldown and name lookups\n";
}
'''
(out/'test.cpp').write_text(prefix+before+middle+body(after,True)+tests)
print(out/'test.cpp')

subprocess.run(['cl','/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG','/I'+str(r/'modules/ManTechPlayerbots'),'test.cpp','/Fe:test.exe'],cwd=out,check=True)
subprocess.run([str(out/'test.exe')],cwd=out,check=True,timeout=45)
