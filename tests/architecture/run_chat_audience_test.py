from pathlib import Path
import argparse,re,subprocess
r=Path(__file__).resolve().parents[2]
p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args()
out=a.output.resolve();out.mkdir(parents=True,exist_ok=True)
s=(r/'modules/ManTechPlayerbots/playerbot/strategy/actions/SayAction.cpp').read_text(encoding='utf-8')
start=s.index('void ChatReplyAction::ChatReplyDo(')
end=s.index('\nbool ChatReplyAction::HandleThunderfuryReply',start)
s=s[start:end]
elig=s[s.index('    if (GetBotAI(bot) &&'):s.index('    {\n        Player* player =',s.index('    if (GetBotAI(bot) &&'))]
guard=re.search(r'        if \(!chanName.empty\(\) && !ai->ChannelHasRealPlayer\(chanName\)\)\s+return;',s).group()
old=(r/'tests/architecture/ChatAudienceFallbackReference.inc').read_text(encoding='utf-8')
# Wiring checks use the real function. Prompt construction/network work is
# deliberately mocked below; this test covers dispatch, not model responses.
for handler in ['HandleLFGQuestsReply','HandleWTBItemsReply','HandleToxicLinksReply','HandleThunderfuryReply']:
    assert s.index(handler)<s.index(elig)
assert s.index(guard)<s.index('        if (player)')<s.index('    SendGeneralResponse(')
assert re.search(r'SET_AI_VALUE\([^\n]+\);\s+return;\s+}\s+}\s+SendGeneralResponse',s)
prefix=r"""
#include <cassert>
#include <iostream>
#include <set>
#include <string>
enum class ChatChannelSource { SRC_UNDEFINED, SRC_WORLD, SRC_WHISPER };
enum class BotState { BOT_STATE_NON_COMBAT };
struct Player{};
struct AI {bool audience=false,strategy=false;bool HasStrategy(const char*,BotState){return strategy;}bool ChannelHasRealPlayer(std::string const&){return audience;}} instance;
bool hasAI=true;
AI* GetBotAI(Player*){return hasAI?&instance:nullptr;}
struct {int llmEnabled=0;std::set<ChatChannelSource> llmBlockedReplyChannels;}sPlayerbotAIConfig;
enum Outcome {NO_AUDIENCE, LLM_POLICY, CANNED, SPECIAL};
"""
def method(name,code):
    return 'Outcome '+name+'(Player* bot,Player* player,std::string chanName,ChatChannelSource chatChannelSource,bool special){\nif(special)return SPECIAL;\n'+elig+'{\nAI* ai=GetBotAI(bot);\n'+code.replace('return;','return NO_AUDIENCE;')+'\nif(player)return LLM_POLICY;\n}\nreturn CANNED;\n}\n'
main=r"""
int main(){unsigned cases=0,corrected=0;Player receiver,sender;
for(bool ai:{false,true})for(int mode:{0,1,2,3})for(bool strategy:{false,true})
for(bool blocked:{false,true})for(auto source:{ChatChannelSource::SRC_UNDEFINED,ChatChannelSource::SRC_WORLD,ChatChannelSource::SRC_WHISPER})
for(bool named:{false,true})for(bool audience:{false,true})for(int who:{0,1,2})for(bool special:{false,true}){
 hasAI=ai;instance.strategy=strategy;instance.audience=audience;sPlayerbotAIConfig.llmEnabled=mode;sPlayerbotAIConfig.llmBlockedReplyChannels.clear();if(blocked)sPlayerbotAIConfig.llmBlockedReplyChannels.insert(source);
 Player* p=who==0?nullptr:who==1?&sender:&receiver;
 auto before=Old(&receiver,p,named?"World":"",source,special);
 auto after=New(&receiver,p,named?"World":"",source,special);
 bool eligible=ai&&mode>0&&(strategy||mode==3)&&source!=ChatChannelSource::SRC_UNDEFINED&&!blocked;
 if(!special&&eligible&&named&&!audience){assert(before==CANNED&&after==NO_AUDIENCE);++corrected;}
 else assert(before==after);
 ++cases;
}
assert(corrected>0);std::cout<<"PASS "<<cases<<" dispatch cases; "<<corrected<<" erroneous no-audience canned fallthroughs stopped; other dispatch outcomes unchanged\n";
}
"""
(out/'test.cpp').write_text(prefix+method('Old',old)+method('New',guard)+main,encoding='utf-8')
subprocess.run(['cl','/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG','test.cpp','/Fe:test.exe'],cwd=out,check=True)
subprocess.run([str(out/'test.exe')],cwd=out,check=True,timeout=30)
