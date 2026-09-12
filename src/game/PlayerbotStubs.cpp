// Empty implementations for builds without the playerbots module
// (BUILD_PLAYERBOTS=OFF). The host calls these unconditionally; without the
// stubs the link step fails on missing symbols. When the module is built it
// provides the real ones and this file is excluded (src/game/CMakeLists.txt).
//
// This list used to be three times as long. Everything the bots reached the
// core through is a module hook now, and a hook needs no stub - the virtual
// has an empty body and nothing registers it. What is left are the few
// symbols that are genuinely core-side: the module bootstrap, the damage-log
// probes have moved to generic script observations. Chat.cpp still registers
// whether or not the module exists.

#include "Objects/Player.h"
#include "Objects/Unit.h"
#include "World.h"
#include "WorldPacket.h"
#include "Chat/Chat.h"

// The single call the core makes into the module: it registers the hook
// objects. Nothing to register when the module is not there.
void World::InitPlayerbotsAtStartup()         {}

class Player;
void Playerbot_OnPlayerDestroyed(Player const*) {}


// ChatHandler bot-command stubs. Chat.cpp registers `.bot`, `.rndbot`,
// `.ahbot`, and `.perfmon` in the command table unconditionally (no
// #ifdef BUILD_PLAYERBOTS gate), so the host must link these symbols even
// when the bot module isn't compiled in. Return true and inform the user.
bool ChatHandler::HandlePlayerbotCommand(char*)
    { SendSysMessage("Playerbots not built (BUILD_PLAYERBOTS=OFF)."); return true; }
bool ChatHandler::HandleRandomPlayerbotCommand(char*)
    { SendSysMessage("Random playerbots not built (BUILD_PLAYERBOTS=OFF)."); return true; }
bool ChatHandler::HandleAhBotCommand(char*)
    { SendSysMessage("AHBot not built (BUILD_PLAYERBOTS=OFF)."); return true; }
bool ChatHandler::HandlePerfMonCommand(char*)
    { SendSysMessage("Bot performance monitor not built (BUILD_PLAYERBOTS=OFF)."); return true; }
