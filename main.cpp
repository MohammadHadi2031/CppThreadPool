#include <iostream>
#include "PrintTask.hpp"
#include <thread>
#include <chrono>
#include "ThreadPool.hpp"
#include <string>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<Task> printer(new PrintTask("hello world", 0));
    (*printer)();

    ThreadPool tp(3);
    
    for (int i = 0; i < 10; i++)
    {
        auto message = "student" + to_string(i);
        shared_ptr<Task> t(new PrintTask(message, 1000));
        tp.AddTask(t);
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    this_thread::sleep_for(chrono::milliseconds(3000));
    tp.Stop();

    return 0;
}