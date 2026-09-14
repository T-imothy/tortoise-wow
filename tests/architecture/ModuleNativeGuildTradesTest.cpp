#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include "MapWork.h"
#include "NativeGuildTrades.h"
using uint8=uint8_t;using uint16=uint16_t;using uint32=uint32_t;
struct ObjectGuid{unsigned id=0;bool operator==(ObjectGuid b)const{return id==b.id;}bool operator!=(ObjectGuid b)const{return id!=b.id;}bool operator<(ObjectGuid b)const{return id<b.id;}};
enum{CMSG_INITIATE_TRADE,CMSG_BEGIN_TRADE,CMSG_SET_TRADE_ITEM,CMSG_ACCEPT_TRADE};
enum TradeSlots{SLOT0};constexpr unsigned TRADE_SLOT_COUNT=7;
constexpr uint8 INVENTORY_SLOT_BAG_0=0,INVENTORY_SLOT_ITEM_START=10,INVENTORY_SLOT_ITEM_END=14,INVENTORY_SLOT_BAG_START=1,INVENTORY_SLOT_BAG_END=3;
constexpr int EQUIP_ERR_OK=0;using ItemPosCountVec=std::vector<int>;
struct WorldPacket{std::vector<unsigned>fields;explicit WorldPacket(int){}WorldPacket&operator<<(ObjectGuid g){fields.push_back(g.id);return *this;}template<class T>WorldPacket&operator<<(T n){fields.push_back(unsigned(n));return *this;}};
struct Player;
class Item{public:ObjectGuid guid;unsigned entry=100,count=10,metadata=17;Player*owner=nullptr;uint8 bag=0,slot=10;bool tradable=true;ObjectGuid GetObjectGuid(){return guid;}ObjectGuid GetOwnerGuid();unsigned GetEntry(){return entry;}unsigned GetCount(){return count;}bool CanBeTraded(){return tradable;}uint16 GetPos(){return uint16(bag<<8)|slot;}uint8 GetBagSlot(){return bag;}uint8 GetSlot(){return slot;}};
class Bag:public Item{public:unsigned GetBagSize(){return 4;}};
struct TradeData{Player*owner;Player*trader;std::array<ObjectGuid,TRADE_SLOT_COUNT>items{};unsigned money=0,spell=0;bool accepted=false;Item*GetItem(TradeSlots);unsigned GetMoney(){return money;}unsigned GetSpell(){return spell;}bool IsAccepted(){return accepted;}time_t GetScamPreventionDelay(){return 200;}};
struct Session{Player*owner;void HandleInitiateTradeOpcode(WorldPacket&);void HandleBeginTradeOpcode(WorldPacket&){}void HandleSetTradeItemOpcode(WorldPacket&);void HandleAcceptTradeOpcode(WorldPacket&);};
unsigned nextItem=1000,initiates=0,sets=0,accepts=0,cancels=0;bool initAllowed=true,setAllowed=true,splitAllowed=true,acceptAllowed=true,cancelOnAccept=false;
std::map<ObjectGuid,Player*>players;
struct Group{unsigned id=1;unsigned GetId(){return id;}};
class Player{public:Group*group=nullptr;Group*GetGroup(){return group;}ObjectGuid guid;unsigned guild=1,map=1,instance=0;uint64_t generation=1;bool alive=true,world=true,teleport=false,combat=false,taxi=false,controlled=true,hasAI=true,lifetime=true,space=true;Session session{this};std::unique_ptr<TradeData>trade;std::map<uint16,std::unique_ptr<Item>>items;
 ObjectGuid GetObjectGuid(){return guid;}unsigned GetGuildId(){return guild;}unsigned GetMapId(){return map;}unsigned GetInstanceId(){return instance;}uint64_t GetMapWorkGeneration(){return generation;}bool IsAlive(){return alive;}bool IsInWorld(){return world;}bool IsBeingTeleported(){return teleport;}bool IsInCombat(){return combat;}bool IsTaxiFlying(){return taxi;}Session*GetSession(){return &session;}TradeData*GetTradeData(){return trade.get();}Player*GetTrader(){return trade?trade->trader:nullptr;}char const*GetName(){return "fixture";}
 Item*GetItemByPos(uint8 bag,uint8 slot){auto i=items.find(uint16(bag<<8)|slot);return i==items.end()?nullptr:i->second.get();}
 unsigned GetItemCount(unsigned id,bool){unsigned n=0;for(auto&[pos,item]:items)if(item->entry==id)n+=item->count;return n;}
 int CanStoreNewItem(uint8 bag,uint8 slot,ItemPosCountVec&,unsigned,unsigned){return space&&!GetItemByPos(bag,slot)?0:1;}
 void SplitItem(uint16 src,uint16 dst,unsigned count){if(!splitAllowed||!space)return;auto*old=items.at(src).get();auto copy=std::make_unique<Item>(*old);copy->guid={++nextItem};copy->count=count;copy->bag=uint8(dst>>8);copy->slot=uint8(dst);old->count-=count;items[dst]=std::move(copy);}
 void TradeCancel(bool){++cancels;Player*other=GetTrader();trade.reset();if(other&&other->GetTrader()==this)other->trade.reset();}
 Item*Add(unsigned count=10){auto p=std::make_unique<Item>();p->guid={++nextItem};p->count=count;p->owner=this;Item*r=p.get();items[10]=std::move(p);return r;}
};
ObjectGuid Item::GetOwnerGuid(){return owner->guid;}
Item*TradeData::GetItem(TradeSlots slot){ObjectGuid g=items[unsigned(slot)];for(auto&[pos,item]:owner->items)if(item->guid==g)return item.get();return nullptr;}
void Session::HandleInitiateTradeOpcode(WorldPacket&p){++initiates;if(!initAllowed)return;Player*to=players.at(ObjectGuid{p.fields[0]});owner->trade=std::make_unique<TradeData>();to->trade=std::make_unique<TradeData>();owner->trade->owner=owner;owner->trade->trader=to;to->trade->owner=to;to->trade->trader=owner;}
void Session::HandleSetTradeItemOpcode(WorldPacket&p){++sets;if(setAllowed)owner->trade->items[p.fields[0]]=owner->GetItemByPos(uint8(p.fields[1]),uint8(p.fields[2]))->guid;}
void Session::HandleAcceptTradeOpcode(WorldPacket&){++accepts;if(cancelOnAccept){owner->TradeCancel(true);return;}if(!acceptAllowed)return;owner->trade->accepted=true;Player*other=owner->GetTrader();if(!other->trade->accepted)return;if(!owner->space||!other->space)return;for(Player*from:{owner,other}){Player*to=from->GetTrader();if(Item*gift=from->trade->GetItem(TradeSlots(0))){uint16 source=gift->GetPos();uint8 target=10;while(to->GetItemByPos(0,target))++target;auto moved=std::move(from->items[source]);from->items.erase(source);moved->owner=to;moved->bag=0;moved->slot=target;to->items[target]=std::move(moved);}}owner->trade.reset();other->trade.reset();}
namespace ai{struct Event{Player*player=nullptr;Event(std::string,std::string,Player*p):player(p){}Player*GetOwner()const{return player&&player->lifetime&&player->world?player:nullptr;}};}
struct PlayerbotAI{static bool IsSafe(Player*a,Player*b){return a&&b&&a->world&&b->world&&!a->teleport&&!b->teleport&&a->map==b->map&&a->instance==b->instance;}};
struct PlayerbotAIStorage{static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage x;return x;}PlayerbotAI*GetAI(Player*p){static PlayerbotAI ai;return p&&p->hasAI?&ai:nullptr;}};
namespace TortoiseBots{struct BotRecord{ObjectGuid masterGuid;};struct BotManager{std::map<ObjectGuid,BotRecord>records;static BotManager&Instance(){static BotManager x;return x;}bool IsControllableBot(Player*p){return p&&p->controlled&&p->world;}BotRecord*FindBot(ObjectGuid g){auto i=records.find(g);return i==records.end()?nullptr:&i->second;}};struct BotWorldActions{inline static bool map=false;static bool IsMapExecution(){return map;}};}
std::vector<std::string>logs;struct Log{template<class...T>void outString(char const*fmt,T...args){char out[512];std::snprintf(out,sizeof(out),fmt,args...);logs.emplace_back(out);}}sLog;
#include "ModuleNativeGuildTrades.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
void Due(){for(auto&offer:TortoiseBots::offers)offer.readyAt=std::chrono::steady_clock::now();}
int main(){using TortoiseBots::NativeGuildTrades;Player from,to;from.guid={1};to.guid={2};players[from.guid]=&from;players[to.guid]=&to;auto&records=TortoiseBots::BotManager::Instance().records;records[from.guid]={};records[to.guid]={};Item*item=from.Add();
 TortoiseBots::BotWorldActions::map=true;CHECK(!NativeGuildTrades::Offer(&from,&to,item,5)&&!initiates);TortoiseBots::BotWorldActions::map=false;
 CHECK(!NativeGuildTrades::Offer(&from,&from,item,5));CHECK(!NativeGuildTrades::Offer(&from,&to,item,0));CHECK(!NativeGuildTrades::Offer(&from,&to,item,11));
 to.guild=2;CHECK(!NativeGuildTrades::Offer(&from,&to,item,5));to.guild=1;to.hasAI=false;CHECK(!NativeGuildTrades::Offer(&from,&to,item,5));to.hasAI=true;
 initAllowed=false;CHECK(!NativeGuildTrades::Offer(&from,&to,item,5)&&from.GetItemCount(100,true)==10&&!from.trade);initAllowed=true;
 splitAllowed=false;CHECK(!NativeGuildTrades::Offer(&from,&to,item,5)&&from.GetItemCount(100,true)==10&&!from.trade);splitAllowed=true;
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5)&&from.GetItemCount(100,true)==10&&!to.GetItemCount(100,true));CHECK(!NativeGuildTrades::Offer(&from,&to,item,5));
 NativeGuildTrades::Update();CHECK(!accepts&&TortoiseBots::offers.size()==1);Due();NativeGuildTrades::Update();CHECK(accepts==2&&from.GetItemCount(100,true)==5&&to.GetItemCount(100,true)==5&&!from.trade&&!to.trade&&TortoiseBots::offers.empty());CHECK(to.items.begin()->second->metadata==17);
 CHECK(logs.back().find("gift completed")!=std::string::npos);
 item=from.GetItemByPos(0,10);CHECK(NativeGuildTrades::Offer(&from,&to,item,5));++from.generation;NativeGuildTrades::Update();CHECK(!from.trade&&from.GetItemCount(100,true)==5&&to.GetItemCount(100,true)==5);
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));records[to.guid].masterGuid={55};NativeGuildTrades::Update();CHECK(!from.trade&&TortoiseBots::offers.empty());records[to.guid].masterGuid={};
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));from.trade->money=1;unsigned priorCancel=cancels;Due();NativeGuildTrades::Update();CHECK(from.trade&&cancels==priorCancel&&TortoiseBots::offers.empty());from.TradeCancel(true);
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));acceptAllowed=false;Due();NativeGuildTrades::Update();CHECK(!from.trade&&from.GetItemCount(100,true)==5&&to.GetItemCount(100,true)==5);acceptAllowed=true;
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));cancelOnAccept=true;Due();NativeGuildTrades::Update();CHECK(!from.trade&&logs.back().find("not completed")!=std::string::npos&&from.GetItemCount(100,true)==5);cancelOnAccept=false;
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));to.space=false;Due();NativeGuildTrades::Update();CHECK(!from.trade&&from.GetItemCount(100,true)==5&&to.GetItemCount(100,true)==5);to.space=true;
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));NativeGuildTrades::Clear();CHECK(!from.trade&&TortoiseBots::offers.empty());
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));from.TradeCancel(true);to.lifetime=false;NativeGuildTrades::Update();CHECK(TortoiseBots::offers.empty());to.lifetime=true;
 setAllowed=false;CHECK(!NativeGuildTrades::Offer(&from,&to,item,5)&&!from.trade);setAllowed=true;
 CHECK(NativeGuildTrades::Offer(&from,&to,item,5));Due();NativeGuildTrades::Update();CHECK(!from.GetItemCount(100,true)&&to.GetItemCount(100,true)==10&&logs.back().find("gift completed")!=std::string::npos);
 Group party,otherParty;Player giver,receiver;giver.guid={500};receiver.guid={501};giver.guild=receiver.guild=0;giver.group=receiver.group=&party;players[giver.guid]=&giver;players[receiver.guid]=&receiver;records[giver.guid]={};records[receiver.guid]={};Item*gift=giver.Add();
 CHECK(!NativeGuildTrades::Offer(&giver,&receiver,gift,10));
 CHECK(NativeGuildTrades::OfferParty(&giver,&receiver,gift,10));receiver.group=&otherParty;Due();NativeGuildTrades::Update();CHECK(!giver.trade&&giver.GetItemCount(100,true)==10);
 receiver.group=nullptr;CHECK(!NativeGuildTrades::OfferParty(&giver,&receiver,gift,10));receiver.group=&party;
 CHECK(NativeGuildTrades::OfferParty(&giver,&receiver,gift,10));Due();NativeGuildTrades::Update();CHECK(!giver.GetItemCount(100,true)&&receiver.GetItemCount(100,true)==10&&logs.back().find("party gift completed")!=std::string::npos);
 std::vector<std::unique_ptr<Player>> crowd;
 for(unsigned n=0;n<130;++n){auto p=std::make_unique<Player>();p->guid={100+n};players[p->guid]=p.get();records[p->guid]={};crowd.push_back(std::move(p));}
 for(unsigned n=0;n<65;++n){Player*a=crowd[2*n].get();Player*b=crowd[2*n+1].get();CHECK(NativeGuildTrades::Offer(a,b,a->Add(),10)==(n<64));}
 CHECK(TortoiseBots::offers.size()==64&&!crowd[128]->trade);
 Due();unsigned beforeAccept=accepts;NativeGuildTrades::Update();CHECK(TortoiseBots::offers.size()>=56&&TortoiseBots::offers.size()<64&&accepts-beforeAccept<=16);
 NativeGuildTrades::Clear();CHECK(TortoiseBots::offers.empty());for(auto const&p:crowd)CHECK(!p->trade);
 std::cout<<"Native guild offer checks passed: native-only split/accept, delayed completion, item conservation, failures, map/owner invalidation, altered trade preservation and clear\n";
}
