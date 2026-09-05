#ifndef MANGOS_EXECUTION_WATCH_H
#define MANGOS_EXECUTION_WATCH_H
#include <array>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>

// Diagnostics only. The watchdog never reads Player/Map pointers, takes game
// locks, or invokes the normal logger (which may itself be the stalled path).
namespace ExecutionWatch
{
    enum Phase : uint32_t
    {
        Idle, WorldStart, Sessions, Transports, Maps, Battlegrounds, AsyncJoin,
        Callbacks, BotMaintenance, MapStart, PlayerCore, BotAI, Cells,
        ObjectUpdates, Visibility, MapCompletion
    };
    inline char const* Name(uint32_t phase)
    {
        static char const* names[] = {"idle", "world", "sessions", "transports", "maps",
            "battlegrounds", "world-owner-work", "db-callbacks", "bot-maintenance", "map",
            "player-core", "bot-ai", "cells", "object-updates", "visibility", "map-completion"};
        return phase < sizeof(names) / sizeof(*names) ? names[phase] : "unknown";
    }
    inline uint64_t Now()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
    }
    struct alignas(64) Slot
    {
        std::atomic<uint32_t> phase{Idle}, map{0}, instance{0}, guid{0};
        std::atomic<uint64_t> changed{0};
    };
    inline std::array<Slot, 128> slots;
    inline std::atomic<size_t> nextSlot{0};
    inline Slot* Current()
    {
        static thread_local size_t const slot = nextSlot.fetch_add(1);
        return slot < slots.size() ? &slots[slot] : nullptr;
    }
    inline void Set(Phase phase, uint32_t map = 0, uint32_t instance = 0, uint32_t guid = 0)
    {
        if (Slot* slot = Current())
        {
            slot->map.store(map, std::memory_order_relaxed);
            slot->instance.store(instance, std::memory_order_relaxed);
            slot->guid.store(guid, std::memory_order_relaxed);
            slot->changed.store(Now(), std::memory_order_relaxed);
            slot->phase.store(phase, std::memory_order_release);
        }
    }
    struct ResetOnExit { ~ResetOnExit() { Set(Idle); } };
    inline void Dump(FILE* file, uint32_t worldLoop, uint64_t stalledMs)
    {
        uint64_t const now = Now();
        std::fprintf(file, "world_loop=%u unchanged_ms=%llu\n", worldLoop,
            static_cast<unsigned long long>(stalledMs));
        for (size_t i = 0; i < slots.size(); ++i)
        {
            Slot const& slot = slots[i];
            uint32_t const phase = slot.phase.load(std::memory_order_acquire);
            if (!phase) continue;
            std::fprintf(file, "slot=%zu phase=%s map=%u instance=%u guid=%u phase_age_ms=%llu\n",
                i, Name(phase), slot.map.load(), slot.instance.load(), slot.guid.load(),
                static_cast<unsigned long long>(now - slot.changed.load()));
        }
    }
}
#endif
