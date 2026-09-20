#include "Memory/SparseListArray.h"
#include <iostream>
#include <memory>

using AuraType = unsigned;
constexpr unsigned TOTAL_AURAS = 231;
struct Unit
{
    ManTech::SparseListArray<int, TOTAL_AURAS> m_modAuras;
    bool HasAuraType(AuraType type) const;
    auto const& GetAurasByType(AuraType type) const { return m_modAuras.Stable(type); }
};
#include "NativeHasAuraType.inc"

#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x " failed\n"; return 1; } } while (false)
int main()
{
    using namespace ManTech;
    auto const buckets = MemoryLedger::Read(MemoryKind::AuraBuckets);
    auto const pages = MemoryLedger::Read(MemoryKind::AuraIndexes);
    {
        auto units = std::make_unique<Unit[]>(1000);
        for (unsigned repeat = 0; repeat < 10; ++repeat)
            for (unsigned n = 0; n < 1000; ++n)
                for (unsigned type = 0; type < TOTAL_AURAS; ++type)
                    CHECK(!units[n].HasAuraType(type));
        CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).count == buckets.count);
        CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).count == pages.count);

        // The unchanged public getter must still preserve escaped references.
        Unit& unit = units[0];
        auto const& stable = unit.GetAurasByType(230);
        auto end = stable.end();
        unit.m_modAuras.Mutable(230).push_back(7);
        CHECK(unit.HasAuraType(230) && stable.front() == 7);
        unsigned sum = 0;
        for (unsigned type = 0; type < TOTAL_AURAS; ++type)
        {
            if (!unit.HasAuraType(type))
                continue;
            for (auto value : unit.GetAurasByType(type))
                sum += value;
        }
        CHECK(sum == 7);
        CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).count == buckets.count + 1);
        CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).count == pages.count + 1);
        unit.m_modAuras.Mutable(230).clear();
        CHECK(!unit.HasAuraType(230) && stable.end() == end);
        unit.m_modAuras.Mutable(230).push_back(9);
        CHECK(unit.HasAuraType(230) && stable.front() == 9 && stable.end() == end);
    }
    CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).bytes == buckets.bytes);
    CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).bytes == pages.bytes);
    std::cout << "PASS: native aura probes allocate no empty lists; live auras and stable references preserved\n";
}
