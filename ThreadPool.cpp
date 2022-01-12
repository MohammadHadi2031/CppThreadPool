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
                // WaitForWakeup();

                // if (_stop)
                // {
                //     return;
                // }

                // if (_tasks.empty())
                // {
                //     continue;
                // }

                // auto t = move(_tasks.dequeue());
                // t();
                shared_ptr<Task> t;
                {
                    unique_lock<mutex> lock(_cv_mutex);
                    _cv.wait(lock, [this] { return _stop || !_tasks.empty(); });
                    cout << "wait \t" << this_thread::get_id() << endl;

                    if (_stop)
                    {
                        return;
                    }

                    if (_tasks.empty())
                    {
                        continue;
                    }

                    t = move(_tasks.front());
                    _tasks.pop();
                }

                cout << "run task \t" << this_thread::get_id() << endl;
                (*t)();
                cout << "task done \t" << this_thread::get_id() << endl;
            }
        }));
    }
}

void ThreadPool::WaitForWakeup()
{
    unique_lock<mutex> lock(_cv_mutex);
    _cv.wait(lock, [this] { return _stop || !_tasks.empty(); });
    cout << "wake up signal" << endl;
}

void ThreadPool::AddTask(shared_ptr<Task> task)
{
    {
        unique_lock<mutex> lock(_cv_mutex);
        _tasks.push(task);
    }
    //_tasks.enqueue(task);
    _cv.notify_one();
    cout << "task added" << endl;
}

void ThreadPool::Stop()
{
    {
        unique_lock<mutex> lock(_cv_mutex);
        _stop = true;
    }
    
    _cv.notify_all();
    for(auto& thread : _threads)
    {
        thread.join();
    }
}