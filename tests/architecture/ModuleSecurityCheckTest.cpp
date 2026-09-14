
#include <iostream>
#include <map>
#include <optional>
#include <string>
enum{SEC_PLAYER=0,SEC_GAMEMASTER=2};
enum LootMethod{GROUP_LOOT,MASTER_LOOT,FREE_FOR_ALL};enum ItemQualities{ITEM_QUALITY_COMMON,ITEM_QUALITY_UNCOMMON,ITEM_QUALITY_RARE};
struct Session{int rank=0;int GetSecurity(){return rank;}};
struct Group{LootMethod method=GROUP_LOOT;ItemQualities threshold=ITEM_QUALITY_UNCOMMON;LootMethod GetLootMethod(){return method;}ItemQualities GetLootThreshold(){return threshold;}};
struct Player{Session* session=nullptr;Group* group=nullptr;unsigned guild=0;Session* GetSession(){return session;}Group* GetGroup(){return group;}unsigned GetGuildId(){return guild;}};
struct Event{Player* owner=nullptr;Player* GetOwner(){return owner;}};
enum class BotState{BOT_STATE_NON_COMBAT,BOT_STATE_COMBAT};
struct PlayerbotAI{Player*bot;Player*master=nullptr;Player*leader=nullptr;unsigned errors=0,strategies=0,leaderReads=0;
 Player*GetMaster(){return master;}Player*GetGroupMaster(){++leaderReads;return leader;}
 void TellError(Player*,std::string){++errors;}void ChangeStrategy(std::string,BotState){++strategies;}};
struct PlayerbotAIStorage{std::map<Player*,PlayerbotAI*> ais;static PlayerbotAIStorage&Instance(){static PlayerbotAIStorage s;return s;}PlayerbotAI*GetAI(Player*p){auto i=ais.find(p);return i==ais.end()?nullptr:i->second;}PlayerbotAI*GetAI(bool)=delete;};
struct Facade{bool random=true;bool IsRandomBot(Player*){return random;}}sRandomBotFacade;
namespace TortoiseBots{struct BotWorldActions{bool map=false;static BotWorldActions&Instance(){static BotWorldActions q;return q;}std::optional<bool>Defer(Player*,std::string,Event&){return map?std::optional<bool>(false):std::nullopt;}};}
namespace ai{struct Action{PlayerbotAI*ai;Player*bot;Action(PlayerbotAI*a,std::string):ai(a),bot(a->bot){}virtual bool isUseful(){return true;}virtual bool Execute(Event&){return true;}virtual bool isUsefulWhenStunned(){return false;}virtual bool RequiresWorldOwner()const{return false;}Player*GetMaster(){return ai->GetMaster();}std::string getName(){return "security check";}};}
#include "ModuleSecurityCheckClass.inc"
using namespace ai;
#include "ModuleSecurityCheck.inc"
#define CHECK(x)do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Session session;Group group;Player bot,master{&session},leader{&session};PlayerbotAI ai{&bot},otherAI{&master};SecurityCheckAction action(&ai);Event event;
 CHECK(action.RequiresWorldOwner());CHECK(!action.isUseful());ai.master=&master;CHECK(action.isUseful());
 master.session=nullptr;CHECK(!action.isUseful());master.session=&session;session.rank=SEC_GAMEMASTER;CHECK(!action.isUseful());session.rank=SEC_PLAYER;
 PlayerbotAIStorage::Instance().ais[&master]=&otherAI;CHECK(!action.isUseful());PlayerbotAIStorage::Instance().ais.clear();
 bot.group=&group;CHECK(!action.Execute(event));group.method=MASTER_LOOT;CHECK(!action.Execute(event));CHECK(ai.strategies==0);
 ai.leader=&leader;leader.session=nullptr;CHECK(!action.Execute(event));leader.session=&session;
 CHECK(action.Execute(event));CHECK(ai.strategies==2&&ai.errors==1);bot.guild=leader.guild=7;CHECK(action.Execute(event));CHECK(ai.strategies==2);
 group.method=FREE_FOR_ALL;bot.guild=8;CHECK(action.Execute(event));CHECK(ai.strategies==4);
 group.method=GROUP_LOOT;group.threshold=ITEM_QUALITY_RARE;CHECK(action.Execute(event));CHECK(ai.strategies==6);
 session.rank=SEC_GAMEMASTER;CHECK(action.Execute(event));CHECK(ai.strategies==6);
 sRandomBotFacade.random=false;CHECK(!action.Execute(event));sRandomBotFacade.random=true;
 TortoiseBots::BotWorldActions::Instance().map=true;CHECK(!action.Execute(event));CHECK(ai.strategies==6);
 std::cout<<"Native loot security distinguishes humans from AI, handles missing leaders and preserves guild/rank policy\n";
}
