
#include <iostream>
#include <map>
#include <optional>
#include <string>
struct Event{};
struct Player{bool group=false;bool GetGroup(){return group;}};
struct PlayerbotAI{Player* bot;Player* leader=nullptr;unsigned lookups=0;bool real=false,nearby=false;
 Player* GetGroupMaster(){++lookups;return leader;}bool IsRealPlayer(){return real;}bool HasPlayerNearby(){return nearby;}};
struct PlayerbotAIStorage{std::map<Player*,PlayerbotAI*> ais;static PlayerbotAIStorage& Instance(){static PlayerbotAIStorage s;return s;}
 PlayerbotAI* GetAI(Player* p){auto i=ais.find(p);return i==ais.end()?nullptr:i->second;}};
struct Facade{bool random=true,result=true;unsigned processed=0;bool IsRandomBot(Player*){return random;}bool ProcessBot(Player*){++processed;return result;}}sRandomBotFacade;
namespace TortoiseBots{struct BotWorldActions{bool map=false;static BotWorldActions&Instance(){static BotWorldActions q;return q;}
 std::optional<bool> Defer(Player*,std::string const&,Event const&){return map?std::optional<bool>(false):std::nullopt;}};}
namespace ai{class Action{public:PlayerbotAI* ai;Player* bot;Action(PlayerbotAI* a,std::string):ai(a),bot(a->bot){}
 virtual bool RequiresWorldOwner()const{return false;}virtual bool Execute(Event&)=0;virtual bool isUseful(){return true;}std::string getName(){return "random bot update";}};}
#define AI_VALUE(type,name) true
#include "ModuleRandomUpdateLeader.inc"
#define CHECK(x) do{if(!(x)){std::cerr<<__LINE__<<": " #x "\n";return 1;}}while(0)
int main(){Player bot,leader;PlayerbotAI ai{&bot},leaderAI{&leader};ai::RandomBotUpdateAction action(&ai);Event event;
 CHECK(action.RequiresWorldOwner());CHECK(action.Execute(event));CHECK(sRandomBotFacade.processed==1&&ai.lookups==0);
 bot.group=true;ai.leader=&leader;CHECK(action.Execute(event));CHECK(sRandomBotFacade.processed==1&&ai.lookups==1); // Human leader has no AI.
 PlayerbotAIStorage::Instance().ais[&leader]=&leaderAI;leaderAI.real=true;CHECK(action.Execute(event));CHECK(sRandomBotFacade.processed==1);
 leaderAI.real=false;CHECK(action.Execute(event));CHECK(sRandomBotFacade.processed==2); // Autonomous group remains eligible.
 ai.leader=nullptr;CHECK(action.Execute(event));CHECK(sRandomBotFacade.processed==3);
 ai.nearby=true;CHECK(action.Execute(event));CHECK(sRandomBotFacade.processed==3);ai.nearby=false;
 sRandomBotFacade.random=false;CHECK(!action.Execute(event));CHECK(sRandomBotFacade.processed==3);sRandomBotFacade.random=true;
 TortoiseBots::BotWorldActions::Instance().map=true;CHECK(!action.Execute(event));CHECK(sRandomBotFacade.processed==3);
 TortoiseBots::BotWorldActions::Instance().map=false;sRandomBotFacade.result=false;CHECK(!action.Execute(event));CHECK(sRandomBotFacade.processed==4);
 std::cout<<"Native random maintenance preserves human leaders, resolves once, and respects the world owner\n";
}
