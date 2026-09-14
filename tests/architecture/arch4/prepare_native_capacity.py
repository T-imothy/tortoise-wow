from pathlib import Path
import shutil
import sys
root=Path(__file__).resolve().parents[3];stage=root;out=Path(sys.argv[1])/'native_capacity';out.mkdir(parents=True,exist_ok=True)
for directory in ['Include','Source']:
    for p in (root/'dep/recastnavigation/Detour'/directory).iterdir():
        if p.is_file():
            rel=p.relative_to(root);source=stage/rel
            dest=out/'Detour'/directory;dest.mkdir(parents=True,exist_ok=True)
            shutil.copyfile(source if source.exists() else p,dest/p.name)
s=(stage/'src/game/Maps/MoveMap.h').read_text();a=s.index('    struct MMapData');b=s.index('    typedef std::unordered_map<uint32, MMapData*>',a)
(out/'MMapData.inc').write_text(s[a:b])
(out/'capacity.cpp').write_text(r'''
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include "DetourNavMeshBuilder.h"
#include "DetourAlloc.h"
#include "Memory/MemoryLedger.h"
#include <unordered_map>
#include <shared_mutex>
#include <thread>
#include <mutex>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
using uint32=uint32_t;
using MMapTileSet=std::unordered_map<uint32,dtTileRef>;
using NavMeshQuerySet=std::unordered_map<std::thread::id,dtNavMeshQuery*>;
#include "MMapData.inc"
using namespace ManTech;
static std::unordered_map<void*,size_t> live;
static size_t bytes=0;
void* alloc(size_t n,dtAllocHint){auto p=malloc(n);if(p){live[p]=n;bytes+=n;}return p;}
void release(void* p){if(!p)return;assert(live.count(p));bytes-=live.at(p);live.erase(p);free(p);}
int main(){
 dtAllocSetCustom(alloc,release);
 for(int cycle=0;cycle<40;++cycle){
  auto mesh=dtAllocNavMesh();dtNavMeshParams params{};params.tileWidth=10;params.tileHeight=10;params.maxTiles=16;params.maxPolys=64;
  assert(dtStatusSucceed(mesh->init(&params)));
  assert(bytes==mesh->getOwnedMemoryBytes());
  {
   MMapData owner(mesh);
   assert(MemoryLedger::Read(MemoryKind::NavShared).bytes==sizeof(owner)+bytes);
   for(int nodes:{2048,16384}){
    auto before=bytes;auto query=dtAllocNavMeshQuery();assert(dtStatusSucceed(query->init(mesh,nodes)));
    assert(bytes-before==query->getOwnedMemoryBytes());
    MemoryLedger::Add(MemoryKind::NavQueries,query->getOwnedMemoryBytes());
    MemoryLedger::Remove(MemoryKind::NavQueries,query->getOwnedMemoryBytes());dtFreeNavMeshQuery(query);
    assert(bytes==before);
   }
   auto query=dtAllocNavMeshQuery();assert(dtStatusSucceed(query->init(mesh,2048)));
   owner.navMeshQueries.emplace(std::this_thread::get_id(),query);
   MemoryLedger::Add(MemoryKind::NavQueries,query->getOwnedMemoryBytes());
   auto failed=dtAllocNavMeshQuery();auto allocated=bytes;
   assert(dtStatusFailed(failed->init(mesh,65536)));dtFreeNavMeshQuery(failed);assert(bytes<allocated);
  }
  assert(bytes==0 && live.empty());
  for(auto k:{MemoryKind::NavShared,MemoryKind::NavQueries,MemoryKind::NavTiles}){
   auto r=MemoryLedger::Read(k);assert(r.count==0&&r.bytes==0);
  }
 }
 dtAllocSetCustom(nullptr,nullptr);
 std::cout<<"PASS actual Detour allocations equal capacity reports; query failure/free and native MMapData destruction balance across 40 lifetimes\n";
}
''')
print(out)
fixture=(out/'capacity.cpp').read_text()
native=(root/'tests/architecture/NavMeshLifetimeTest.cpp').read_text(encoding='utf-8')
a=native.index('static dtTileRef AddFlatTile');b=native.index('static void CheckGate',a)
fixture=fixture.replace('int main(){','void Check(bool ok){assert(ok);}\n'+native[a:b]+'\nint main(){')
fixture=fixture.replace('  {\n   MMapData owner(mesh);','''  auto sharedBytes=bytes;
  auto initialTile=AddFlatTile(*mesh,0);
  auto tileBytes=bytes-sharedBytes;
  {
   MMapData owner(mesh);''')
fixture=fixture.replace('sizeof(owner)+bytes','sizeof(owner)+sharedBytes')
fixture=fixture.replace('   for(int nodes:', '''   assert(MemoryLedger::Read(MemoryKind::NavTiles).bytes==tileBytes);
   // A successful native removal releases the tile charge exactly once.
   if(cycle%2){
    assert(dtStatusSucceed(mesh->removeTile(initialTile,nullptr,nullptr)));
    MemoryLedger::Remove(MemoryKind::NavTiles,tileBytes);
    assert(dtStatusFailed(mesh->removeTile(initialTile,nullptr,nullptr)));
   }
   for(int nodes:''')
(out/'capacity.cpp').write_text(fixture)
