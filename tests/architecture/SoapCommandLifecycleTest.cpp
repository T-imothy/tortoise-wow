#include <any>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <string>
#include <thread>
using uint32 = unsigned;
enum AccountTypes { SEC_PLAYER, SEC_MODERATOR, SEC_GAMEMASTER, SEC_ADMINISTRATOR, SEC_CONSOLE };
void check(bool value) { if (!value) throw std::runtime_error("SOAP contract failed"); }
struct soap { void* user=nullptr; };
constexpr int SOAP_OK=0;
int soap_sender_fault(soap*, const char*, const char*) { return 400; }
int soap_receiver_fault(soap*, const char*, const char*) { return 503; }
char* soap_strdup(soap*,const char* text) { auto* p=static_cast<char*>(std::malloc(std::strlen(text)+1)); std::strcpy(p,text); return p; }
struct AccountMgr {
    AccountTypes security=SEC_ADMINISTRATOR;
    AccountTypes GetSecurityFromDatabase(uint32) { return security; }
} sAccountMgr;
struct CliCommandHolder {
    uint32 account; AccountTypes security; std::any arg;
    void (*print)(std::any,const char*); void (*finished)(std::any,bool);
    CliCommandHolder(uint32 a,AccountTypes s,std::any state,const char*,decltype(print) p,decltype(finished) f)
        : account(a),security(s),arg(state),print(p),finished(f) {}
};
struct World {
    inline static std::atomic<bool> stopped{false};
    std::unique_ptr<CliCommandHolder> pending;
    bool stopOnQueue=false;
    static bool IsStopped() { return stopped.load(); }
    void QueueCliCommand(CliCommandHolder* command) { pending.reset(command); if(stopOnQueue) stopped=true; }
} sWorld;
struct SOAPThread { static constexpr AccountTypes MinLevel=SEC_ADMINISTRATOR; };
namespace {
#include "NativeSoapCommands.inc"
int main() {
    soap request; char command[]="server info"; char empty[]=""; char* result=nullptr;
    check(ns1__executeCommand(&request,command,&result)==401);
    request.user=reinterpret_cast<void*>(uintptr_t(7));
    sAccountMgr.security=SEC_GAMEMASTER;
    check(ns1__executeCommand(&request,command,&result)==403);
    sAccountMgr.security=SEC_ADMINISTRATOR;
    check(ns1__executeCommand(&request,empty,&result)==400); check(!sWorld.pending);

    // Shutdown may discard a queued command without calling completion. The
    // shared callback state must remain valid until the holder is destroyed.
    sWorld.stopOnQueue=true;
    check(ns1__executeCommand(&request,command,&result)==503);
    check(sWorld.pending->account==7 && sWorld.pending->security==SEC_ADMINISTRATOR);
    std::weak_ptr<SoapCommandState> weak=std::any_cast<std::shared_ptr<SoapCommandState>>(sWorld.pending->arg);
    sWorld.pending->print(sWorld.pending->arg,"late output");
    sWorld.pending->finished(sWorld.pending->arg,true);
    check(!weak.expired()); sWorld.pending.reset(); check(weak.expired());

    World::stopped=false; sWorld.stopOnQueue=false;
    auto state=std::make_shared<SoapCommandState>();
    std::thread owner([state] { SoapPrint(state,"one"); SoapPrint(state,"two"); SoapCommandFinished(state,true); });
    while(!state->finished.load(std::memory_order_acquire)) std::this_thread::yield();
    check(state->success && state->output=="onetwo"); owner.join();
}
