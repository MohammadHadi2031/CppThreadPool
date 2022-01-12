#ifndef THREADPOOL
#define THREADPOOL

#include "Task.hpp"
#include <queue>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include "ConcurrentTaskQueue.hpp"
#include <iostream>
#include <memory>

using namespace std;

class ThreadPool
{
    public:
        ThreadPool();
        ThreadPool(int size);
        void AddTask(shared_ptr<Task> task);
        void Stop();

    private: 
        queue<shared_ptr<Task>> _tasks;
        vector<thread> _threads;
        bool _stop;
        condition_variable _cv;
        mutex _cv_mutex;
        void WaitForWakeup();
};

#endif