#ifndef TASK
#define TASK

#include <iostream>

class Task
{
    public:
        void operator()();

    protected:
        virtual void Do();
};

#endif