#include <algorithm>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
using uint32=unsigned int; using uint64=unsigned long long; using int32=int; using int64=long long;
#define UI64FMTD "%llu"
time_t fakeNow=1000;
time_t FakeTime(void*) {return fakeNow;}
#define time FakeTime
struct Field {std::string text; std::string GetCppString(){return text;} uint32 GetUInt32(){return uint32(std::strtoull(text.c_str(),nullptr,10));} uint64 GetUInt64(){return std::strtoull(text.c_str(),nullptr,10);}};
struct QueryResult {std::vector<std::vector<Field>> rows;size_t index=0; Field*Fetch(){return rows[index].data();}bool NextRow(){return ++index<rows.size();}};
struct Db {
    std::map<std::pair<uint32,std::string>,std::vector<Field>> saved;
    int reads=0,writes=0; bool failCount=false,failRows=false,failWrite=false;std::string lastEvent,lastData;
    QueryResult* PQuery(char const*sql){++reads;if(std::string(sql).find("COUNT")!=std::string::npos){if(failCount)return nullptr;return new QueryResult{{{{std::to_string(saved.size())}}}};}if(failRows||saved.empty())return nullptr;auto*r=new QueryResult;for(auto const&row:saved)r->rows.push_back(row.second);return r;}
    void escape_string(std::string&s){std::string out;for(char c:s){if(c=='\''||c=='\\')out+='\\';out+=c;}s=out;}
    static std::string unescape(std::string s){std::string out;for(size_t i=0;i<s.size();++i){if(s[i]=='\\'&&i+1<s.size())++i;out+=s[i];}return out;}
    bool PExecute(char const*sql,...){++writes;if(failWrite)return false;if(std::string(sql)=="DELETE FROM ai_playerbot_values WHERE event <> 'temporary'"){for(auto it=saved.begin();it!=saved.end();){if(it->first.second!="temporary")it=saved.erase(it);else ++it;}return true;}va_list args;va_start(args,sql);uint32 guid=va_arg(args,uint32);lastEvent=va_arg(args,char const*);std::string key=unescape(lastEvent);if(std::string(sql).find("DELETE")==0)saved.erase({guid,key});else{uint32 value=va_arg(args,uint32);lastData=va_arg(args,char const*);uint64 expiry=va_arg(args,uint64);saved[{guid,key}]={{std::to_string(guid)},{key},{std::to_string(value)},{unescape(lastData)},{std::to_string(expiry)}};}va_end(args);return true;}
} CharacterDatabase;
struct Guid {uint32 n;uint32 GetCounter(){return n;}};
struct Player {uint32 guid; Guid GetObjectGuid(){return {guid};}uint32 GetGUIDLow(){return guid;}};
struct Config{uint32 maxRandomBotInWorldTime=100,maxRandomBotsPriceChangeInterval=60;}sPlayerbotAIConfig;
uint32 urand(uint32 low,uint32){return low;}
class RandomBotFacade {public:bool LoadPersistentValues();bool ResetPersistentValues();uint32 GetValue(Player*,std::string);uint32 GetValue(uint32,std::string);int32 GetValueValidTime(uint32,std::string);std::string GetData(uint32,std::string);void SetValue(uint32,std::string,uint32,std::string="",int32=-1);void SetValue(Player*,std::string,uint32,std::string="",int32=-1);double GetBuyMultiplier(Player*);double GetSellMultiplier(Player*);uint32 GetTradeDiscount(Player*,Player*);void SetTradeDiscount(Player*,Player*,uint32);void AddTradeDiscount(Player*,Player*,int32);};
#include "ModuleValueStorage.inc"
#include "ModuleValueMethods.inc"
void Check(bool v,char const*m){if(!v){std::cerr<<m<<'\n';std::exit(1);}}
void Restart(){s_values.clear();s_valuesReady=false;}
int main(){RandomBotFacade f;
    CharacterDatabase.failCount=true;Check(!f.LoadPersistentValues(),"failed schema read must not publish ready");f.SetValue(1,"specNo",3);Check(CharacterDatabase.writes==0,"unready store must not write");
    CharacterDatabase.failCount=false;Check(f.LoadPersistentValues(),"empty store starts");
    f.SetValue(1,"specNo",3);f.SetValue(1,"specLink",1,"talent'\\link");Check(CharacterDatabase.lastData=="talent\\'\\\\link","escape persisted data");
    f.SetValue(1,"ttl",7,"expires",10);f.SetValue(1,"quote'",4);Check(CharacterDatabase.lastEvent=="quote\\'","escape event");
    int reads=CharacterDatabase.reads;for(int i=0;i<10000;++i)Check(f.GetValue(1,"specNo")==3,"cached reads");Check(CharacterDatabase.reads==reads,"reads perform no SQL");
    Restart();Check(f.LoadPersistentValues(),"restart load");Check(f.GetValue(1,"specNo")==3&&f.GetData(1,"specLink")=="talent'\\link","persistent selection and data");
    Check(f.GetValueValidTime(1,"ttl")==10,"remaining lifetime restored");fakeNow=1010;Check(f.GetValue(1,"ttl")==0&&f.GetData(1,"ttl").empty()&&f.GetValueValidTime(1,"ttl")==0,"expiry boundary");
    Check(f.GetValue(1,"specNo")==3&&f.GetValueValidTime(1,"specNo")==-1,"non-expiring value");
    CharacterDatabase.failWrite=true;f.SetValue(1,"specNo",99);Check(f.GetValue(1,"specNo")==3,"enqueue failure preserves published value");CharacterDatabase.failWrite=false;
    f.SetValue(1,"specNo",0);Check(f.GetValue(1,"specNo")==0&&CharacterDatabase.saved.count({1,"specNo"})==0,"zero removes persisted value");
    int writes=CharacterDatabase.writes;f.SetValue(1,std::string(46,'x'),1);f.SetValue(1,"data",1,std::string(256,'x'));Check(CharacterDatabase.writes==writes,"oversized key/data rejected");
    Player bot{1},master{2};f.SetTradeDiscount(&bot,&master,0);std::vector<std::thread> threads;for(int i=0;i<8;++i)threads.emplace_back([&]{for(int n=0;n<100;++n)f.AddTradeDiscount(&bot,&master,1);});for(auto&t:threads)t.join();Check(f.GetTradeDiscount(&bot,&master)==800,"discount increments serialize");
    f.SetTradeDiscount(&bot,&master,std::numeric_limits<uint32>::max());f.AddTradeDiscount(&bot,&master,1);Check(f.GetTradeDiscount(&bot,&master)==std::numeric_limits<uint32>::max(),"discount overflow saturates");f.AddTradeDiscount(&bot,&master,std::numeric_limits<int32>::min());Check(f.GetTradeDiscount(&bot,&master)==2147483647u,"INT_MIN decrement safe");
    Restart();CharacterDatabase.failRows=true;Check(!f.LoadPersistentValues()&&!s_valuesReady,"nonempty store read failure fails startup");CharacterDatabase.failRows=false;Check(f.LoadPersistentValues(),"retry loads after read failure");Check(f.GetTradeDiscount(&bot,&master)==2147483647u,"discount survives restart");
    f.SetValue(1,"temporary",9);f.SetValue(uint32(0),"bot_count",30);CharacterDatabase.failWrite=true;
    Check(!f.ResetPersistentValues()&&f.GetValue(uint32(0),"bot_count")==30,"failed reset enqueue preserves all cached state");CharacterDatabase.failWrite=false;
    Check(f.ResetPersistentValues()&&f.GetValue(1,"temporary")==9&&f.GetValue(uint32(0),"bot_count")==0&&f.GetTradeDiscount(&bot,&master)==0,"reset preserves only temporary events");
    Restart();Check(f.LoadPersistentValues()&&f.GetValue(1,"temporary")==9&&CharacterDatabase.saved.size()==1,"reset persists across restart");
    std::cout<<"Persistent values, SQL enqueue ordering, restart and atomic discount checks passed\n";
}
