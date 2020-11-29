#ifndef TASK_H
#define TASK_H
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QString>
#include <vector>

enum TaskStatusType { FINISHED, PERMANENT, TODO };
enum TaskType { ONCE, WEEK, MONTH, PERM , LONG};
class Task
{

public:
    QDate date ;
    QTime time;
    QString name;
    QString text;
    TaskStatusType status;
    TaskType type;
    int processed;
    void to_string_vec(std::vector<QString> &vec);
    void set_date(const  QDate &date );
    void set_time(const  QTime &time );
    void set_name(const QString &name);
    void set_text(const QString &text);
    void set_status(const TaskStatusType &st);
    void set_type(const TaskType &tp);
    void set_processed(int pr);
    Task();
};

#endif // TASK_H
