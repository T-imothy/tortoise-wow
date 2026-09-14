#include <algorithm>
#include <atomic>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <unordered_map>
#include <vector>
using uint32=unsigned;
struct AuctionHouseEntry{unsigned team;};AuctionHouseEntry ally{1},horde{2},neutral{0};
struct AuctionEntry{unsigned Id=0,buyout=0,itemCount=1,itemTemplate=7;AuctionHouseEntry const*auctionHouseEntry=&ally;};
struct AuctionHouseObject{std::vector<AuctionEntry>items;};AuctionHouseObject house;
struct Store{unsigned GetNumRows(){return 3;}AuctionHouseEntry const*LookupEntry(unsigned n){return n==2?nullptr:(n?&horde:&ally);}}sAuctionHouseStore;
struct AuctionMgr{AuctionHouseObject*GetAuctionsMap(AuctionHouseEntry const*){return &house;}}sAuctionMgr;
bool failure=false;unsigned copies=0;
namespace TortoiseBots{std::vector<AuctionEntry>CopyAuctionEntries(AuctionHouseObject&h){++copies;if(failure)throw std::runtime_error("snapshot failure");return h.items;}}
struct AuctionHouseMgr{static unsigned GetAuctionHouseTeam(AuctionHouseEntry const*e){return e->team;}};
enum{CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_AUCTION};struct World{std::atomic<bool>twoSide=false;bool getConfig(int){return twoSide.load();}}sWorld;
struct Player{unsigned team;unsigned GetTeam(){return team;}};
struct RandomBotFacade{
 using AuctionPriceMap=std::unordered_map<uint32,std::vector<AuctionEntry>>;
 std::shared_ptr<AuctionPriceMap const>ahMirror=std::make_shared<AuctionPriceMap>();std::mutex m_ahActionMutex;
 void LoadAuctionPrices();std::vector<AuctionEntry>GetAhPrices(uint32)const;std::vector<AuctionEntry>GetAhPrices(uint32,uint32)const;std::vector<AuctionEntry>GetAhPrices(uint32,Player*)const;
};
#include "ModuleAuctionPricePublish.inc"
#include "ModuleAuctionPriceRead.inc"
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){RandomBotFacade facade;CHECK(facade.GetAhPrices(7).empty());
 for(unsigned n=0;n<80;++n)house.items.push_back({n+1,80-n,1,7,&ally});house.items.push_back({99,0,1,7,&ally});house.items.push_back({100,1,0,7,&ally});
 facade.LoadAuctionPrices();auto retained=facade.GetAhPrices(7);CHECK(retained.size()==64&&copies==1);for(auto const&e:retained)CHECK(e.buyout<=64&&e.itemCount==1);CHECK(facade.GetAhPrices(999).empty());
 house.items={{1,100,1,7,&ally},{2,200,1,7,&horde},{3,300,1,7,&neutral}};facade.LoadAuctionPrices();Player a{1},h{2};CHECK(facade.GetAhPrices(7,&a).size()==2&&facade.GetAhPrices(7,&h).size()==2&&facade.GetAhPrices(7,(Player*)nullptr).size()==3);
 sWorld.twoSide=true;CHECK(facade.GetAhPrices(7,&a).size()==3);sWorld.twoSide=false;
 failure=true;bool threw=false;try{facade.LoadAuctionPrices();}catch(std::runtime_error const&){threw=true;}CHECK(threw&&facade.GetAhPrices(7).size()==3);failure=false;CHECK(retained.size()==64&&retained.front().buyout<=64);
 house.items={{1,100,1,7,&ally},{2,100,1,7,&horde},{3,100,1,7,&neutral}};facade.LoadAuctionPrices();
 std::atomic<bool> start=false,ok=true;std::vector<std::thread> readers;
 for(unsigned n=0;n<8;++n)readers.emplace_back([&]{while(!start.load())std::this_thread::yield();for(unsigned k=0;k<2000;++k){auto view=facade.GetAhPrices(7);if(view.size()!=3||view[0].buyout!=view[1].buyout||view[1].buyout!=view[2].buyout)ok=false;auto filtered=facade.GetAhPrices(7,&a);if(filtered.size()!=2||filtered[0].buyout!=filtered[1].buyout)ok=false;}});
 start=true;for(unsigned n=0;n<1000;++n){for(auto&e:house.items)e.buyout=n+1;facade.LoadAuctionPrices();}for(auto&t:readers)t.join();CHECK(ok);
 std::cout<<"Native auction snapshots preserve bounded lowest-price/faction/deduplication policy across concurrent publication and refresh failure\n";
}
