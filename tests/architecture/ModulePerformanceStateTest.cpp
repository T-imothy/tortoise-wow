#include <algorithm>
#include <atomic>
#include <chrono>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <sstream>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <vector>
using uint32=std::uint32_t;using uint64=std::uint64_t;
using std::count;
#define UI64FMTD "%" PRIu64
#define CMANGOS
class PlayerbotAI;
#include "ModulePerformanceTypes.inc"
struct Context {PerformanceStack performanceStack;};
struct MockPlayer {uint32 GetMapId(){return 1;}uint32 GetInstanceId(){return 1;}};
class PlayerbotAI {public:Context ctx;MockPlayer player;Context*GetAiObjectContext(){return &ctx;}MockPlayer*GetBot(){return &player;}};
struct Config {bool perfMonEnabled=true;}sPlayerbotAIConfig;
struct Log {std::atomic<unsigned>calls{0};template<class...T>void outString(char const*f,T...args){char buf[4096];std::snprintf(buf,sizeof(buf),f,args...);std::string text=buf;if(text.find("nan")!=text.npos||text.find("inf")!=text.npos){std::cerr<<text;std::abort();}++calls;}}sLog;
#define sPerformanceMonitor bot_perf::PerformanceMonitor::instance()
struct ChatCommand {};
struct ChatHandler {bool allowed=false;ChatCommand command;std::string message;ChatCommand const*FindCommand(char const*){return &command;}bool IsCommandAvailable(ChatCommand const&){return allowed;}void SendSysMessage(char const*m){message=m;}};
#include "ModulePerformanceMethods.inc"
void Check(bool b,char const*m){if(!b){std::cerr<<m<<'\n';std::exit(1);}}
int main(){
 PerformanceData direct;direct.count=UINT32_MAX;PerformanceStack nested{"same","same"};
 {PerformanceMonitorOperation op(direct,"same",&nested);sPlayerbotAIConfig.perfMonEnabled=false;}
 Check(direct.count==uint64(UINT32_MAX)+1,"counter exceeds 32 bits");Check(nested.size()==1,"disabled completion preserves outer recursive frame");
 auto&monitor=bot_perf::PerformanceMonitor::instance();Check(!monitor.start(PERF_MON_ACTION,"off"),"disabled start returns no operation");sPlayerbotAIConfig.perfMonEnabled=true;{auto lazy=monitor.start(PERF_MON_ACTION,"lazy",nullptr,99,7);Check(bool(lazy),"monitoring initializes new map buckets without legacy manager");}monitor.Init(1,1);monitor.Reset();monitor.PrintStats(true,true,true);
 std::vector<std::thread> workers;
 for(unsigned i=0;i<4;++i)workers.emplace_back([&,i]{PerformanceStack stack;for(unsigned j=0;j<1200;++j){monitor.Init(1,i+1);auto outer=monitor.start(PERF_MON_TOTAL,"PlayerbotAI::UpdateAI ",&stack,1,i+1);{auto inner=monitor.start(PERF_MON_ACTION,"same",&stack,1,i+1);auto recursive=monitor.start(PERF_MON_ACTION,"same",&stack,1,i+1);}Check(stack.size()==1,"nested same-name frames balanced");}Check(stack.empty(),"worker stack balanced");});
 for(unsigned i=0;i<150;++i){monitor.Reset();monitor.PrintStats(i%2,true,true);}
 for(auto&thread:workers)thread.join();monitor.PrintStats();Check(sLog.calls>0,"reports executed during concurrent updates");
 ChatHandler handler;bool enabled=sPlayerbotAIConfig.perfMonEnabled;TortoiseBots::BotCommands::HandlePerformanceCommand(&handler,"toggle");Check(sPlayerbotAIConfig.perfMonEnabled==enabled,"denied command cannot toggle monitoring");handler.allowed=true;TortoiseBots::BotCommands::HandlePerformanceCommand(&handler,"toggle invalid");Check(sPlayerbotAIConfig.perfMonEnabled==enabled,"invalid syntax has no partial mutation");TortoiseBots::BotCommands::HandlePerformanceCommand(&handler,"toggle");Check(sPlayerbotAIConfig.perfMonEnabled!=enabled,"authorized toggle works");TortoiseBots::BotCommands::HandlePerformanceCommand(&handler,"reset");TortoiseBots::BotCommands::HandlePerformanceCommand(&handler,"tick stack map");Check(!TortoiseBots::BotCommands::HandlePerformanceCommand(nullptr,""),"missing handler rejected");
 std::cout<<"Concurrent module performance state and nesting checks passed\n";
}
