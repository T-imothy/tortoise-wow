#include <iostream>
struct Map{};struct Player;
struct WorldObject{Map*map;bool world=true;virtual bool IsPlayer(){return false;}bool IsInWorld(){return world;}Map*FindMap(){return map;}virtual~WorldObject()=default;};
struct Session{Player*player;Player*GetPlayer(){return player;}};
struct Player:WorldObject{bool teleport=false;Session*session=nullptr;bool IsPlayer()override{return true;}bool IsBeingTeleported(){return teleport;}Session*GetSession(){return session;}};
struct PlayerbotAI{static bool IsSafe(Player*,WorldObject*);};
#include "ModuleNativeMapSafety.inc"
int main(){bool fail=false;Map map,other;Player source,target,foreign;source.map=&map;target.map=&map;foreign.map=&other;Session targetSession{&target};target.session=&targetSession;WorldObject creature;creature.map=&map;
 if(!PlayerbotAI::IsSafe(&source,&target)||!PlayerbotAI::IsSafe(&source,&creature)||PlayerbotAI::IsSafe(nullptr,&target)||PlayerbotAI::IsSafe(&source,nullptr)||PlayerbotAI::IsSafe(&source,&foreign))fail=true;
 target.teleport=true;if(PlayerbotAI::IsSafe(&source,&target))fail=true;target.teleport=false;
 target.session=nullptr;if(PlayerbotAI::IsSafe(&source,&target))fail=true;target.session=&targetSession;
 targetSession.player=nullptr;if(PlayerbotAI::IsSafe(&source,&target))fail=true;targetSession.player=&source;if(PlayerbotAI::IsSafe(&source,&target))fail=true;targetSession.player=&target;
 target.world=false;if(PlayerbotAI::IsSafe(&source,&target))fail=true;target.world=true;
 source.world=false;if(PlayerbotAI::IsSafe(&source,&creature))fail=true;source.world=true;
 source.teleport=true;if(PlayerbotAI::IsSafe(&source,&creature))fail=true;source.teleport=false;
 source.map=nullptr;creature.map=nullptr;if(PlayerbotAI::IsSafe(&source,&creature))fail=true;
 if(fail){std::cerr<<"Native map/session ownership eligibility failed\n";return 1;}std::cout<<"Same-map queries reject removed, transferring, missing-session and reassigned Player targets\n";
}
