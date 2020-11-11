#pragma once

#include <thread>
#include <functional>
#include <vector>
#include "multithread/BoundedBlockingQue.h"
#include <iostream>

struct ThreadPool
{
typedef std::function<void()> Task;

public:
    ThreadPool(int threadNum = 0): threadNum(threadNum){}
    ~ThreadPool()
    {
        if(running) stop();
    }

    void start()
    {
        running = true;
        for(int i = 0; i < threadNum; i++)
        {
            threads.emplace_back(new std::thread(&ThreadPool::runInThread,this));
        }
     }

    void stop()
    {
        running = false;
        for(int i = 0; i < threadNum; i++)
        {
            que.put([this](){}); 
        }

        for(int i = 0; i < threadNum; i++)
        {
            if(threads[i]->joinable())
            {
                threads[i]->join();
            }
        }
    }

    void run(Task task)
    {
        if(threads.empty()) {task(); return;}
        if(running) que.put(task);
    }

private:
    void runInThread()
    {
        while(running)
        {
              Task task = que.take();
              if(task)
              {
                  task();
              }
        }
    }

private:
    bool running;
    BoundedBlockingQue<Task> que; //线程安全队列
    int threadNum;
    std::vector<std::unique_ptr<std::thread>> threads;
};