#include "ConcurrentTaskQueue.hpp"

void ConcurrentTaskQueue::enqueue(shared_ptr<Task> task)
{
    unique_lock<mutex> lock(_mutex);
    push(task);
}

shared_ptr<Task> ConcurrentTaskQueue::dequeue()
{
    unique_lock<mutex> lock(_mutex);
    auto t = front();
    pop();
    return t;
}

bool ConcurrentTaskQueue::empty()
{
    unique_lock<mutex> lock(_mutex);
    return empty();
}