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
    cout << std::left << std::setw(25) << message << setw(25) << threadId << endl;
#endif
}