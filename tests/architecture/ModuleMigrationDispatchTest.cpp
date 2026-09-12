#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#define CHECK(x) do { if (!(x)) { std::cerr<<__LINE__<<": " #x <<'\n';std::exit(1);} } while(0)
using path=std::filesystem::path;
struct directory_entry { ::path value; directory_entry(::path p):value(p){} ::path path()const{return value;} };
struct Config { std::map<std::string,std::string> values;
    std::string GetStringDefault(std::string k,std::string d){auto i=values.find(k);return i==values.end()?d:i->second;}
    bool GetBoolDefault(std::string k,bool d){auto i=values.find(k);return i==values.end()?d:i->second=="1";} } sConfig;
struct { template<class...T> void outInfo(T...){} template<class...T> void out(T...){} } sLog;
constexpr int LOG_AUTOUPDATER=1;
int LoginDatabase=1,CharacterDatabase=2,WorldDatabase=3;
struct Call {std::string folder;int db;bool module,region,sorted;};
class AutoUpdater
{
public:
    std::vector<Call> calls;unsigned failAt=0;
    bool ProcessUpdates();
    bool ProcessTargetUpdates(directory_entry dir,int* db,bool region,bool sorted){calls.push_back({dir.path().generic_string(),*db,false,region,sorted});return calls.size()!=failAt;}
    bool ProcessModuleUpdates(path const&,std::string folder,int* db,bool sorted){calls.push_back({folder,*db,true,false,sorted});return calls.size()!=failAt;}
};
#include "NativeModuleMigrationDispatch.inc"
int main()
{
    sConfig.values={{"Database.AutoUpdate.Path","core"},{"Database.AutoUpdate.AuthUpdateName","auth"},{"Database.AutoUpdate.CharUpdateName","character"},{"Database.AutoUpdate.WorldUpdateName","world"},{"Database.AutoUpdate.SortByName","1"}};
    AutoUpdater updater; CHECK(updater.ProcessUpdates());CHECK(updater.calls.size()==6);
    CHECK(updater.calls[1].folder=="core/character"&&updater.calls[1].db==2);
    CHECK(updater.calls[4].folder=="char"&&updater.calls[4].db==2&&updater.calls[4].module);
    for(auto c:updater.calls)CHECK(c.sorted);
    sConfig.values["Database.AutoUpdate.ModuleCharUpdateName"]="custom-char";
    sConfig.values["Database.AutoUpdate.ModuleAuthUpdateName"]="custom-auth";
    sConfig.values["Database.AutoUpdate.ModuleWorldUpdateName"]="custom-world";
    updater.calls.clear();CHECK(updater.ProcessUpdates());
    CHECK(updater.calls[3].folder=="custom-auth"&&updater.calls[4].folder=="custom-char"&&updater.calls[5].folder=="custom-world");
    CHECK(updater.calls[1].folder=="core/character");
    for(unsigned fail=1;fail<=6;++fail){updater.calls.clear();updater.failAt=fail;CHECK(!updater.ProcessUpdates());CHECK(updater.calls.size()==fail);}
    updater.failAt=0;updater.calls.clear();sConfig.values["Database.AutoUpdate.Enabled"]="0";CHECK(updater.ProcessUpdates());CHECK(updater.calls.empty());
    sConfig.values["Database.AutoUpdate.Enabled"]="1";sConfig.values["NiHao"]="1";CHECK(updater.ProcessUpdates());CHECK(updater.calls.size()==9);
    CHECK(updater.calls[7].folder=="core/character/cn"&&updater.calls[7].region);
    std::cout<<"Core/module migration folder selection, database routing, ordering and failure propagation passed\n";
}
