#include "Memory/SparseListArray.h"
#include "Memory/LazyStorage.h"
#include <map>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <thread>
#include <vector>

#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x " failed\n"; std::abort(); } } while (false)

int main()
{
    using namespace ManTech;
    const auto before = MemoryLedger::Read(MemoryKind::AuraBuckets);
    {
        SparseListArray<int, 231> first, second;
        for (unsigned i = 0; i < 231; ++i)
            CHECK(first[i].empty());
        CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).count == before.count);
        auto& list = first.Mutable(42);
        list.push_back(1);
        list.push_back(2);
        auto iterator = list.begin();
        auto end = list.end();
        list.push_back(3);
        list.remove(2);
        CHECK(*iterator == 1 && end == list.end());
        CHECK(second[42].empty());
        list.clear();
        CHECK(end == first[42].end());
        first.Mutable(42).push_back(4);
        CHECK(end == first[42].end());
        CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).count == before.count + 1);
    }
    CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).bytes == before.bytes);

    {
        SparseListArray<int,231> owner;
        auto const& emptyReference=owner.Stable(7);
        auto emptyEnd=emptyReference.end();
        CHECK(emptyReference.empty());
        owner.Mutable(7).push_back(9);
        CHECK(emptyReference.front()==9 && emptyReference.end()==emptyEnd);
        std::vector<std::thread> readers;
        for(int i=0;i<8;++i)
            readers.emplace_back([&] {
                for(int n=0;n<1000;++n)
                    CHECK(&owner.Stable(8)==&owner.Stable(8));
            });
        for(auto& reader:readers)reader.join();
        CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).count==before.count+2);
    }
    CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).bytes == before.bytes);

    {
        CHECK(sizeof(SparseListArray<int,231>) < 512);
        const auto indexes=MemoryLedger::Read(MemoryKind::AuraIndexes);
        {
            SparseListArray<int,231> owner;
            for(unsigned i=0;i<231;++i)CHECK(owner[i].empty());
            CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).bytes==indexes.bytes);
            std::vector<std::thread> threads;
            for(unsigned t=0;t<12;++t)threads.emplace_back([&,t] {
                for(unsigned j=0;j<231;++j) {
                    unsigned n=(j*19+t)%231;
                    auto* first=&owner.Stable(n);
                    CHECK(first==&owner.Stable(n));
                }
            });
            for(auto& thread:threads)thread.join();
            CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).count==indexes.count+29);
            CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).count==before.count+231);
            std::array<std::list<int>,231> reference;
            // Mutations retain the original single-owner contract.
            for(unsigned n=0;n<10000;++n) {
                auto i=(n*37)%231;
                if(n%7==0){owner.Mutable(i).clear();reference[i].clear();}
                else {owner.Mutable(i).push_back(n);reference[i].push_back(n);}
                CHECK(owner[i]==reference[i]);
            }
            auto* last=&owner.Stable(230);
            auto end=last->end();owner.Mutable(230).clear();
            CHECK(last==&owner.Stable(230)&&end==owner.Stable(230).end());
        }
        CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).count==indexes.count);
        CHECK(MemoryLedger::Read(MemoryKind::AuraIndexes).bytes==indexes.bytes);
        CHECK(MemoryLedger::Read(MemoryKind::AuraBuckets).bytes==before.bytes);
    }

    auto optionalBefore=MemoryLedger::Read(MemoryKind::OptionalState);
    {
        LazyStorageArray<std::map<int,int>,8> maps;
        CHECK(maps.Read(2).empty()); CHECK(MemoryLedger::Read(MemoryKind::OptionalState).bytes==optionalBefore.bytes);
        auto const& stable=static_cast<decltype(maps) const&>(maps)[2]; auto end=stable.end();
        maps[2].emplace(3,42); CHECK(stable.at(3)==42);CHECK(end==stable.end());
        maps[2].clear();CHECK(end==stable.end());
        std::thread a([&]{ for(int i=0;i<1000;++i) (void)static_cast<decltype(maps) const&>(maps)[5]; });
        std::thread b([&]{ for(int i=0;i<1000;++i) (void)static_cast<decltype(maps) const&>(maps)[5]; });
        a.join();b.join();CHECK(MemoryLedger::Read(MemoryKind::OptionalState).count==optionalBefore.count+2);
    }
    CHECK(MemoryLedger::Read(MemoryKind::OptionalState).bytes==optionalBefore.bytes);
    std::cout << "PASS Turtle 231 aura types, stable lists/iterators, concurrent publication, lazy immunity lifetime, complete ledger release\n";
}
