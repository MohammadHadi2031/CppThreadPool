#include "ConcurrentTaskQueue.hpp"

void ConcurrentTaskQueue::enqueue(Task task)
{
    unique_lock<mutex> lock(_mutex);
    push(task);
}

Task ConcurrentTaskQueue::dequeue()
{
    unique_lock<mutex> lock(_mutex);
    auto t = move(front());
    pop();
    return t;
}

bool ConcurrentTaskQueue::empty()
{
    unique_lock<mutex> lock(_mutex);
    return empty();
}