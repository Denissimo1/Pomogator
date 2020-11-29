#include "task.h"

Task::Task()
{

}

void Task::to_string_vec(std::vector<QString> &vec)
{
    vec.clear();
    QString s1 = date.toString();
    vec.push_back(s1);
    s1 = time.toString()+ "\n";
    vec.push_back(s1);
    s1 = name + "\n";
    vec.push_back(s1);
    s1 = text + "\n";
    vec.push_back(s1);
    switch (status) {
    case FINISHED:
        vec.push_back("FINISHED\n");
        break;
    case PERMANENT:
        vec.push_back("PERMANENT\n");
         break;
    case TODO:
        vec.push_back("TODO\n");
         break;
    }
    //ONCE, WEEK, MONTH, PERM , LONG
    switch (type) {
    case ONCE:
        vec.push_back("ONCE\n");
        break;
    case WEEK:
        vec.push_back("WEEK\n");
         break;
    case MONTH:
        vec.push_back("MONTH\n");
         break;
    case PERM:
        vec.push_back("PERM\n");
         break;
    case LONG:
        vec.push_back("LONG\n");
         break;
    }
    QString pr(std::to_string(processed).c_str());

    vec.push_back(pr+"\n");
}
void Task::set_date(const  QDate &_date )
{
    date = _date;
}
void Task::set_time(const  QTime &_time )
{
    time = _time;
}
void Task::set_name(const QString &_name)
{
    name = _name;
}
void Task::set_text(const QString &_text)
{
    text = _text;
}
void Task::set_status(const TaskStatusType &_st)
{
    status = _st;
}
void Task::set_type(const TaskType &tp)
{
    type = tp;
}
void Task::set_processed(int _pr)
{
    processed = _pr;
}


