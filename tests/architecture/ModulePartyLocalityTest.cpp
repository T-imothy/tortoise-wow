#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <stdexcept>
using uint32=unsigned;using uint8=unsigned char;using ObjectGuid=unsigned;
struct Map{};struct Player;struct WorldSession{Player*player=nullptr;Player*GetPlayer(){return player;}};
struct WorldObject{bool world=true;Map*map=nullptr;bool IsInWorld(){return world;}Map*FindMap(){return map;}bool IsPlayer(){return true;}};
struct Group{struct Slot{ObjectGuid guid;};using MemberSlotList=std::vector<Slot>;using member_citerator=MemberSlotList::const_iterator;MemberSlotList members;MemberSlotList const&GetMemberSlots(){return members;}};
struct Player:WorldObject{unsigned guid=0;bool teleport=false,alive=true,combat=false,forbidden=false,hasAI=true,predicate=true;float x=0,health=25;unsigned cls=1,subgroup=0;Group*group=nullptr;WorldSession session;
 Player(unsigned id,Map*m):guid(id){map=m;session.player=this;}
 bool IsBeingTeleported(){return teleport;}WorldSession*GetSession(){return &session;}Group*GetGroup(){return group;}
 void read(){if(forbidden)throw std::runtime_error("foreign map gameplay state read");}
 unsigned GetClass(){return cls;}float GetHealth(){read();return health;}float GetMaxHealth(){read();return 100;}
};using Unit=Player;
struct PlayerbotAI{Player*bot;Player*master=nullptr;Player*GetGroupMaster(){return master;}static bool IsSafe(Player*,WorldObject*);bool IsSafe(WorldObject*o){return IsSafe(bot,o);}};
#include "ModulePartyIsSafe.inc"
struct PlayerbotAIStorage{static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}Player*GetAI(Player*p){return p&&p->hasAI?p:nullptr;}};
struct ObjectMgr{std::unordered_map<unsigned,Player*>players;Player*GetPlayer(unsigned g){auto i=players.find(g);return i==players.end()?nullptr:i->second;}}sObjectMgr;
struct Facade{bool IsAlive(Player*p){p->read();return p->alive;}bool IsInCombat(Player*p){p->read();return p->combat;}float getDistance2d(Player*a,Player*b){a->read();b->read();return std::abs(a->x-b->x);}bool IsDistanceLessOrEqualThan(float a,float b){return a<=b;}}sServerFacade;
struct Config{float reactDistance=30,lowHealth=30,mediumHealth=50,criticalHealth=15;}sPlayerbotAIConfig;
constexpr unsigned CLASS_PRIEST=5;
bool IsInGroup_Helper(Player*a,Player*b,bool){return a->group==b->group&&a->subgroup==b->subgroup;}
struct Base{PlayerbotAI*ai;Player*bot;std::string qualifier="low";Player*GetMaster(){return ai->master;}std::string getQualifier(){return qualifier;}std::list<ObjectGuid>members(){std::list<ObjectGuid>out;for(auto s:bot->group->members)out.push_back(s.guid);return out;}};
struct IsNearLeaderValue:Base{bool Calculate();};struct GroupBoolCountValue:Base{uint32 Calculate();};struct AoeHealValue:Base{uint8 Calculate();};struct LineTargetValue:Base{Unit*Calculate();};struct IsInCombatValue:Base{Unit*GetTarget(){return bot;}bool Calculate();};
#define AI_VALUE(T,n) members()
#define PAI_VALUE2(T,n,q) player->predicate
#include "ModulePartyNear.inc"
#include "ModulePartyCount.inc"
#include "ModulePartyAoe.inc"
#include "ModulePartyLine.inc"
#include "ModulePartyCombat.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Map map,other;Player bot(1,&map),local(2,&map),remote(3,&other),third(4,&map);Group group;group.members={{2},{3},{1},{4},{99}};bot.group=local.group=remote.group=third.group=&group;PlayerbotAI ai{&bot,&local};remote.forbidden=true;remote.combat=true;sObjectMgr.players={{1,&bot},{2,&local},{3,&remote},{4,&third}};
 IsNearLeaderValue near;near.ai=&ai;near.bot=&bot;CHECK(near.Calculate());ai.master=&remote;CHECK(!near.Calculate());ai.master=&local;local.teleport=true;CHECK(!near.Calculate());local.teleport=false;local.x=31;CHECK(!near.Calculate());local.x=0;ai.master=&bot;CHECK(near.Calculate());ai.master=nullptr;CHECK(!near.Calculate());ai.master=&local;
 GroupBoolCountValue count;count.ai=&ai;count.bot=&bot;CHECK(count.Calculate()==3);local.predicate=false;CHECK(count.Calculate()==2);third.hasAI=false;CHECK(count.Calculate()==1);third.hasAI=true;local.predicate=true;
 AoeHealValue aoe;aoe.ai=&ai;aoe.bot=&bot;CHECK(aoe.Calculate()==3);third.x=31;CHECK(aoe.Calculate()==2);third.x=0;third.alive=false;CHECK(aoe.Calculate()==2);third.alive=true;third.world=false;third.forbidden=true;CHECK(aoe.Calculate()==2);third.world=true;third.forbidden=false;bot.cls=CLASS_PRIEST;third.subgroup=1;CHECK(aoe.Calculate()==2);bot.cls=1;
 LineTargetValue line;line.ai=&ai;line.bot=&bot;CHECK(line.Calculate()==&local);ai.master=&remote;CHECK(line.Calculate()==nullptr);ai.master=&local;group.members={{2},{4},{3},{1}};CHECK(line.Calculate()==&third);third.teleport=true;third.forbidden=true;CHECK(line.Calculate()==&local);third.teleport=false;third.forbidden=false;
 IsInCombatValue combat;combat.ai=&ai;combat.bot=&bot;CHECK(!combat.Calculate());local.combat=true;CHECK(combat.Calculate());local.x=31;CHECK(!combat.Calculate());local.x=0;local.teleport=true;local.forbidden=true;CHECK(!combat.Calculate());local.teleport=false;local.forbidden=false;
 local.session.player=nullptr;CHECK(!near.Calculate());local.session.player=&local;
 std::cout<<"Actual party decisions passed: counts, map instances, transfers, session ownership, healer subgroups and local combat/follow range\n";
}
