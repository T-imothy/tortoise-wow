// ManTech realm policy, matching Classic core commit 61a59c05f.
// Native loot distribution and all other bot permissions remain authoritative.
#include "playerbot/playerbot.h"
#include "playerbot/strategy/actions/SecurityCheckAction.h"

bool ai::SecurityCheckAction::isUseful() { return false; }
bool ai::SecurityCheckAction::Execute(Event&) { return false; }
bool ai::SecurityCheckAction::RequiresWorldOwner() const { return false; }
