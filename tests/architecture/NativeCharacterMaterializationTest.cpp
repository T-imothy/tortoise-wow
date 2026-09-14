#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using uint32=unsigned;
std::vector<std::string> events;
bool createAccepted=true,saveAccepted=true;
enum {LOCALE_enUS,AT_LOGIN_FIRST,CINEMATICS_SKIP_SAME_RACE,CINEMATICS_SKIP_ALL,CHAR_CREATE_ERROR,CHAR_CREATE_SUCCESS,LOG_CHAR,PLAYERHOOK_ON_CREATE};
enum class SessionTransport{Headless};
struct WorldSession {template<class...A>WorldSession(A...){events.push_back("session");}~WorldSession(){events.push_back("session destroyed");}};
namespace PlayerVariables{enum{PendingChallengeMask};}
struct Player {Player(WorldSession*){events.push_back("player");}~Player(){events.push_back("player destroyed");}template<class...A>bool Create(A...){events.push_back("create");return createAccepted;}void SetCinematic(int){}void SetAtLoginFlag(int){}void SetPlayerVariable(int,std::string){}bool SaveToDB(bool,bool sync,bool){events.push_back(sync?"save synchronous":"save async");return saveAccepted;}unsigned GetObjectGuid(){return 42;}unsigned GetGUIDLow(){return 42;}};
struct MasterPlayer {MasterPlayer(WorldSession*){}void Create(Player*){}void SaveToDB(){events.push_back("master saved");}};
struct ObjectMgr {unsigned GeneratePlayerLowGuid(){return 42;}void InsertPlayerInCache(Player*){events.push_back("cache");}void UpdatePlayerCachedPosition(Player*){}void IncreaseActivePlayersCount(int){events.push_back("count");}}sObjectMgr;
struct Database {template<class...A>void PExecute(A...){events.push_back("realm count");}}LoginDatabase;
struct Log {template<class...A>void out(A...){}}sLog;
#define BASIC_LOG(...) do{}while(0)
struct LogCharAction {enum Action{ActionCreate};unsigned guid,account;Action action;std::string payload;};
struct DbLog {void LogCharAction(::LogCharAction){}}sDBLogger;
struct PlayerScript {void OnCreate(Player*){events.push_back("hook");}};
template<class T>struct ScriptRegistry {template<class F>static void ForEachEnabledHook(int,F f){T script;f(&script);}};
struct Outcome {int result=CHAR_CREATE_ERROR;unsigned guid=0,newCharactersCount=0;};
struct Info {unsigned race=1,class_=1,gender=0,skin=0,face=0,hairStyle=0,hairColor=0,facialHair=0,challengeMask=0;}info;
unsigned realmID=1;
Outcome Materialize(){unsigned accountId=1,charCount=2;int sec=0,team=1,skipCinematics=CINEMATICS_SKIP_ALL;bool haveSameRace=false;std::string name="Fixture",accName="Fixture",effectiveIP="127.0.0.1";Outcome outcome;
#include "NativeCharacterMaterialization.inc"
}
void Check(bool ok,char const*why){if(!ok){std::cerr<<why<<'\n';std::exit(1);}}
int main(){
 auto result=Materialize();Check(result.result==CHAR_CREATE_SUCCESS&&result.guid==42&&result.newCharactersCount==3,"success publishes committed identity and exact count");
 Check(events==std::vector<std::string>{"session","player","create","save synchronous","master saved","cache","realm count","hook","count","player destroyed","session destroyed"},"save precedes cache/hooks and player dies before transient session");
 events.clear();saveAccepted=false;result=Materialize();Check(result.result==CHAR_CREATE_ERROR&&!result.guid&&events==std::vector<std::string>{"session","player","create","save synchronous","player destroyed","session destroyed"},"failed save publishes no identity, cache, hooks or count");
 events.clear();createAccepted=false;result=Materialize();Check(result.result==CHAR_CREATE_ERROR&&events==std::vector<std::string>{"session","player","create","player destroyed","session destroyed"},"failed materialization does not save and preserves destruction order");
 std::cout<<"Native synchronous character save, publication and transient ownership passed\n";
}
