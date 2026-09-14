#include "Util/AccountMembershipIndex.h"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

static void require(bool ok) { if (!ok) std::abort(); }
int main() {
    ManTech::AccountMembershipIndex index;
    std::list<std::uint32_t> ordered, reference;
    std::mt19937 random(7821);
    require(!index.Contains(0));
    for (unsigned i=0; i<5000; ++i) {
        auto id = random()%2000;
        reference.push_back(id);
        index.Append(ordered, id);
        require(ordered==reference);
        for (unsigned j=0; j<5; ++j) {
            auto query = random()%3000;
            require(index.Contains(query)==(std::find(reference.begin(),reference.end(),query)!=reference.end()));
        }
    }
    // Readers must see registrations made at runtime, including while other
    // readers are active. No iterator reads occur concurrently with an append.
    std::atomic<unsigned> published{0};
    std::atomic<bool> done{false};
    std::vector<std::thread> readers;
    for (unsigned i=0;i<4;++i) readers.emplace_back([&] {
        while (!done.load()) {
            unsigned upto=published.load();
            if (upto) require(index.Contains(10000+upto));
            require(!index.Contains(999999));
        }
    });
    for (unsigned i=1;i<=2000;++i) {
        index.Append(ordered,10000+i);
        reference.push_back(10000+i);
        published.store(i);
    }
    done.store(true);
    for(auto& reader:readers) reader.join();
    require(ordered==reference);
    std::vector<unsigned> queries;
    for(unsigned i=0;i<100000;++i) queries.push_back(random()%14000);
    auto start=std::chrono::steady_clock::now();
    unsigned oldHits=0;
    for(auto query:queries) oldHits+=std::find(reference.begin(),reference.end(),query)!=reference.end();
    auto middle=std::chrono::steady_clock::now();
    unsigned newHits=0;
    for(auto query:queries) newHits+=index.Contains(query);
    auto end=std::chrono::steady_clock::now();
    require(oldHits==newHits);
    std::cout << "Membership, order, duplicates, runtime additions and concurrent readers passed; old_ms="
        << std::chrono::duration<double,std::milli>(middle-start).count()
        << " indexed_ms=" << std::chrono::duration<double,std::milli>(end-middle).count() << '\n';
}
