"""Compile current source bodies against native-boundary fixtures."""
from pathlib import Path
import subprocess,argparse
p=argparse.ArgumentParser();p.add_argument('--root',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();a.output.mkdir(parents=True,exist_ok=True)
m=a.root/'modules/ManTechPlayerbots/playerbot'
def body(path,signature):
 s=path.read_text(encoding='utf8');start=s.index(signature);end=s.index('{',start);depth=1;i=end+1
 while depth:
  depth+=(s[i]=='{')-(s[i]=='}');i+=1
 return s[start:i]
fixture=r'''
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <regex>
#include <mutex>
#include <memory>
#include <iostream>
#include <algorithm>
#include <cstdint>
using uint32=uint32_t; using uint8=uint8_t;
enum {CHAR_NAME_SUCCESS=0,CHAR_NAME_RESERVED=1,CHAR_NAME_PROFANE=2,SEC_PLAYER=0};
std::vector<std::wregex> NamesProfaneValidators,NamesReservedValidators;
uint8 ValidateName(std::wstring const&);
struct PlayerCacheData{uint32 uiAccount=1;std::string sName;};
struct CreatureInfo{uint32 VendorTemplateId=0;};
struct VendorItemData{std::vector<int> m_items;};
struct ObjectMgr{
 std::map<uint32,PlayerCacheData> chars;std::map<uint32,CreatureInfo> creatures;std::map<uint32,VendorItemData> direct,shared;
 static uint8 CheckPlayerName(std::string const& n){return ValidateName(std::wstring(n.begin(),n.end()));}
 bool IsReservedName(std::string const& n){return n=="DatabaseReserved";}
 PlayerCacheData const* GetPlayerDataByGUID(uint32 id){auto i=chars.find(id);return i==chars.end()?nullptr:&i->second;}
 CreatureInfo const* GetCreatureTemplate(uint32 id){auto i=creatures.find(id);return i==creatures.end()?nullptr:&i->second;}
 VendorItemData const* GetNpcVendorItemList(uint32 id){auto i=direct.find(id);return i==direct.end()?nullptr:&i->second;}
 VendorItemData const* GetNpcVendorTemplateItemList(uint32 id){auto i=shared.find(id);return i==shared.end()?nullptr:&i->second;}
}sObjectMgr;
struct {bool IsInRandomAccountList(uint32 a){return a==1||a==2;}}sPlayerbotAIConfig;
struct {int GetSecurity(uint32 a){return a==2?1:0;}}sAccountMgr;
struct {template<class...T>void outError(T...){}}sLog;
struct RandomPlayerbotMgr{
 std::map<uint32,int> pending;std::map<uint32,int> login;
 void ClearPendingBotLogin(uint32 b){pending.erase(b);}void SetEventValue(uint32 b,char const*,int v,int){login[b]=v;}
 void OnBotLoginQueryComplete(uint32);
};
unsigned urand(unsigned a,unsigned){return a;}
struct RandomPlayerbotFactory{
 enum class NameRaceAndGender:uint8{Male=0,Female=1};
 static std::mutex nameMutex;static std::map<NameRaceAndGender,std::vector<std::string>> freeNames;
 static void EnsureNamesInitialized(){}static std::string CreateRandomBotName(NameRaceAndGender);
};
std::mutex RandomPlayerbotFactory::nameMutex;
std::map<RandomPlayerbotFactory::NameRaceAndGender,std::vector<std::string>> RandomPlayerbotFactory::freeNames;
'''
parts=[body(a.root/'src/game/Database/DBCStores.cpp','uint8 ValidateName('),body(m/'RandomPlayerbotMgr.cpp','bool IsRandomBotLoginCandidate('),body(m/'RandomPlayerbotMgr.cpp','void RandomPlayerbotMgr::OnBotLoginQueryComplete('),body(m/'RandomPlayerbotFactory.cpp','std::string RandomPlayerbotFactory::CreateRandomBotName('),body(m/'NativeVendorStock.h','inline bool HasNativeVendorStock(')]
tests=r'''
int main(){
 for(auto rule:{L"^sir",L"^lothar$",L"^atari$",L"^god",L"^jenn",L"^marine",L"^master",L"^santa$",L"^nimue$",L"^eowyn$",L"^lord"})NamesReservedValidators.emplace_back(rule,std::regex::icase);
 std::vector<std::string> rejected={"Siristo","Lothar","Atari","Sirion","Godo","Sirina","Sirawgam","Jennata","Sirupez","Marineron","Siristera","Masterrenz","Sirynn","Santa","Marinerva","Jennah","Nimue","Eowyn","Siriam","Lordon"};
 uint32 id=1;for(auto const&name:rejected){sObjectMgr.chars[id]={1,name};assert(!IsRandomBotLoginCandidate(id));++id;}
 sObjectMgr.chars[30]={1,"Averin"};assert(IsRandomBotLoginCandidate(30));assert(!IsRandomBotLoginCandidate(999));
 sObjectMgr.chars[31]={3,"Averin"};assert(!IsRandomBotLoginCandidate(31));
 sObjectMgr.chars[32]={1,"DatabaseReserved"};assert(!IsRandomBotLoginCandidate(32));
 sObjectMgr.chars[33]={2,"DatabaseReserved"};assert(IsRandomBotLoginCandidate(33)); // native security exception
 sObjectMgr.chars[34]={2,"Siristo"};assert(!IsRandomBotLoginCandidate(34)); // DBC validation still applies
 RandomPlayerbotMgr mgr;mgr.pending[30]=1;mgr.login[30]=1;mgr.OnBotLoginQueryComplete(30);assert(mgr.pending.empty()&&mgr.login[30]==0);mgr.OnBotLoginQueryComplete(30);assert(mgr.pending.empty());
 auto rg=RandomPlayerbotFactory::NameRaceAndGender::Male;
 RandomPlayerbotFactory::freeNames[rg]={"Siristo","Averin","Lothar"};assert(RandomPlayerbotFactory::CreateRandomBotName(rg)=="Averin");assert(RandomPlayerbotFactory::CreateRandomBotName(rg).empty());assert(RandomPlayerbotFactory::CreateRandomBotName(rg).empty());
 assert(!HasNativeVendorStock(1));sObjectMgr.creatures[1]={};assert(!HasNativeVendorStock(1));sObjectMgr.direct[1]={};assert(!HasNativeVendorStock(1));sObjectMgr.direct[1].m_items.push_back(1);assert(HasNativeVendorStock(1));sObjectMgr.direct.clear();sObjectMgr.creatures[1].VendorTemplateId=7;assert(!HasNativeVendorStock(1));sObjectMgr.shared[7].m_items.push_back(2);assert(HasNativeVendorStock(1));
 std::cout<<"PASS: 20 reproduced name failures, valid/absent/foreign-account/security variants, completion/repeated completion, exhausted name pool, direct/shared/empty vendor stock\n";
}
'''
src=a.output/'T89BotFixTest.cpp';src.write_text(fixture+'\n'.join(parts)+tests,encoding='utf8');exe=a.output/'T89BotFixTest.exe'
subprocess.run(['cl.exe','/nologo','/std:c++17','/EHsc','/MD',str(src),'/Fe:'+str(exe),'/Fo:'+str(a.output/'T89BotFixTest.obj')],check=True)
subprocess.run([str(exe)],check=True,timeout=15)

native=r'''
#include <map>
#include <cassert>
#include <iostream>
using uint32=unsigned;enum Team{TEAM_NONE=0,HORDE=67,ALLIANCE=469};
struct GraveYardData{uint32 safeLocId;Team team;};using GraveYardMap=std::multimap<uint32,GraveYardData>;
struct {int writes=0;template<class...T>void ExecuteUpdate(T...){++writes;}}sWorld;
struct {int writes=0;template<class...T>void PExecute(T...){++writes;}}WorldDatabase;
struct ObjectMgr{GraveYardMap m_GraveYardMap;GraveYardData*FindGraveYardData(uint32 id,uint32 zone){auto r=m_GraveYardMap.equal_range(zone);for(auto i=r.first;i!=r.second;++i)if(i->second.safeLocId==id)return &i->second;return nullptr;}bool AddGraveYardLink(uint32,uint32,Team,bool);void RemoveGraveYardLink(uint32,uint32,Team,bool);}sObjectMgr;
struct OPvPCapturePointEP_CGT{void LinkGraveYard(Team);void UnLinkGraveYard();};
'''
h=(a.root/'src/game/OutdoorPvP/OutdoorPvPEP.h').read_text();import re
constants='\n'.join(re.findall(r'uint32 const (?:EP_GraveYardId|EP_Zone|TFV_area) = \d+;',h))
nativeparts=[body(a.root/'src/game/ObjectMgr.cpp','bool ObjectMgr::AddGraveYardLink('),body(a.root/'src/game/ObjectMgr.cpp','void ObjectMgr::RemoveGraveYardLink('),body(a.root/'src/game/OutdoorPvP/OutdoorPvPEP.cpp','void OPvPCapturePointEP_CGT::LinkGraveYard('),body(a.root/'src/game/OutdoorPvP/OutdoorPvPEP.cpp','void OPvPCapturePointEP_CGT::UnLinkGraveYard(')]
nativetest=r'''
int main(){assert(EP_GraveYardId==128);OPvPCapturePointEP_CGT tower;sObjectMgr.AddGraveYardLink(128,139,TEAM_NONE,false);sObjectMgr.AddGraveYardLink(124,139,TEAM_NONE,false);
 tower.UnLinkGraveYard();assert(!sObjectMgr.FindGraveYardData(128,139));assert(sObjectMgr.FindGraveYardData(124,139));
 for(auto team:{ALLIANCE,HORDE,ALLIANCE}){tower.LinkGraveYard(team);tower.LinkGraveYard(team);for(auto zone:{139u,2258u}){auto*g=sObjectMgr.FindGraveYardData(128,zone);assert(g&&g->team==team);}assert(sObjectMgr.m_GraveYardMap.size()==3);tower.UnLinkGraveYard();tower.UnLinkGraveYard();assert(sObjectMgr.m_GraveYardMap.size()==1);}
 assert(!sWorld.writes&&!WorldDatabase.writes);std::cout<<"PASS: actual native graveyard capture, neutralization, recapture, duplicate transitions and no persistent writes\n";}
'''
src=a.output/'T89GraveyardTest.cpp';src.write_text(native+constants+'\n'+'\n'.join(nativeparts)+nativetest);exe=a.output/'T89GraveyardTest.exe'
subprocess.run(['cl.exe','/nologo','/std:c++17','/EHsc','/MD',str(src),'/Fe:'+str(exe),'/Fo:'+str(a.output/'T89GraveyardTest.obj')],check=True)
subprocess.run([str(exe)],check=True,timeout=15)
