// Execute the real module command permission/selection boundary and the
// preserved CMaNGOS forwarding function with recording terminal services.
#include <cstdlib>
#include <iostream>
#include <string>
enum { SEC_PLAYER, SEC_ADMINISTRATOR };
struct Player { bool admin = false; };
struct ChatCommand {};
struct ChatHandler {
    Player* player = nullptr;
    int access = SEC_ADMINISTRATOR;
    bool registered = true;
    bool permission = true;
    ChatCommand const* FindCommand(char const* name) const {
        static ChatCommand command;
        return registered && std::string(name) == "ahbot" ? &command : nullptr;
    }
    bool IsCommandAvailable(ChatCommand const&) const {
        return permission && (player ? player->admin : access >= SEC_ADMINISTRATOR);
    }
    int denied = 0;
    void PSendSysMessage(char const*) { ++denied; }
};
Player* Requester(ChatHandler* h) { return h->player; }
bool IsBotAdministrator(Player* p) { return p->admin; }
struct { bool ahMarketUseCMaNGOS = true; } sPlayerbotAIConfig;
namespace ahbot {
class AhBot {
public:
    static bool HandleAhBotCommand(ChatHandler*, char const*);
    ChatHandler* caller = nullptr;
    std::string received;
    int calls = 0;
    bool result = true;
    bool HandleCommand(ChatHandler* h, std::string args) {
        caller = h; received = args; ++calls; return result;
    }
};
}
ahbot::AhBot service, moduleService;
bool HandleModuleAhBot(ChatHandler* h, char const* args) {
    return moduleService.HandleCommand(h, args ? args : "");
}
#define auctionbot service
using ahbot::AhBot;
#include "NativeAhBotModuleDispatch.inc"
#include "NativeAhBotChatDispatch.inc"
#define CHECK(x) do { if (!(x)) { std::cerr << "Failed: " #x << '\n'; std::exit(1); } } while (0)
int main() {
    ChatHandler chat;
    Player player;
    for (bool selected : {false, true}) {
        sPlayerbotAIConfig.ahMarketUseCMaNGOS = selected;
        int before = service.calls + moduleService.calls;
        chat.player = nullptr;
        chat.access = SEC_PLAYER;
        CHECK(HandleAhBot(&chat, "rebuild all"));
        CHECK(service.calls + moduleService.calls == before);
        chat.access = SEC_ADMINISTRATOR;
        chat.registered = false;
        CHECK(HandleAhBot(&chat, "rebuild all"));
        CHECK(service.calls + moduleService.calls == before);
        chat.registered = true;
        chat.permission = false;
        CHECK(HandleAhBot(&chat, "rebuild all"));
        CHECK(service.calls + moduleService.calls == before);
        chat.permission = true;
        CHECK(!HandleAhBot(nullptr, "rebuild all"));
        chat.player = &player;
        player.admin = false;
        CHECK(HandleAhBot(&chat, "rebuild all"));
        CHECK(service.calls + moduleService.calls == before);
        CHECK(chat.denied > 0);
        for (bool console : {false, true}) {
            player.admin = true;
            chat.player = console ? nullptr : &player;
            for (auto args : {"reload", "rebuild", "rebuild all", "status all", "item 117 reset", "", static_cast<char const*>(nullptr)}) {
                for (bool result : {false, true}) {
                    service.result = moduleService.result = result;
                    int oldPrimary = service.calls, oldAlternative = moduleService.calls;
                    CHECK(HandleAhBot(&chat, args) == result);
                    CHECK(service.calls == oldPrimary + (selected ? 1 : 0));
                    CHECK(moduleService.calls == oldAlternative + (selected ? 0 : 1));
                    auto const& called = selected ? service : moduleService;
                    CHECK(called.caller == &chat);
                    CHECK(called.received == (args ? args : ""));
                }
            }
        }
    }
    std::cout << "AH module permissions, exclusive selection and forwarding passed\n";
}
