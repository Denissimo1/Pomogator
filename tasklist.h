#ifndef TASKLIST_H
#define TASKLIST_H
#include "task.h"
#include <vector>
#include <QFile>

using namespace std;

class TaskList
{
    void insertTaskToFile(QFile &file, Task &tsk);
    void readTaskFromFile(QFile &file,  Task &tsk);
public:
     vector<Task> tasklist;
    void loadFromFile(const string &f_name);
    void saveToFile(const string &f_name);
    void addTask(const Task& tsk);
    TaskList();
};

#endif // TASKLIST_H
