#include "PrintTask.hpp"

using namespace std;

PrintTask::PrintTask(string message, int delayMilliseconds) : _message(message), _delayMilliseconds(delayMilliseconds)
{

}

void PrintTask::Do()
{
    cout << "here babe " << _delayMilliseconds << endl;
    this_thread::sleep_for (chrono::milliseconds(_delayMilliseconds));
    cout << _message << endl;
}