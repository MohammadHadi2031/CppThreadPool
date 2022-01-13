#include "ThreadPool.hpp"

ThreadPool::ThreadPool() : ThreadPool(4)
{

}

ThreadPool::ThreadPool(int size) : _stop(false)
{
    for (auto i = 0; i < size; i++)
    {
        _threads.push_back(thread([this] 
        {
            while(true)
            {
                shared_ptr<Task> t;
                {
                    unique_lock<mutex> lock(_cv_mutex);
                    _cv.wait(lock, [this] { return _stop || !_tasks.empty(); });
                    Logger::log("wait", this_thread::get_id());

                    if (_stop)
                    {
                        Logger::log("stopped", this_thread::get_id());
                        return;
                    }

                    if (_tasks.empty())
                    {
                        continue;
                    }

                    t = _tasks.front();
                    _tasks.pop();
                }

                Logger::log("running task", this_thread::get_id());
                (*t)();
                Logger::log("task done", this_thread::get_id());
            }
        }));
    }
}

void ThreadPool::AddTask(shared_ptr<Task> task)
{
    {
        unique_lock<mutex> lock(_cv_mutex);
        _tasks.push(task);
    }

    _cv.notify_one();
}

void ThreadPool::Stop()
{
    {
        unique_lock<mutex> lock(_cv_mutex);
        _stop = true;
    }
    
    Logger::log("notify all");
    _cv.notify_all();
    for(auto& thread : _threads)
    {
        Logger::log("joining thread", thread.get_id());
        thread.join();
    }
}
