
#include <cstdlib>
#include <charconv>
#include <iostream>
#include <sstream>
#include <string>
struct ChatCommand{};
struct ChatHandler{bool allowed=false;ChatCommand command;std::string message;
 ChatCommand const*FindCommand(char const*){return &command;}bool IsCommandAvailable(ChatCommand const&){return allowed;}
 void SendSysMessage(char const*s){message=s;}template<class...Args>void PSendSysMessage(char const*s,Args...){message=s;}
};
struct Config{bool enabled=true;unsigned diffWithPlayer=100,diffEmpty=200;}sPlayerbotAIConfig;
struct World{unsigned GetAverageDiff(){return 30;}unsigned GetMaxDiff(){return 60;}}sWorld;
namespace TortoiseBots{
enum class RandomBotAdminAction{Refresh,Upgrade,Revive,ChangeStrategy,Remove,Initialize,Teleport,Rpg,Grind};
struct BotManager{static BotManager&Instance(){static BotManager x;return x;}unsigned GetBotCount(){return 5;}};
struct RandomBotService{unsigned queued=0,updates=0,tunings=0,resets=0;std::string selector;RandomBotAdminAction action;
 bool ResetPersistentState(){++resets;return true;}
 bool ConfigureActivityController(double,double,double){++tunings;return true;}float GetActivityPercentage(){return 100;}
 static RandomBotService&Instance(){static RandomBotService s;return s;}unsigned GetTargetCount(){return 30;}unsigned GetPendingAdminCount(){return queued;}
 unsigned QueueAdminAction(RandomBotAdminAction a,std::string s){++queued;action=a;selector=s;return 1;}void RequestUpdate(){++updates;}
};namespace BotCommands{
#include "ModuleRandomAdminCommand.inc"
}}
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){using namespace TortoiseBots;ChatHandler handler;auto&service=RandomBotService::Instance();
 BotCommands::HandleRandomCommand(&handler,"remove all");Check(!service.queued,"unauthorized request rejected");
 handler.allowed=true;BotCommands::HandleRandomCommand(&handler,"remove all junk");BotCommands::HandleRandomCommand(&handler,"remove");BotCommands::HandleRandomCommand(&handler,"update junk");
 Check(!service.queued&&!service.updates,"invalid syntax has no mutation");
 sPlayerbotAIConfig.enabled=false;BotCommands::HandleRandomCommand(&handler,"remove all");Check(!service.queued,"disabled module rejected");sPlayerbotAIConfig.enabled=true;
 BotCommands::HandleRandomCommand(&handler,"remove all");Check(service.queued==1&&service.action==RandomBotAdminAction::Remove&&service.selector=="all","authorized request reaches native service");
 BotCommands::HandleRandomCommand(&handler,"update");Check(service.updates==1,"update uses service cadence");
 BotCommands::HandleRandomCommand(&handler,"stats");Check(service.queued==1,"stats is read only");
 BotCommands::HandleRandomCommand(&handler,"pid 1 2");BotCommands::HandleRandomCommand(&handler,"pid 1 2 3 junk");BotCommands::HandleRandomCommand(&handler,"pid nan 2 3");Check(!service.tunings,"malformed PID tuning has no side effects");
 sPlayerbotAIConfig.enabled=false;BotCommands::HandleRandomCommand(&handler,"pid 1 2 3");Check(!service.tunings,"disabled module cannot be tuned");sPlayerbotAIConfig.enabled=true;
 handler.allowed=false;BotCommands::HandleRandomCommand(&handler,"pid 1 2 3");Check(!service.tunings,"PID tuning respects command permissions");handler.allowed=true;
 BotCommands::HandleRandomCommand(&handler,"pid 0.05 0.001 0.05");Check(service.tunings==1,"valid PID tuning reaches the controller");
 BotCommands::HandleRandomCommand(&handler,"reset all");Check(!service.resets,"reset rejects extra arguments");
 handler.allowed=false;BotCommands::HandleRandomCommand(&handler,"reset");Check(!service.resets,"reset requires native command permission");handler.allowed=true;
 BotCommands::HandleRandomCommand(&handler,"reset");Check(service.resets==1,"reset reaches persistent store service");
 BotCommands::HandleRandomCommand(&handler,"init Bot");Check(service.action==RandomBotAdminAction::Initialize&&service.selector=="Bot","init is queued with explicit scope");
 BotCommands::HandleRandomCommand(&handler,"teleport Bot");Check(service.action==RandomBotAdminAction::Teleport,"teleport routes to native level destination");
 BotCommands::HandleRandomCommand(&handler,"rpg Bot");Check(service.action==RandomBotAdminAction::Rpg,"rpg routes to native inn destination");
 BotCommands::HandleRandomCommand(&handler,"grind Bot");Check(service.action==RandomBotAdminAction::Grind,"grind routes to native local destination");
 for(auto text:{"diff 1","diff -1 2","diff 0 2","diff 1 0","diff 4294967296 2","diff 1x 2","diff 1 2 extra"})BotCommands::HandleRandomCommand(&handler,text);
 Check(sPlayerbotAIConfig.diffWithPlayer==100&&sPlayerbotAIConfig.diffEmpty==200,"invalid latency targets cannot partially mutate configuration");
 BotCommands::HandleRandomCommand(&handler,"diff 120 240");Check(sPlayerbotAIConfig.diffWithPlayer==120&&sPlayerbotAIConfig.diffEmpty==240,"latency targets apply atomically");
 handler.allowed=false;BotCommands::HandleRandomCommand(&handler,"diff 10 20");Check(sPlayerbotAIConfig.diffWithPlayer==120,"latency tuning preserves native permissions");handler.allowed=true;
 BotCommands::HandleRandomCommand(&handler,"diff");Check(sPlayerbotAIConfig.diffWithPlayer==120,"latency report is read only");
 Check(!BotCommands::HandleRandomCommand(nullptr,"stats"),"missing handler rejected");
 std::cout<<"Native random-bot admin authorization and parsing passed\n";
}
