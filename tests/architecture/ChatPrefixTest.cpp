#include "playerbot/ChatPrefix.h"
#include <boost/algorithm/string/predicate.hpp>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <atomic>

int main()
{
    for (unsigned a=0;a<256;++a) for(unsigned b=0;b<256;++b)
    {
        std::string text(1,char(a)),prefix(1,char(b));
        assert(ai::chat::HasInsensitivePrefix(text,prefix)==boost::algorithm::istarts_with(text,prefix));
    }
    for(std::string text:{"","gnomes","GNOMES Hitem:42","gNoMeS Hquest:1","ordinary chat","gnom"})
        for(std::string prefix:{"","gnomes","GNOMES","gnomes Hitem:","a longer prefix than the message"})
            assert(ai::chat::HasInsensitivePrefix(text,prefix)==boost::algorithm::istarts_with(text,prefix));
    for(bool optimized:{false,true})
    {
        std::atomic<unsigned> matches{0};std::vector<std::thread> workers;
        auto begin=std::chrono::steady_clock::now();
        for(unsigned t=0;t<8;++t) workers.emplace_back([&]{
            std::string text="GnOmEs Hitem:42",prefix="gnomes";unsigned count=0;
            for(unsigned n=0;n<10000;++n)
                count+=optimized?ai::chat::HasInsensitivePrefix(text,prefix):boost::algorithm::istarts_with(text,prefix);
            matches+=count;
        });
        for(auto& worker:workers)worker.join();assert(matches==80000);
        std::cout<<(optimized?"cached_facet":"boost_default")<<" 8_threads_80k_checks_ms="
                 <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-begin).count()<<'\n';
    }
    std::cout<<"PASS 65536 byte-pair comparisons, empty/short/prefix cases and concurrent readers\n";
}
