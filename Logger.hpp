#ifndef LOGGER
#define LOGGER

#define DEBUG

#include <string>
#include <thread>
#include <iostream>
#include <iomanip>

using namespace std;

class Logger
{
    public: 
        static void log(string message);
        static void log(string message, thread::id threadId);
};

#endif