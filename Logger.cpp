#include "Logger.hpp"

void Logger::log(string message)
{
#ifdef DEBUG
    cout << message << endl;
#endif
}

void Logger::log(string message, thread::id threadId)
{
#ifdef DEBUG
    cout << message << "\t\t\t" << threadId << endl;
#endif
}