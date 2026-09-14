#include "playerbot/ChatBroadcastSender.h"
#include <cassert>
#include <thread>
#include <vector>
#include <iostream>
using ai::chat::BroadcastSenderScope;
void run(unsigned id)
{
    bool value=false;
    assert(!BroadcastSenderScope::TryGet(id,value));
    {
        BroadcastSenderScope outer(id,true);
        assert(BroadcastSenderScope::TryGet(id,value)&&value);
        assert(!BroadcastSenderScope::TryGet(id+100,value));
        {
            BroadcastSenderScope nested(id+100,false);
            assert(BroadcastSenderScope::TryGet(id+100,value)&&!value);
            assert(!BroadcastSenderScope::TryGet(id,value));
        }
        assert(BroadcastSenderScope::TryGet(id,value)&&value);
        try {BroadcastSenderScope nested(id,false);throw 1;}catch(int){}
        assert(BroadcastSenderScope::TryGet(id,value)&&value);
        for(int i=0;i<10000;++i)assert(BroadcastSenderScope::TryGet(id,value)&&value);
    }
    assert(!BroadcastSenderScope::TryGet(id,value));
}
int main()
{
    std::vector<std::thread> threads;
    for(unsigned i=1;i<=8;++i)threads.emplace_back([i]{run(i);});
    for(auto& t:threads)t.join();
    run(1);
    std::cout<<"PASS synchronous sender scope, mismatch/fallback, false classification, nesting, unwinding and 8 independent threads\n";
}
