#ifndef CONCURRENT_TASK_QUEUE
#define CONCURRENT_TASK_QUEUE

#include <queue>
#include "Task.hpp"
#include <mutex>
#include <memory>

using namespace std;

class ConcurrentTaskQueue : public queue<shared_ptr<Task>>
{
    public:
        void enqueue(shared_ptr<Task> t);
        shared_ptr<Task> dequeue();
        bool empty();

    private:
        mutex _mutex;
};


#endif