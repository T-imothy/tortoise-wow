#include <algorithm>
#include <atomic>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <tuple>
#include <vector>
#include "ItemCacheLookup.h"
using TortoiseBots::LookupItemCache;
using uint32=unsigned; using uint8=unsigned char; using int32=int;
using RandomItemList=std::vector<uint32>;
enum EquipmentSlots { EQUIPMENT_SLOT_HEAD, EQUIPMENT_SLOT_NECK, EQUIPMENT_SLOT_TRINKET1, EQUIPMENT_SLOT_TRINKET2, EQUIPMENT_SLOT_FINGER1, EQUIPMENT_SLOT_FINGER2 };
enum { ITEM_SOURCE_QUEST=1, ITEM_SOURCE_PVP=2, QUEST_STATUS_COMPLETE=1 };
struct BotEquipKey {
 std::tuple<uint32,uint8,uint8,uint8,uint32> key;
 BotEquipKey(uint32 a,uint8 b,uint8 c,uint8 d,uint32 e):key(a,b,c,d,e){}
 bool operator<(BotEquipKey const& b)const{return key<b.key;}
};
struct ItemInfoEntry { std::map<uint32,uint32>weights;uint32 minLevel=25,team=0,slot=0,quality=2,source=0,itemId=0;std::vector<uint32>sourceIds;};
struct WeightScale {struct {uint32 id=0;}info;};
struct Player { uint32 GetLevel(){return 30;}uint32 GetTeam(){return 1;}int GetQuestRewardStatus(uint32){return 0;}struct Honor {struct Rank {int rank=0;};Rank GetRank(){return {};}};Honor GetHonorMgr(){return {};}};
struct Log {template<class...T>void outString(T...){} }sLog;
uint32 urand(uint32 low,uint32){return low;}
struct RandomItemMgr {
 std::map<BotEquipKey,RandomItemList> equipCache;
 std::map<uint32,std::map<uint32,uint32>>ammoCache;
 std::map<uint32,std::map<uint32,RandomItemList>>potionCache,foodCache;
 std::map<uint32,RandomItemList>tradeCache;
 std::map<uint32,ItemInfoEntry*>itemInfoCache;
 std::map<uint32,WeightScale>m_weightScales;
 uint32 GetPlayerSpecId(Player*){return 21;}
 RandomItemList Query(uint32,uint8,uint8,uint8,uint32);
 uint32 GetAmmo(uint32,uint32);uint32 GetRandomPotion(uint32,uint32);uint32 GetRandomFood(uint32,uint32);uint32 GetRandomTrade(uint32);
 bool HasStatWeight(uint32);uint32 GetMinLevelFromCache(uint32);uint32 GetStatWeight(Player*,uint32);uint32 GetStatWeight(uint32,uint32);
 std::vector<uint32> GetUpgradeList(Player*,uint32,uint8,uint32,uint32,uint32=1);
}sRandomItemMgr;
#include "ModuleItemCacheEquip.inc"
#include "ModuleItemCacheAmmo.inc"
#include "ModuleItemCachePotion.inc"
#include "ModuleItemCacheFood.inc"
#include "ModuleItemCacheTrade.inc"
#include "ModuleItemCacheWeight.inc"
#include "ModuleItemCacheHasWeight.inc"
#include "ModuleItemCacheUpgrade.inc"
int main(){
 auto& c=sRandomItemMgr;Player player;
 c.equipCache[BotEquipKey(30,1,21,0,2)]={100}; c.ammoCache[2][1]=200;
 c.potionCache[2][1]={300};c.foodCache[2][1]={400};c.tradeCache[2]={500};c.m_weightScales[21].info.id=21;
 std::vector<ItemInfoEntry> items(64);
 for(unsigned i=0;i<items.size();++i){auto& item=items[i];item.itemId=100+i;item.weights[21]=50; c.itemInfoCache[item.itemId]=&item;}
 c.itemInfoCache[999]=nullptr;
 std::atomic<bool> fail=false;std::vector<std::thread>threads;
 for(unsigned worker=0;worker<8;++worker)threads.emplace_back([&,worker]{for(unsigned n=0;n<200;++n){unsigned miss=10000+worker*200+n;
  if(c.Query(30,1,21,0,2)!=RandomItemList{100} || !c.Query(miss,1,21,0,2).empty() || c.GetAmmo(30,1)!=200 || c.GetAmmo(miss,miss)!=0 || c.GetRandomPotion(30,1)!=300 || c.GetRandomPotion(30,miss)!=0 || c.GetRandomFood(30,1)!=400 || c.GetRandomFood(miss,miss)!=0 || c.GetRandomTrade(30)!=500 || c.GetRandomTrade(miss)!=0 || c.GetStatWeight(100,21)!=50 || c.GetStatWeight(100,miss)!=0 || c.GetStatWeight(miss,21)!=0 || c.GetMinLevelFromCache(miss)!=0 || c.HasStatWeight(miss) || c.HasStatWeight(999))fail=true;
 }});
 for(auto& t:threads)t.join();
 auto upgrades=c.GetUpgradeList(&player,21,0,2,0);
 if(upgrades.size()!=64 || c.GetStatWeight(&player,100)!=50 || c.GetStatWeight(nullptr,100)!=0)fail=true;
 if(c.equipCache.size()!=1||c.ammoCache.size()!=1||c.ammoCache.at(2).size()!=1||c.potionCache.size()!=1||c.potionCache.at(2).size()!=1||c.foodCache.size()!=1||c.foodCache.at(2).size()!=1||c.tradeCache.size()!=1||c.itemInfoCache.size()!=65||c.m_weightScales.size()!=1)fail=true;
 for(auto const& item:items)if(item.weights.size()!=1)fail=true;
 if(fail){std::cerr<<"Native item lookup result, equal-weight ordering or cache immutability failed\n";return 1;}
 std::cout<<"Native cache queries preserve all populated/missing results across eight readers; equal-weight upgrade sort succeeds\n";
}
