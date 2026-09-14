#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <unordered_set>
#include <atomic>
#include <thread>
using uint32=unsigned;
enum {HIGHGUID_PLAYER};
struct ObjectGuid{unsigned id=0;ObjectGuid()=default;ObjectGuid(int,unsigned n):id(n){}unsigned GetCounter()const{return id;}bool IsEmpty()const{return !id;}bool operator<(ObjectGuid const&o)const{return id<o.id;}};
struct Player;
struct Session{bool network=false;Player*player=nullptr;bool HasNetworkTransport(){return network;}bool IsHeadless(){return !network;}Player*GetPlayer(){return player;}};
constexpr unsigned SOCIAL_FLAG_FRIEND=1,SOCIAL_FLAG_IGNORED=2;
struct FriendInfo{unsigned Flags=0;};
struct PlayerSocial{std::map<ObjectGuid,FriendInfo>m_playerSocialMap;bool HasFriend(ObjectGuid guid){auto i=m_playerSocialMap.find(guid);return i!=m_playerSocialMap.end()&&(i->second.Flags&SOCIAL_FLAG_FRIEND);}std::vector<ObjectGuid>GetFriendGuids()const;};
#include "NativeSocialFriendGuids.inc"
struct Guild{ObjectGuid leader;ObjectGuid GetLeaderGuid(){return leader;}};
struct GuildMgr{std::map<unsigned,Guild>guilds;Guild*GetGuildById(unsigned id){auto i=guilds.find(id);return i==guilds.end()?nullptr:&i->second;}}sGuildMgr;
struct ObjectMgr{unsigned GetPlayerAccountIdByGUID(ObjectGuid guid){return guid.id;}}sObjectMgr;
struct Config{bool IsInRandomAccountList(unsigned account){return account==999;}}sPlayerbotAIConfig;
struct Player{unsigned guid;unsigned guild=0;unsigned GetGuildId(){return guild;}unsigned GetGUIDLow(){return guid;}bool world=true;Session*session=nullptr;PlayerSocial social;bool IsInWorld(){return world;}Session*GetSession(){return session;}ObjectGuid GetObjectGuid(){return {HIGHGUID_PLAYER,guid};}ObjectGuid getObjectGuid(){return GetObjectGuid();}PlayerSocial*GetSocial(){return &social;}int GetTeam(){return 1;}};
struct World{std::map<unsigned,Session*>sessions;auto const&GetAllSessions(){return sessions;}}sWorld;
struct Accessor{std::map<unsigned,Player*>live;Player*FindPlayer(ObjectGuid guid){auto i=live.find(guid.id);return i==live.end()?nullptr:i->second;}}sObjectAccessor;
namespace TortoiseBots {
struct BotWorldActions{static bool map;static bool IsMapExecution(){return map;}};bool BotWorldActions::map=false;
struct BotRecord{bool random=true;ObjectGuid masterGuid;};
struct BotManager{std::vector<Player*>bots;std::map<unsigned,BotRecord>records;static BotManager&Instance(){static BotManager s;return s;}auto GetAllBots(){return bots;}BotRecord*FindBot(ObjectGuid guid){auto i=records.find(guid.id);return i==records.end()?nullptr:&i->second;}};
}
struct RandomBotFacade{
#include "ModuleSocialSnapshotDeclaration.inc"
std::shared_ptr<SocialSnapshot const> socialSnapshot=std::make_shared<SocialSnapshot>();
std::map<unsigned,Player*>players;void SyncNativePlayers();auto const&GetPlayers(){return players;}bool IsRandomBot(Player*p){auto*r=TortoiseBots::BotManager::Instance().FindBot(p->GetObjectGuid());return r&&r->random;}}sRandomBotFacade;
#include "ModuleSocialPopulation.inc"
struct Channel{std::set<unsigned>members;bool HasMember(ObjectGuid guid){return members.count(guid.id)!=0;}};
struct ChannelMgr{std::map<std::string,Channel*>channels;bool sentPacket=false;Channel*GetChannel(std::string const&name,Player*,bool send){sentPacket|=send;auto i=channels.find(name);return i==channels.end()?nullptr:i->second;}}channels;
bool managerAvailable=true;ChannelMgr*channelMgr(int){return managerAvailable?&channels:nullptr;}
enum class ActivePiorityType{IN_EMPTY_SERVER,PLAYER_FRIEND,OTHER};
class PlayerbotAI{public:Player*bot;bool friendFlag=false;bool HasRealPlayerMaster(){return false;}bool IsInRealGuild();ActivePiorityType SocialPriority(){
#include "ModuleSocialPriority.inc"
return ActivePiorityType::OTHER;}bool IsPlayerFriend(){return friendFlag;}void SetPlayerFriend(bool value){friendFlag=value;}bool HasPlayerRelation();bool ChannelHasRealPlayer(std::string);};
#include "ModuleSocialGuild.inc"
#include "ModuleSocialRelation.inc"
#include "ModuleChannelPresence.inc"
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){Player human{1},owned{2},random{3},controlled{4},offline{5};Session network{true,&human},headless{false,&owned};human.session=&network;owned.session=random.session=controlled.session=offline.session=&headless;offline.world=false;
 sWorld.sessions={{1,&network},{2,&headless},{3,nullptr}};
 auto&manager=TortoiseBots::BotManager::Instance();manager.bots={&owned,&random,&controlled,&offline};manager.records={{2,{false,{}}},{3,{true,{}}},{4,{true,{HIGHGUID_PLAYER,1}}},{5,{false,{}}}};
 sRandomBotFacade.SyncNativePlayers();Check(sRandomBotFacade.players.size()==3&&sRandomBotFacade.players.count(1)&&sRandomBotFacade.players.count(2)&&sRandomBotFacade.players.count(4),"view contains humans and controlled companions, excludes autonomous and offline bots");
 for(auto*p:{&human,&owned,&random,&controlled})sObjectAccessor.live[p->guid]=p;
 human.social.m_playerSocialMap[{HIGHGUID_PLAYER,3}]={SOCIAL_FLAG_FRIEND};PlayerbotAI ai{&random};Check(ai.HasPlayerRelation()&&ai.friendFlag,"real human friendship protects autonomous bot activity");
 ai.friendFlag=false;sObjectAccessor.live.erase(1);Check(!ai.HasPlayerRelation(),"removed human in an older view is resolved by current GUID before social access");sObjectAccessor.live[1]=&human;
 Channel world,trade;channels.channels={{"world",&world},{"trade",&trade}};trade.members.insert(1);
 Check(!ai.ChannelHasRealPlayer("world"),"human in another channel is not an audience");world.members.insert(1);Check(ai.ChannelHasRealPlayer("world"),"actual network member is an audience");
 network.network=false;Check(!ai.ChannelHasRealPlayer("world"),"headless member is not a real-player audience");network.network=true;human.world=false;Check(!ai.ChannelHasRealPlayer("world"),"offline channel entry is not an audience");human.world=true;
 Check(!ai.ChannelHasRealPlayer("missing")&&!channels.sentPacket,"unknown channel lookup produces no not-member packet or new channel");managerAvailable=false;Check(!ai.ChannelHasRealPlayer("world"),"missing faction manager handled");

 // Native social copy excludes ignored-only entries and is independent of mutation.
 human.social.m_playerSocialMap[{HIGHGUID_PLAYER,6}]={SOCIAL_FLAG_IGNORED};
 human.social.m_playerSocialMap[{HIGHGUID_PLAYER,7}]={SOCIAL_FLAG_FRIEND|SOCIAL_FLAG_IGNORED};
 auto friends=human.social.GetFriendGuids();Check(friends.size()==2,"friend query preserves combined flags and excludes ignore-only");
 random.guild=11;owned.guild=12;controlled.guild=13;sGuildMgr.guilds={{11,{{HIGHGUID_PLAYER,123}}},{12,{{HIGHGUID_PLAYER,999}}},{13,{{HIGHGUID_PLAYER,0}}}};
 sRandomBotFacade.SyncNativePlayers();auto before=sRandomBotFacade.GetSocialSnapshot();
 Check(before->hasControlledPopulation&&before->friendGuids.count(3)&&before->friendGuids.count(7)&&!before->friendGuids.count(6),"snapshot contains native friend union");
 Check(before->realGuildIds.count(11)&&!before->realGuildIds.count(12)&&!before->realGuildIds.count(13),"native real guild classification excludes random and missing leader accounts");
 Check(ai.IsInRealGuild(),"world real-guild query follows native leader classification");
 TortoiseBots::BotWorldActions::map=true;sGuildMgr.guilds.clear();Check(ai.IsInRealGuild(),"map guild priority uses captured IDs without native guild lookup");Check(ai.SocialPriority()==ActivePiorityType::PLAYER_FRIEND,"map friend priority uses immutable union");TortoiseBots::BotWorldActions::map=false;
 random.guild=0;
 ai.friendFlag=false;TortoiseBots::BotWorldActions::map=true;sObjectAccessor.live.clear();Check(ai.HasPlayerRelation(),"map relation reads immutable facts without cross-map lookup");TortoiseBots::BotWorldActions::map=false;
 human.social.m_playerSocialMap.clear();sRandomBotFacade.SyncNativePlayers();Check(before->friendGuids.count(3)&&sRandomBotFacade.GetSocialSnapshot()->friendGuids.empty()&&friends.size()==2,"old readers retain a complete prior snapshot");
 std::atomic<bool>stop{false},bad{false};std::thread reader([&]{while(!stop){auto snapshot=sRandomBotFacade.GetSocialSnapshot();if(snapshot->friendGuids.count(3)!=snapshot->friendGuids.count(7))bad=true;}});
 for(unsigned i=0;i<300;++i){human.social.m_playerSocialMap.clear();if(i%2){human.social.m_playerSocialMap[{HIGHGUID_PLAYER,3}]={SOCIAL_FLAG_FRIEND};human.social.m_playerSocialMap[{HIGHGUID_PLAYER,7}]={SOCIAL_FLAG_FRIEND};}sRandomBotFacade.SyncNativePlayers();}
 stop=true;reader.join();Check(!bad,"concurrent readers never observe partial social publication");
 manager.bots.clear();sWorld.sessions.clear();sRandomBotFacade.SyncNativePlayers();Check(sRandomBotFacade.players.empty()&&!sRandomBotFacade.GetSocialSnapshot()->hasControlledPopulation&&sRandomBotFacade.GetSocialSnapshot()->friendGuids.empty(),"refresh removes stale population entries");
 TortoiseBots::BotWorldActions::map=true;Check(ai.SocialPriority()==ActivePiorityType::IN_EMPTY_SERVER,"empty published population retains native priority order");TortoiseBots::BotWorldActions::map=false;
 std::cout<<"Native social population, friendship and channel audience identity passed\n";
}
