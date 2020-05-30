#include "multithread/BoundedBlockingQue.h"
#include <thread>
#include <vector>
#include "ftport.h"
#include "gtest/gtest.h"
#include <iostream>

namespace
{
   class testBBQ : public testing::Test
   {
   };
}

FT_LIANG_BEG

BoundedBlockingQue<int> que;

void produce()
{
    for(int i = 0; i < 10; i++)
    {
        que.put(i);
        printf("%lu put %d\n", std::this_thread::get_id(), i);
    }
}

void consume()
{
     while(true)
    {
        int a = que.take();
        printf("%lu pop %d\n", std::this_thread::get_id(), a);
        if(a == 42) break;
    }
}

TEST_F(testBBQ, test_MPMC)
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 2; i++)
    {
        threads.push_back(std::thread(consume));
        threads.push_back(std::thread(produce));
    }

    sleep(1);

    que.put(42);
    que.put(42);
    
    for(int i = 0; i < 4; i++)
    {
        threads[i].join();
    }
}

FT_LIANG_END