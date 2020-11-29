#include "tasklist.h"



TaskList::TaskList()
{

}

void TaskList::readTaskFromFile(QFile &file,  Task &tsk)
{
     QString s1 = file.readLine();
     s1 = s1.left(s1.length()-1);
     QDate dt = QDate::fromString(s1);
     tsk.set_date(dt);
     QString s2 = file.readLine();
      s2 = s2.left(s2.length()-1);
     tsk.set_name(s2);
     QString s3 = file.readLine();
      s3 = s3.left(s3.length()-1);
     tsk.set_text(s3);
    //QString s4 = file.readLine();
   // QTime tt = QTime::fromString(s4);
   //  tsk.set_time(tt);
     QString s6 = file.readLine();
     s6 = s6.left(s6.length()-1);
     if (s6 == "FINISHED")   tsk.set_status(FINISHED);
      if (s6 == "PERMANENT")   tsk.set_status(PERMANENT);
       if (s6 == "TODO")   tsk.set_status(TODO);
     QString s5 = file.readLine();
      s5 = s5.left(s5.length()-1);
       if (s5 == "ONCE")   tsk.set_type(ONCE);
        if (s5 == "WEEK")   tsk.set_type(WEEK);
         if (s5 == "MONTH")   tsk.set_type(MONTH);
          if (s5 == "PERM")   tsk.set_type(PERM);
           if (s5 == "LONG")   tsk.set_type(LONG);


     QString s7 = file.readLine();
      s7 = s7.left(s7.length()-1);
     tsk.set_processed(s7.toInt());
}
 void TaskList::insertTaskToFile(QFile &file, Task &tsk)
 {
      std::vector<QString> vec;
     tsk.to_string_vec(vec);
     for (size_t i=0; i< vec.size(); i++) file.write(vec[i].toUtf8());
 }
void TaskList::loadFromFile(const string &f_name)
{
    QFile file(f_name.c_str());
    file.open(QIODevice::ReadOnly);
    QString s = file.readLine();
    int n = s.toInt();
    tasklist.clear();
    for (size_t i=0; i<n;i++)
    {
        Task tsk;
        readTaskFromFile(file, tsk);
        tasklist.push_back(tsk);
    }
     file.close();
}
void TaskList::saveToFile(const string &f_name)
{
    QFile file(f_name.c_str());
    file.open(QIODevice::WriteOnly);
    int sz = tasklist.size();
    string ssz = to_string(sz)+"\n";
    file.write(ssz.c_str());
    for(size_t i=0; i<tasklist.size();i++)
    {
        insertTaskToFile(file, tasklist[i]);
    }
    file.close();
}
void TaskList::addTask(const Task& tsk )
{
    tasklist.push_back(tsk);
}
