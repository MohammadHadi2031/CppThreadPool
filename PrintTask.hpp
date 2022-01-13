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
        void Do() override;

    private:
        string _message;
        int _delayMilliseconds;
};

#endif