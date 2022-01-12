#include "Task.hpp"

using namespace std;

void Task::operator()()
{
    Do();
}

void Task::Do()
{
    cout << "not implemented" << endl;
}