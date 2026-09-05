// Exercise the actual playerbot context template without a world/database.
#include <cstdint>
#include <functional>
#include <memory>
#include <sstream>
#include <string_view>
#include <vector>
#include <iostream>
#include <stdexcept>
using int8 = int8_t;
using uint8 = uint8_t;
using int32 = int32_t;
using uint32 = uint32_t;
class PlayerbotAI;
#include "../modules/mod-playerbots/src/playerbot/strategy/NamedObjectContext.h"

static unsigned constructed = 0, destroyed = 0;
struct Value
{
    Value() { ++constructed; }
    virtual ~Value() { ++destroyed; }
};
struct Context : ai::NamedObjectContext<Value>
{
    explicit Context(bool shared = false) : NamedObjectContext(shared)
    {
        creators["same"] = [](PlayerbotAI*) { return new Value; };
        creators["shared-only"] = [](PlayerbotAI*) { return new Value; };
    }
};
static void Check(bool value, char const* message)
{
    if (!value) throw std::runtime_error(message);
}

int main()
{
    Context shared(true);
    Value* sharedSame = shared.Create("same", nullptr);
    Value* sharedOnly = shared.Create("shared-only", nullptr);
    {
        ai::NamedObjectContextList<Value> values;
        auto* local = new Context;
        values.Add(&shared); // Include an earlier shared context to catch shadowing.
        values.Add(local);
        Value* localSame = local->Create("same", nullptr);
        auto snapshot = values.GetLocalCreated();
        Check(snapshot.size() == 1 && snapshot.count("same"), "Shared values entered a local sweep");
        unsigned before = constructed;
        Check(!values.FindLocalCreated("shared-only"), "Local sweep accessed a shared value");
        Check(!values.FindLocalCreated("missing"), "Sweep created an absent value");
        Check(constructed == before, "Read-only maintenance invoked a factory");
        Check(values.FindLocalCreated("same") == localSame, "Local lookup returned a shadowing shared value");
        values.EraseLocal("same");
        Check(destroyed == 1, "Local cleanup destroyed shared ownership");
        Check(!values.FindLocalCreated("same"), "Removed snapshot entry was recreated");
        Check(shared.FindCreated("same") == sharedSame && shared.FindCreated("shared-only") == sharedOnly,
            "Shared cache was changed by a bot sweep");
    }
    Check(destroyed == 1, "Bot context destruction deleted a shared cache");
    shared.Clear();
    Check(destroyed == constructed, "Cache ownership leaked values");
    std::cout << "Playerbot cache ownership and non-creating cleanup tests passed.\n";
}
