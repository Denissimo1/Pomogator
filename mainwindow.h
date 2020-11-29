#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtTextToSpeech>
#include <QMainWindow>
#include <QCloseEvent>
#include <QListWidget>
#include <QListWidgetItem>
#include "tasklist.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QDate cd;
    TaskList tasklst;
    void viewCurrTasks(const QDate &dt);
    string base_file_name;
    QTextToSpeech * speech ;
    void hello_user(QString st);
    vector<QIcon> stages_ic;
    void load_icon();
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_clicked();
    void ShowContextMenu(const QPoint& pos);
    void on_action_1();
    void on_action_2();
    void on_calendarWidget_selectionChanged();

    void on_MainWindow_destroyed();

 //   void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_action_triggered();

private:
    QString getDataWord(int i);
    Ui::MainWindow *ui;
    Dialog *dlg;
};
#endif // MAINWINDOW_H
