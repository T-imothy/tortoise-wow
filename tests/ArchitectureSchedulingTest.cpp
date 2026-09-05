#include "../src/shared/BoundedWork.h"
#include "../src/shared/IdleResidency.h"
#include "../src/shared/PathReuseContext.h"
#include <array>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>

static void Check(bool value, char const* message)
{
    if (!value) throw std::runtime_error(message);
}

int main()
{
    BoundedWork::UniqueQueue cells;
    for (uint32_t round = 0; round < 10; ++round)
        for (uint32_t id = 0; id < 6000; ++id) cells.Push(id);
    Check(cells.Size() == 6000, "Cell overlap multiplied pending work");
    for (uint32_t id = 0; id < 6000; ++id)
        Check(cells.Pop() == id, "New work overtook an older cell");
    Check(cells.Size() == 0, "Cell backlog did not drain");
    cells.Push(1); cells.Clear(); cells.Push(1);
    Check(cells.Pop() == 1, "Clearing a population prevented reenqueuing");

    // Stagger bot maintenance across the whole minute, not across a handful
    // of ticks just because character GUIDs are sequential.
    std::array<uint32_t, 60> buckets{};
    for (uint32_t id = 1; id <= 6000; ++id)
        ++buckets[BoundedWork::Phase(id, 60000) / 1000];
    for (auto count : buckets)
        Check(count > 40 && count < 160, "Maintenance phase concentrated bots into a burst");
    Check(BoundedWork::Phase(12, 0) == 0, "Disabled interval divided by zero");

    BoundedWork::Deadlines deadlines;
    deadlines.Served(1, 1000);
    Check(!deadlines.Due(1, 1099, 100), "Early background execution");
    Check(deadlines.Due(1, 1100, 100), "Deadline lost at interval boundary");
    Check(deadlines.Due(1, 1100, 50), "Decreasing interval stuck scheduling");
    Check(!deadlines.Due(1, 1100, 200), "Increasing interval ignored");
    deadlines.Served(2, UINT32_MAX - 49);
    Check(!deadlines.Due(2, 25, 100), "Clock wrap fired an early update");
    Check(deadlines.Due(2, 50, 100), "Clock wrap lost an overdue update");

    // Count-bounded round robin with the SAME metadata used by Map. Simulate
    // a live population reduction followed by an increase, without resetting
    // cursor/deadlines. Every surviving/new bot must continue to get turns.
    size_t cursor = 0;
    uint32_t now = 2000;
    for (uint32_t population : {6000U, 3000U, 0U, 10000U, 4000U})
    {
        std::vector<uint32_t> served(population, 0);
        for (uint32_t tick = 0; tick < 300; ++tick)
        {
            now += 100;
            BoundedWork::Budget budget(0, 73);
            size_t visited = 0, completed = 0;
            while (visited < population && !budget.Exhausted(completed))
            {
                cursor %= population;
                uint32_t const id = uint32_t(cursor++);
                ++visited;
                if (!deadlines.Due(id, now, 100)) continue;
                deadlines.Served(id, now);
                ++served[id]; ++completed;
            }
            Check(completed <= 73, "Count budget exceeded");
        }
        for (auto count : served) Check(count > 0, "Population change starved a bot");
        deadlines.Prune([population](uint32_t id) { return id < population; });
        Check(deadlines.Size() == population, "Removed population retained stale deadlines");
    }
    BoundedWork::Budget one(0, 1);
    Check(!one.Exhausted(0) && one.Exhausted(1), "Small budget starves its first job");
    BoundedWork::Budget timed(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    Check(!timed.Exhausted(0), "Elapsed budget prevented the first job from progressing");
    Check(timed.Exhausted(1), "Elapsed time budget kept admitting background work");

    IdleResidency lifetime(100);
    Check(!lifetime.UnusedFor(159, 60), "Value evicted too early");
    Check(lifetime.UnusedFor(160, 60), "Idle value retained forever");
    for (time_t now = 160; now < 1000; ++now)
    {
        lifetime.Touch(now);
        Check(!lifetime.UnusedFor(now, 60), "Actively used value evicted");
    }
    Check(!lifetime.UnusedFor(900, 60), "Backward wall-clock jump evicted a value");
    Check(lifetime.UnusedFor(1060, 60), "Value did not become reclaimable after becoming idle");

    PathReuseContext context{1, 0, 10, 3, 0};
    auto changed = context;
    Check(changed == context, "Identical path context cannot reuse corridor");
    changed.map = 0; Check(changed != context, "Map change reused corridor");
    changed = context; ++changed.instance; Check(changed != context, "Instance change reused corridor");
    changed = context; ++changed.terrain; Check(changed != context, "Nav tile change reused corridor");
    changed = context; ++changed.capabilities; Check(changed != context, "Movement mode change reused corridor");
    changed = context; ++changed.transport; Check(changed != context, "Transport change reused corridor");

    std::cout << "Scheduling, population-change, cache lifetime and path-context tests passed.\n";
}
