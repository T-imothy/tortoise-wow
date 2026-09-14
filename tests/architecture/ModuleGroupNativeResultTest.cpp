#include <iostream>
#include <string>
using uint32=unsigned;
struct Group{bool raid=false,bg=false;unsigned count=1;bool IsRaidGroup(){return raid;}bool isBGGroup(){return bg;}unsigned GetMembersCount(){return count;}void ConvertToRaid(){raid=true;}};
struct WorldPacket{template<class T>WorldPacket&operator<<(T const&){return *this;}};
struct Player;struct Session{Player*player;Player*target=nullptr;bool accept=true;Group*created=nullptr;Player*GetPlayer(){return player;}void HandleGroupInviteOpcode(WorldPacket&);};
struct Player{std::string name="fixture";Group*group=nullptr,*invite=nullptr,*original=nullptr;Session session{this};bool sessionLive=true;Session*GetSession(){return sessionLive?&session:nullptr;}char const*GetName(){return name.c_str();}Group*GetGroup(){return group;}Group*GetGroupInvite(){return invite;}Group*GetOriginalGroup(){return original;}};
void Session::HandleGroupInviteOpcode(WorldPacket&){if(!accept)return;Group*g=player->group;if(g&&g->bg)g=player->original;if(!g)g=player->invite=created;target->invite=g;}
enum class PlayerbotSecurityLevel{PLAYERBOT_SECURITY_INVITE};struct Security{bool CheckLevelFor(PlayerbotSecurityLevel,bool,Player*){return true;}};
struct AI{Security security;Security*GetSecurity(){return &security;}bool IsRealPlayer(){return false;}};
struct PlayerbotAIStorage{AI ai;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage x;return x;}AI*GetAI(Player*){return &ai;}};
struct InviteToGroupAction{AI*ai;bool Invite(Player*,Player*);};
#include "ModuleGroupInviteResult.inc"
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){AI ai;InviteToGroupAction action{&ai};Player inviter,target;Group pending,existing,bg;inviter.session.target=&target;inviter.session.created=&pending;
 CHECK(!action.Invite(nullptr,&target));CHECK(!action.Invite(&inviter,nullptr));CHECK(!action.Invite(&inviter,&inviter));target.sessionLive=false;CHECK(!action.Invite(&inviter,&target));target.sessionLive=true;
 inviter.session.accept=false;CHECK(!action.Invite(&inviter,&target));inviter.session.accept=true;CHECK(action.Invite(&inviter,&target));CHECK(target.invite==&pending);
 CHECK(!action.Invite(&inviter,&target));target.invite=nullptr;inviter.group=&existing;CHECK(action.Invite(&inviter,&target));CHECK(target.invite==&existing);
 target.invite=nullptr;inviter.group=&bg;bg.bg=true;inviter.original=&existing;CHECK(action.Invite(&inviter,&target));CHECK(target.invite==&existing);
 target.invite=nullptr;target.session.player=&inviter;CHECK(!action.Invite(&inviter,&target));
 std::cout<<"Native invite rejection, pending/new/existing/original group identity and session ownership passed\n";
}
