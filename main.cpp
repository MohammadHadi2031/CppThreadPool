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
    auto printer = PrintTask("hello world" + to_string(12), 0);
    printer();

    ThreadPool tp(3);
    
    for (int i = 0; i < 10; i++)
    {
        auto message = "student" + to_string(i);
        auto t = make_shared<Task>(PrintTask(message, 0));
        tp.AddTask(t);
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    tp.Stop();

    return 0;
}