#include "../src/game/Maps/TerrainTileUsage.h"

#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>

static void Check(bool passed, char const* message)
{
    if (!passed)
        throw std::runtime_error(message);
}

int main()
{
    TerrainTileUsage tile;
    Check(tile.ShouldUnload(false), "An untouched, unreferenced tile must be reclaimable.");
    Check(!tile.ShouldUnload(true), "A world-grid reference must prevent eviction.");

    // Reproduce the original failure: queries continuously use a tile, but no
    // loaded world grid references it. Minute sweeps must not reload it.
    for (int minute = 0; minute < 120; ++minute)
    {
        for (int query = 0; query < 1000; ++query)
            tile.MarkAccessed();
        Check(!tile.ShouldUnload(false), "Terrain used by queries was evicted.");
    }
    Check(tile.ShouldUnload(false), "An idle tile must be released at the next unused interval.");

    // A new query after a sweep grants another interval; dropping a reference
    // must not discard usage registered since that sweep.
    Check(!tile.ShouldUnload(true), "Referenced tile was evicted on a later sweep.");
    tile.MarkAccessed();
    Check(!tile.ShouldUnload(false), "Query after dropping the last reference was lost.");
    Check(tile.ShouldUnload(false), "Query-only residency must not become permanent.");

    // Multiple map/cell workers can record usage concurrently. Cleanup occurs
    // only after they have joined, as in TerrainManager::Update.
    std::vector<std::thread> readers;
    for (int worker = 0; worker < 8; ++worker)
        readers.emplace_back([&tile]() {
            for (int query = 0; query < 10000; ++query)
                tile.MarkAccessed();
        });
    for (auto& reader : readers)
        reader.join();
    Check(!tile.ShouldUnload(false), "Concurrent queries were not retained.");
    Check(tile.ShouldUnload(false), "Concurrent access prevented eventual reclamation.");

    std::cout << "Terrain tile residency tests passed.\n";
}
