#pragma once

#include <atomic>

// Terrain queries can use a tile without holding a loaded world-grid reference.
// Keep those tiles until a complete cleanup interval passes without a query.
// Cleanup itself still runs only when the map workers are stopped.
class TerrainTileUsage
{
public:
    void MarkAccessed()
    {
        // Avoid repeatedly writing the same cache line on the terrain hot path.
        if (!m_accessed.load(std::memory_order_relaxed))
            m_accessed.store(true, std::memory_order_relaxed);
    }

    bool ShouldUnload(bool referenced)
    {
        bool const accessed = m_accessed.exchange(false, std::memory_order_relaxed);
        return !referenced && !accessed;
    }

private:
    std::atomic<bool> m_accessed{false};
};
