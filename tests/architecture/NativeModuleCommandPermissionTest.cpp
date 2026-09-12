// Native permission implementations with mock session/account storage.
// The module query must dispatch to CLI/SOAP policy without dereferencing a
// nonexistent game session, and retain configured RBAC grants and bans.
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
using uint32 = uint32_t;
enum AccountTypes { SEC_PLAYER, SEC_MODERATOR, SEC_GAMEMASTER, SEC_ADMINISTRATOR, SEC_CONSOLE };
struct ChatCommand { uint32 SecurityLevel = SEC_ADMINISTRATOR; bool AllowConsole = true; uint32 PermissionMask = 4; };
struct Session { uint32 account = 1; AccountTypes rank = SEC_PLAYER; uint32 GetAccountId() const { return account; } };
class ChatHandler {
public:
    Session* m_session;
    static std::map<uint32,uint32> m_rbacAccountBannedPermissions, m_rbacAccountGrantedPermissions;
    explicit ChatHandler(Session* session) : m_session(session) {}
    virtual ~ChatHandler() = default;
#include "NativeModulePermissionQuery.inc"
protected:
    virtual AccountTypes GetAccessLevel() const { return m_session->rank; }
    virtual bool isAvailable(ChatCommand const& cmd) const;
};
class CliHandler : public ChatHandler {
public:
    AccountTypes rank = SEC_PLAYER;
    CliHandler() : ChatHandler(nullptr) {}
protected:
    AccountTypes GetAccessLevel() const override { return rank; }
    bool isAvailable(ChatCommand const& cmd) const override;
};
std::map<uint32,uint32> ChatHandler::m_rbacAccountBannedPermissions, ChatHandler::m_rbacAccountGrantedPermissions;
#include "NativeGameCommandPermission.inc"
#include "NativeCliCommandPermission.inc"
#define CHECK(x) do { if (!(x)) { std::cerr << "Failed: " #x << '\n'; std::exit(1); } } while (0)
int main() {
    Session session;
    ChatHandler game(&session);
    CliHandler cli;
    ChatHandler* soap = &cli;
    ChatCommand cmd;
    for (auto rank : {SEC_PLAYER, SEC_MODERATOR, SEC_GAMEMASTER, SEC_ADMINISTRATOR, SEC_CONSOLE}) {
        session.rank = cli.rank = rank;
        CHECK(game.IsCommandAvailable(cmd) == (rank >= SEC_ADMINISTRATOR));
        CHECK(soap->IsCommandAvailable(cmd) == (rank >= SEC_ADMINISTRATOR));
    }
    cmd.AllowConsole = false;
    CHECK(!soap->IsCommandAvailable(cmd));
    CHECK(game.IsCommandAvailable(cmd));
    cmd.AllowConsole = true;
    session.rank = SEC_PLAYER;
    ChatHandler::m_rbacAccountGrantedPermissions[1] = 4;
    CHECK(game.IsCommandAvailable(cmd));
    session.rank = SEC_ADMINISTRATOR;
    ChatHandler::m_rbacAccountBannedPermissions[1] = 4;
    CHECK(!game.IsCommandAvailable(cmd));
    ChatHandler::m_rbacAccountBannedPermissions[1] = 2;
    CHECK(game.IsCommandAvailable(cmd));
    cli.rank = SEC_PLAYER;
    CHECK(!soap->IsCommandAvailable(cmd));
    std::cout << "Native module authorization preserves game RBAC and console/SOAP policy\n";
}
