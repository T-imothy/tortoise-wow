#include <iostream>
#include <map>
#include <optional>
#include <string>
using uint32=unsigned;using uint8=unsigned char;
enum{ALLIANCE=1,LANG_COMMON=1,LANG_ORCISH=2,LANG_UNIVERSAL=0,GR_RIGHT_DEMOTE=1,GR_RIGHT_PROMOTE=2,GR_RIGHT_INVITE=4};
enum class PlayerbotSecurityLevel{PLAYERBOT_SECURITY_GUILD};
struct WorldPacket{void rpos(int){}WorldPacket& operator>>(std::string& s){s="inviter";return *this;}};
bool acceptNative=true,leaveNative=true,admitMember=true;unsigned accepts=0,declines=0,leaves=0,notes=0,logs=0;
struct Player;struct Session{Player*player;void HandleGuildAcceptOpcode(WorldPacket&);void HandleGuildDeclineOpcode(WorldPacket&){++declines;}void HandleGuildLeaveOpcode(WorldPacket&);};
struct Player{unsigned guild=0,invited=10;Session session{this};unsigned GetGuildId(){return guild;}unsigned GetGuildIdInvited(){return invited;}unsigned GetObjectGuid(){return 1;}unsigned getObjectGuid(){return 1;}unsigned GetGUIDLow(){return 1;}unsigned GetTeam(){return ALLIANCE;}char const* GetName(){return "fixture";}Session* GetSession(){return &session;}void Say(std::string,int){}};
struct MemberSlot{unsigned RankId=1;};
struct Guild{unsigned size=5;bool member=true;MemberSlot slot;unsigned GetMemberSize(){return size;}std::string GetName(){return "guild";}MemberSlot*GetMemberSlot(unsigned){return member?&slot:nullptr;}bool rights=true;unsigned GetLeaderGuid(){return 1;}bool HasRankRight(unsigned,unsigned){return rights;}void BroadcastToGuild(Session*,std::string,int){}};
Guild guild;struct GuildMgr{Guild*current=&guild;Guild*GetGuildById(unsigned id){return id==10?current:nullptr;}}sGuildMgr;
void Session::HandleGuildAcceptOpcode(WorldPacket&){++accepts;if(acceptNative){player->guild=player->invited;guild.member=admitMember;}}
void Session::HandleGuildLeaveOpcode(WorldPacket&){++leaves;if(leaveNative){player->guild=0;sGuildMgr.current=nullptr;}}
Player inviter;struct ObjectAccessor{static Player*FindPlayerByName(char const*){return &inviter;}};
bool normalizePlayerName(std::string&){return true;}
struct Security{bool allow=true;bool CheckLevelFor(PlayerbotSecurityLevel,bool,Player*,bool){return allow;}};
struct AI{Security security;Security*GetSecurity(){return &security;}void TellError(Player*,std::string){}bool HasActivePlayerMaster(){return false;}};
struct PlayerbotAIStorage{static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage x;return x;}AI*GetAI(Player*){return nullptr;}};
struct Config{float spellDistance=30;bool inviteChat=false;unsigned guildMaxBotLimit=1000;template<class...T>void logEvent(T...){++logs;}}sPlayerbotAIConfig;
struct Facade{float getDistance2d(Player*,Player*){return 1000;}}sServerFacade;
struct Random{bool IsFreeBot(Player*){return true;}}sRandomBotFacade;
unsigned urand(unsigned a,unsigned){return a;}
struct TalentSpec{static void SetPublicNote(Player*){++notes;}};
#define BOT_TEXT2(text,placeholders) std::string(text)
struct Event{Player*owner=nullptr;WorldPacket packet;Player*GetOwner(){return owner;}WorldPacket&GetPacket(){return packet;}};
struct Base{Player*bot;AI*ai;std::string getName(){return "guild";}Player*GetMaster(){return nullptr;}};
struct GuildAcceptAction:Base{bool Execute(Event&);};struct GuildLeaveAction:Base{bool Execute(Event&);};struct GuildManageNearbyAction:Base{bool isUseful();};
namespace TortoiseBots{enum class BotActivity{Idle,Grinding,PlayerMaster,Other};struct BotActivityLeaseManager{static BotActivityLeaseManager&Instance(){static BotActivityLeaseManager x;return x;}BotActivity activity=BotActivity::Idle;BotActivity GetActivity(unsigned){return activity;}};}
namespace TortoiseBots {struct BotWorldActions {static BotWorldActions&Instance(){static BotWorldActions x;return x;}std::optional<bool>Defer(Player*,std::string,Event&){return std::nullopt;}};}
#include "ModuleGuildAccept.inc"
#include "ModuleGuildManageEligibility.inc"
#include "ModuleGuildLeave.inc"
struct GuildMembershipQueries{
#include "ModuleGuildMembershipQueries.inc"
};
int main(){bool fail=false;Player bot;AI ai;Event event;GuildAcceptAction accept{{&bot,&ai}};GuildLeaveAction leave{{&bot,&ai}};GuildManageNearbyAction manage{{&bot,&ai}};inviter.guild=10;
 sGuildMgr.current=nullptr;if(accept.Execute(event)||accepts||notes||logs)fail=true;
 sGuildMgr.current=&guild;bot.invited=20;if(accept.Execute(event)||accepts||declines)fail=true;bot.invited=10;
 acceptNative=false;if(accept.Execute(event)||accepts!=1||notes||logs)fail=true;
 acceptNative=true;admitMember=false;if(accept.Execute(event)||notes||logs)fail=true;bot.guild=0;
 admitMember=true;if(!accept.Execute(event)||notes!=1||logs!=1||bot.guild!=10)fail=true;
 if(!manage.isUseful())fail=true;guild.member=false;if(manage.isUseful())fail=true;guild.member=true;sGuildMgr.current=nullptr;if(manage.isUseful()||leave.Execute(event)||leaves)fail=true;
 sGuildMgr.current=&guild;leaveNative=false;if(leave.Execute(event)||leaves!=1||logs!=1)fail=true;
 leaveNative=true;if(!leave.Execute(event)||leaves!=2||logs!=2||bot.guild)fail=true;
 GuildMembershipQueries queries;bot.guild=10;sGuildMgr.current=nullptr;
 if(queries.MemberGuild(&bot)||queries.HasGuildRight(&bot,1)||queries.IsGuildLeader(&bot)||queries.GetRankId(&bot)!=255||!queries.GuildIsFull(10))fail=true;
 sGuildMgr.current=&guild;guild.member=false;if(queries.MemberGuild(&bot)||queries.HasGuildRight(&bot,1)||queries.GetRankId(&bot)!=255)fail=true;
 guild.member=true;guild.rights=false;if(queries.HasGuildRight(&bot,1))fail=true;guild.rights=true;
 if(!queries.HasGuildRight(&bot,1)||!queries.IsGuildLeader(&bot)||queries.GetRankId(&bot)!=1||queries.GuildIsFull(10))fail=true;
 if(queries.MemberGuild(nullptr)||queries.HasGuildRight(nullptr,1)||queries.IsGuildLeader(nullptr))fail=true;
 if(fail){std::cerr<<"Native guild expiry/rejection/admission/result contract failed\n";return 1;}
 std::cout<<"Native guild actions reject missing/superseded invites, verify admission and preserve rejection/destruction outcomes\n";
}
