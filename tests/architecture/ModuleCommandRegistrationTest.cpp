#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <string>
#include <vector>
enum {SEC_PLAYER=0,SEC_MODERATOR=2,SEC_ADMINISTRATOR=4};
struct ChatHandler {};
struct ChatCommand {char const*Name=nullptr;int SecurityLevel=0;bool AllowConsole=false;std::function<bool(ChatHandler*,char*)>ModuleHandler;};
namespace TortoiseBots {
namespace BotCommands {bool HandleRandomCommand(ChatHandler*,char const*){return true;}bool HandleChatCommand(ChatHandler*,char const*){return true;}bool HandleAuctionCommand(ChatHandler*,char const*){return true;}bool HandlePerformanceCommand(ChatHandler*,char const*){return true;}}
struct BotChatAdapter {std::vector<ChatCommand>GetCommands()const;};
#include "ModuleCommandRegistrations.inc"
// The extracted source closes the TortoiseBots namespace.
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){
 std::ifstream file(std::string(CORE_SOURCE_ROOT)+"/src/game/Chat/Chat.cpp");Check(bool(file),"core command source readable");std::string src((std::istreambuf_iterator<char>(file)),{});
 auto begin=src.find("static ChatCommand commandTable[] =");auto end=src.find("static std::vector<ChatCommand> scriptCommandTable;",begin);Check(begin!=src.npos&&end!=src.npos,"native root table boundaries found");src=src.substr(begin,end-begin);
 std::regex name(R"cmd(\{\s*"([^"]+)"\s*,)cmd");std::set<std::string>coreNames;
 for(auto it=std::sregex_iterator(src.begin(),src.end(),name);it!=std::sregex_iterator();++it)coreNames.insert((*it)[1]);
 TortoiseBots::BotChatAdapter adapter;std::set<std::string>moduleNames;
 for(auto const&command:adapter.GetCommands()){
  Check(command.Name&&moduleNames.insert(command.Name).second,"module commands have unique names");
  if(coreNames.count(command.Name)){std::cerr<<"Native entry shadows module command: "<<command.Name<<'\n';return 1;}
  Check(command.AllowConsole&&bool(command.ModuleHandler),"native console/module dispatch is present");
  int required=std::string(command.Name)=="bot"?SEC_PLAYER:((std::string(command.Name)=="ahbot"||std::string(command.Name)=="rndbot")?SEC_ADMINISTRATOR:SEC_MODERATOR);Check(command.SecurityLevel==required,"command security preserved");
 }
 Check(moduleNames==std::set<std::string>{"bot","ahbot","perfmon","rndbot"},"expected command families registered");
 std::cout<<"Module command registration is unshadowed and preserves security\n";
}
