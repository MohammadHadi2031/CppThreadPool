#ifndef CONCURRENT_TASK_QUEUE
#define CONCURRENT_TASK_QUEUE

#include <queue>
#include "Task.hpp"
#include <mutex>

using namespace std;

class ConcurrentTaskQueue : public queue<Task>
{
    public:
        void enqueue(Task t);
        Task dequeue();
        bool empty();

    private:
        mutex _mutex;
};


#endif