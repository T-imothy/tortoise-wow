#pragma once
#include <cstdint>

struct PathReuseContext
{
    uint32_t map = 0, instance = 0, terrain = 0, capabilities = 0;
    uint64_t transport = 0;
    bool operator==(PathReuseContext const& rhs) const
    {
        return map == rhs.map && instance == rhs.instance && terrain == rhs.terrain &&
            capabilities == rhs.capabilities && transport == rhs.transport;
    }
    bool operator!=(PathReuseContext const& rhs) const { return !(*this == rhs); }
};
