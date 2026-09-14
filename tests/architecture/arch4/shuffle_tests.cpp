
#include "Util/PositiveWeightedShuffle.h"
#include <chrono>
#include <iostream>
#include <numeric>
#include <array>
    template <class D, class W, class URBG>
    inline void WeightedShuffle
    (D first, D last
        , W first_weight, W last_weight
        , URBG&& g)
    {
        while (first != last && first_weight != last_weight)
        {
            std::discrete_distribution<int> dd(first_weight, last_weight);
            auto i = dd(g);

            if (i)
            {
                std::swap(*first, *std::next(first, i));
                std::swap(*first_weight, *std::next(first_weight, i));
            }
            ++first;
            ++first_weight;
        }
    }


int main() {
    unsigned checks=0;
    for (unsigned seed=0;seed<1000;++seed) {
        std::mt19937 data(seed+9001);
        unsigned n=seed<30?seed:data()%400+1;
        std::vector<unsigned> a(n),wa(n);
        std::iota(a.begin(),a.end(),0);
        for (unsigned i=0;i<n;++i) wa[i]=seed%3==0?1:1+data()%200000;
        auto b=a,wb=wa; std::mt19937 ga(seed),gb(seed);
        WeightedShuffle(a.begin(),a.end(),wa.begin(),wa.end(),ga);
        ManTech::PositiveWeightedShuffle(b,wb,gb);
        if(a!=b || wa!=wb || ga!=gb) {std::cerr<<"Mismatch seed="<<seed<<" n="<<n<<"\n";return 1;}
        ++checks;
    }
    std::cout<<checks<<" seeded permutations, weight associations and RNG states match pinned code\n";
    for(unsigned n:{4000,8000,14459}) {
        std::vector<unsigned>a(n),wa(n);
        std::iota(a.begin(),a.end(),0);
        for(unsigned i=0;i<n;++i)wa[i]=1+(i*31)%200000;
        auto b=a,wb=wa;std::mt19937 ga(77123),gb(77123);
        auto start=std::chrono::steady_clock::now();
        WeightedShuffle(a.begin(),a.end(),wa.begin(),wa.end(),ga);
        auto mid=std::chrono::steady_clock::now();
        ManTech::PositiveWeightedShuffle(b,wb,gb);
        auto end=std::chrono::steady_clock::now();
        if(a!=b || wa!=wb || ga!=gb){std::cerr<<"Large mismatch "<<n;return 2;}
        std::cout<<n<<": old_ms="<<std::chrono::duration<double,std::milli>(mid-start).count()
            <<" candidate_ms="<<std::chrono::duration<double,std::milli>(end-mid).count()<<"; exact match\n";
    }
}
