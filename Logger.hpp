#ifndef LOGGER
#define LOGGER

#include <string>
#include <thread>

using namespace std;

class Logger
{
    public: 
        static void log(string message);
        static void log(string message, thread::id threadId);
};

#endif