from pathlib import Path
import argparse,subprocess
r=Path(__file__).resolve().parents[2]
p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);args=p.parse_args()
out=args.output.resolve();out.mkdir(parents=True,exist_ok=True)
def functions(source,klass):
 result=[]
 for name in ['ExtractAllItemIds','ExtractAllQuestIds']:
  start=source.index('std::set<uint32> ChatHelper::'+name)
  end=source.index('\n}\n',start)+3
  result.append(source[start:end].replace('ChatHelper::',klass+'::'))
 return '\n'.join(result)
prefix='''#include <set>
#include <regex>
#include <string>
#include <cstdint>
#include <cassert>
#include <thread>
#include <vector>
#include <iostream>
using uint32=uint32_t;
struct Before {static std::set<uint32> ExtractAllItemIds(std::string const&);static std::set<uint32> ExtractAllQuestIds(std::string const&);};
struct After {static std::set<uint32> ExtractAllItemIds(std::string const&);static std::set<uint32> ExtractAllQuestIds(std::string const&);};
'''
test='''
int main(){
 for(std::string s:{"","ordinary chat","Hitem:","Hitem:-1","Hitem:19019","Hitem:019019 Hitem:19019","|cffffffff|Hitem:42:0|h[Name]|h|r","Hquest:1:60 Hquest:10","Hitem:42 and Hquest:1","Hitem:0 Hitem:123x"}){
 assert(Before::ExtractAllItemIds(s)==After::ExtractAllItemIds(s));assert(Before::ExtractAllQuestIds(s)==After::ExtractAllQuestIds(s));}
 // The existing overflow behavior is preserved; no silent ID wrapping.
 for(bool old:{false,true}){bool threw=false;try{if(old)Before::ExtractAllItemIds("Hitem:999999999999999999999");else After::ExtractAllItemIds("Hitem:999999999999999999999");}catch(std::out_of_range const&){threw=true;}assert(threw);}
 std::vector<std::thread> workers;for(int i=0;i<8;++i)workers.emplace_back([]{for(int j=0;j<1000;++j){assert(After::ExtractAllItemIds("Hitem:19019 Hitem:42").size()==2);assert(After::ExtractAllQuestIds("Hquest:1 Hquest:10").size()==2);}});for(auto& w:workers)w.join();
 std::cout<<"PASS link/no-link/duplicate/malformed/overflow equivalence and 8 concurrent readers of immutable patterns\\n";
}
'''
(out/'links.cpp').write_text(prefix+functions((r/'tests/architecture/ChatLinksReference.inc').read_text(encoding='utf-8'),'Before')+functions((r/'modules/ManTechPlayerbots/playerbot/ChatHelper.cpp').read_text(encoding='utf-8'),'After')+test)

subprocess.run(['cl','/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG','links.cpp','/Fe:links.exe'],cwd=out,check=True)
subprocess.run([str(out/'links.exe')],cwd=out,check=True,timeout=45)
