#ifndef PRINT_TASK
#define PRINT_TASK

#include <string>
#include "Task.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class PrintTask : public Task
{
    public:
        PrintTask(string message, int delayMilliseconds);
    
    protected:
        virtual void Do();

    private:
        string _message;
        int _delayMilliseconds;
};

#endif