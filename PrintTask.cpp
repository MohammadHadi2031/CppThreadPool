#include "PrintTask.hpp"

using namespace std;

PrintTask::PrintTask(string message, int delayMilliseconds) :
    Task(),
    _message(message),
    _delayMilliseconds(delayMilliseconds)
{

}

void PrintTask::Do()
{
    this_thread::sleep_for (chrono::milliseconds(_delayMilliseconds));
    cout << _message << endl;
}