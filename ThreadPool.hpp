#ifndef THREADPOOL
#define THREADPOOL

#include "Task.hpp"
#include <queue>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <memory>
#include "Logger.hpp"
#include <sstream>

using namespace std;

class ThreadPool
{
    public:
        ThreadPool();
        ThreadPool(int size);
        void AddTask(shared_ptr<Task> task);
        void Stop();
        //static string ToString(thread::id threadId);

    private: 
        queue<shared_ptr<Task>> _tasks;
        vector<thread> _threads;
        bool _stop;
        condition_variable _cv;
        mutex _cv_mutex;
};

#endif