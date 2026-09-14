from pathlib import Path
import sys
w=Path(__file__).parent;s=w.parents[2];t=Path(sys.argv[1])
sql=(s/'src/shared/Database/SqlOperations.h').read_text(encoding='utf-8')
sql=sql[sql.index('class SqlOperation\n'):sql.index('class SqlTransaction :')]
code=r'''
#include <memory>
#include <functional>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include "Memory/MemoryLedger.h"
using uint32=uint32_t;class SqlConnection;
char* mangos_strdup(const char* s){auto n=strlen(s)+1;auto p=new char[n];memcpy(p,s,n);return p;}
SQL_CLASSES
bool SqlPlainRequest::Execute(SqlConnection*){return true;}
bool SqlMultilineRequest::Execute(SqlConnection*){return true;}
int main(){using namespace ManTech;
 auto before=MemoryLedger::Read(MemoryKind::DatabaseWork);
 {auto first=std::make_unique<SqlPlainRequest>("SELECT 123");auto second=std::make_unique<SqlMultilineRequest>(std::string(10000,'x').c_str());
 auto live=MemoryLedger::Read(MemoryKind::DatabaseWork);assert(live.count==before.count+2);assert(live.bytes>=before.bytes+10011);
 assert(first->Execute(nullptr));assert(MemoryLedger::Read(MemoryKind::DatabaseWork).count==before.count+2);
 first.reset();assert(MemoryLedger::Read(MemoryKind::DatabaseWork).count==before.count+1);
 }
 assert(MemoryLedger::Read(MemoryKind::DatabaseWork).count==before.count);assert(MemoryLedger::Read(MemoryKind::DatabaseWork).bytes==before.bytes);
 std::cout<<"Actual SQL base/query accounting remains charged through execution and releases on destruction\n";
}
'''.replace('SQL_CLASSES',sql)
(t/'sql_accounting_tests.cpp').write_text(code)
native=(s/'src/game/Maps/GridMap.cpp').read_text(encoding='utf-8')
def body(sig):
 start=native.index('{',native.index(sig));end=start+1;depth=1
 while depth:depth+=(native[end]=='{')-(native[end]=='}');end+=1
 return native[start:end]
h=(s/'src/game/Maps/GridMap.h').read_text(encoding='utf-8')
start=h.index('        void AccountPayload(');end=h.index('        bool loadAreaData',start)
account=h[start:end]
code=r'''
#include <atomic>
#include <cstdint>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "Memory/MemoryLedger.h"
using uint32=uint32_t;using int16=int16_t;using uint16=uint16_t;using uint8=uint8_t;
struct dtAccessGate{struct Read{Read(dtAccessGate*){}};struct Write{Write(dtAccessGate*){}};};
constexpr int MAX_NUMBER_OF_GRIDS=2;
struct GridMap{
 uint16* m_area_map=nullptr;float* m_V9=nullptr;float* m_V8=nullptr;uint16* m_liquidEntry=nullptr;uint8* m_liquidFlags=nullptr;float* m_liquid_map=nullptr;
 float getHeightFromFlat(float,float)const{return 0;}
 float(GridMap::*m_gridGetHeight)(float,float)const=&GridMap::getHeightFromFlat;
 size_t m_payloadBytes=0,m_payloadArrays=0;
 ACCOUNT
 size_t GetPayloadBytes()const{return m_payloadBytes;}
 void unloadData() UNLOAD
 ~GridMap(){unloadData();}
};
struct Manager{unsigned unloaded=0;void unloadMap(uint32,int,int){++unloaded;}} vm,mm;
namespace VMAP{struct VMapFactory{static Manager* createOrGetVMapManager(){return &vm;}};}
namespace MMAP{struct MMapFactory{static Manager* createOrGetMMapManager(){return &mm;}};}
struct TerrainInfo{
 dtAccessGate m_lifetimeGate;uint32 m_mapId=0,m_pressureCheckElapsed=0;
 struct Timer{uint32 elapsed=0;void Update(uint32 d){elapsed+=d;}bool Passed(){return elapsed>=60000;}void Reset(){elapsed=0;}} i_timer;
 std::atomic<GridMap*> m_GridMaps[2][2]{};int16 m_GridRef[2][2]{};
 void CleanUpGrids(uint32 diff) CLEANUP
};
int main(){using namespace ManTech;auto before=MemoryLedger::Read(MemoryKind::Terrain);
 TerrainInfo terrain;auto held=new GridMap();held->m_liquid_map=new float[17*1024*1024];held->AccountPayload(17*1024*1024*sizeof(float));
 auto idle=new GridMap();idle->m_area_map=new uint16[256];idle->AccountPayload(256*sizeof(uint16));
 terrain.m_GridMaps[0][0]=held;terrain.m_GridRef[0][0]=1;terrain.m_GridMaps[1][1]=idle;
 terrain.CleanUpGrids(500);assert(terrain.m_GridMaps[1][1]);
 terrain.CleanUpGrids(500);assert(!terrain.m_GridMaps[1][1]);assert(terrain.m_GridMaps[0][0]==held);assert(vm.unloaded==1&&mm.unloaded==1);
 terrain.m_GridRef[0][0]=0;terrain.CleanUpGrids(1000);assert(!terrain.m_GridMaps[0][0]);assert(vm.unloaded==2&&mm.unloaded==2);
 terrain.CleanUpGrids(60000);assert(vm.unloaded==2);
 assert(MemoryLedger::Read(MemoryKind::Terrain).bytes==before.bytes);assert(MemoryLedger::Read(MemoryKind::Terrain).count==before.count);
 std::cout<<"Actual terrain cleanup/accounting: one-second pressure checks, referenced tiles protected, collision/nav releases and repeated cleanup balanced\n";
}
'''.replace('ACCOUNT',account).replace('UNLOAD',body('void GridMap::unloadData')).replace('CLEANUP',body('void TerrainInfo::CleanUpGrids'))
(t/'terrain_pressure_tests.cpp').write_text(code)
