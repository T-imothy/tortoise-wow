#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>
using uint32=unsigned;using int32=int;
struct AreaTableEntry{uint32 Id,ZoneId;int32 AreaLevel;};
std::map<unsigned,AreaTableEntry>areas={{1,{1,0,20}},{2,{2,1,0}},{3,{3,0,0}},{4,{4,3,10}}};
AreaTableEntry const*GetAreaEntryByAreaID(unsigned id){auto i=areas.find(id);return i==areas.end()?nullptr:&i->second;}
struct Store{unsigned GetMaxEntry(){return 5;}}sAreaStore;
struct FactionTemplateEntry{};
struct Factions{FactionTemplateEntry entry;FactionTemplateEntry const*LookupEntry(unsigned){return &entry;}}sFactionTemplateStore;
struct CreatureData{unsigned creature_id[1];};struct CreatureInfo{unsigned faction=1,level_max=1;};
struct ObjectMgr{CreatureInfo info;CreatureInfo const*GetCreatureTemplate(unsigned){return &info;}}sObjectMgr;
struct WorldPosition{WorldPosition()=default;template<class T>WorldPosition(T){}AreaTableEntry const*GetArea(){return nullptr;}auto GetCreaturesNear(){return std::vector<std::pair<unsigned,CreatureData> const*>{};}};
using ReputationRank=int;enum{REP_NEUTRAL};
struct PlayerbotAI{static int GetFactionReaction(FactionTemplateEntry const*,FactionTemplateEntry const*){return REP_NEUTRAL;}};
struct TravelMgr{std::unordered_map<uint32,int32>areaLevels;mutable std::recursive_mutex areaLevelsMutex;int32 GetAreaLevel(uint32);bool TryGetValidatedAreaLevel(uint32,int32&)const;};
#include "ModuleAreaLevelCache.inc"
int main(){TravelMgr cache;std::atomic<bool>go=false,failed=false;std::vector<std::thread>workers;
 for(unsigned worker=0;worker<8;++worker)workers.emplace_back([&,worker]{while(!go.load())std::this_thread::yield();for(unsigned n=0;n<200;++n){
  if(cache.GetAreaLevel(2)!=20||cache.GetAreaLevel(3)!=10)failed=true;
  unsigned invalid=1000+worker*200+n;int32 level=0;
  if(cache.GetAreaLevel(invalid)!=-2||cache.TryGetValidatedAreaLevel(invalid,level))failed=true;
  if(!cache.TryGetValidatedAreaLevel(2,level)||level!=20)failed=true;
 }});
 go=true;for(auto&worker:workers)worker.join();
 if(failed||cache.areaLevels.size()!=1604){std::cerr<<"Concurrent lazy cache, parent recursion or validated read failed\n";return 1;}
 std::cout<<"Eight concurrent native area-cache readers/writers preserve recursive results and 1604 entries\n";
}
