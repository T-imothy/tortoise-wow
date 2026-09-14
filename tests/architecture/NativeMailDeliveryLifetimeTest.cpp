#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using uint32=unsigned;
enum{ITEM_UNCHANGED,LOG_MAIL_AH};
bool alive=true;unsigned accessesAfterTransfer=0;
struct Proto{std::string Name1="attachment";}proto;
struct Item{unsigned count=3;~Item(){alive=false;}void Check(){if(!alive){++accessesAfterTransfer;throw std::runtime_error("deleted attachment access");}}unsigned GetCount(){Check();return count;}unsigned GetEntry(){Check();return 42;}Proto*GetProto(){Check();return &proto;}void SetState(int){Check();}};
struct Player{bool merge=false;std::unique_ptr<Item>*owner;unsigned stored=0;Item*MoveItemToInventory(int,Item*item,bool){stored+=item->GetCount();if(merge){owner->reset();return nullptr;}return item;}std::string GetShortDescription(){return "recipient";}};
struct Log{unsigned calls=0,entry=0;std::string name;void out(int,char const*,char const*,char const*n,unsigned e){++calls;entry=e;name=n;}}sLog;
unsigned Deliver(Player*loadedPlayer,Item*it){int dest=0;
#include "NativeMailDeliveryLifetime.inc"
 return count;
}
int main(){for(bool merge:{false,true}){alive=true;auto item=std::make_unique<Item>();Player player{merge,&item};if(Deliver(&player,item.get())!=3||player.stored!=3||sLog.entry!=42||sLog.name!="attachment"||accessesAfterTransfer)return 1;if(merge&&item)return 1;}if(sLog.calls!=2)return 1;std::cout<<"Native mail delivery snapshots diagnostics before ordinary/merging inventory transfers\n";}
