#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    speech = new QTextToSpeech ;
    base_file_name = "D://Home//my_base.bas";
    ui->setupUi(this);
    QString td = "Сегодня ";
    cd = QDate::currentDate();
    int wd= cd.dayOfWeek();
    int d = cd.day();
    int m  = cd .month();
     QString s1(QDate::longDayName(wd).toStdString().c_str() );
     QString s2(std::to_string(d).c_str());
     QString s3 = QDate::longMonthName(m);
   // speech->say( "Доброе утро" );
  //  qDebug()<<s3.right( 1 );
     if  (s3.right( 1 )== "ь")
     {
         s3.replace("ь", "я");
     }
     else
     {
        s3 = s3 + "a ";
     }
     QString cur_day = td+s1+", "+s2+ " "+  s3;
     QString cu = getDataWord(d);
     QString cur_day2 = td+s1+", "+cu+ " "+  s3;
    ui->label->setText(cur_day);

    dlg = new Dialog(this);
    ui->calendarWidget->setSelectedDate(cd);
    connect(dlg, SIGNAL(dlg->on_buttonBox_accepted()  ),this, SLOT(sendData()));

    load_icon();
    tasklst.loadFromFile(base_file_name);
    viewCurrTasks(cd);
    hello_user(cur_day2);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));



}

 void MainWindow::ShowContextMenu(const QPoint& pos)
 {
     QPoint globalPos = ui->listWidget->mapToGlobal(pos);
     QMenu myMenu;
     myMenu.addAction("Удалить", this, SLOT(on_action_1( )));
     myMenu.addAction("Отметить как выполненное", this, SLOT(on_action_2( )));
     myMenu.exec(globalPos);

 }

 void MainWindow::on_action_1()
 {
   // ui->listWidget->
    QList< QListWidgetItem* > items = ui->listWidget->selectedItems();
    QString s = items[0]->text();
    QDate dt = ui->calendarWidget->selectedDate();
    for (size_t i=0; i< tasklst.tasklist.size(); i++)
    {
        if ( tasklst.tasklist[i].date <= dt  )
        {
            if ( tasklst.tasklist[i].name == s)
            {
                tasklst.tasklist.erase(tasklst.tasklist.begin()+i);
                viewCurrTasks(cd);
            }

        }
    }
 }
 void MainWindow::on_action_2()
 {

 }

void MainWindow::load_icon()
{

    //stages_ic[0].
    QIcon i1(":/rec/imgs/Circle_Green.ico");
    stages_ic.push_back(i1);
    QIcon i2(":/rec/imgs/Circle_Yellow.ico");
    stages_ic.push_back(i2);
    QIcon i3(":/rec/imgs/Circle_Orange.ico");
    stages_ic.push_back(i3);
    QIcon i4(":/rec/imgs/Circle_Red.ico");
    stages_ic.push_back(i4);
    QIcon i5(":/rec/imgs/DrawingPin1_Blue.ico");
    stages_ic.push_back(i5);
    QIcon i6(":/rec/imgs/Flag1_Green.ico");
     stages_ic.push_back(i6);
     QIcon i7(":/rec/imgs/Clock4.ico");
      stages_ic.push_back(i7);
       QIcon i8(":/rec/imgs/Warning.ico");
       stages_ic.push_back(i8);
       QIcon i9(":/rec/imgs/Box_Blue.ico");
       stages_ic.push_back(i9);
       QIcon i10(":/rec/imgs/Box_Green.ico");
       stages_ic.push_back(i10);
       QIcon i11(":/rec/imgs/Box_Grey.ico");
       stages_ic.push_back(i11);
       QIcon i12(":/rec/imgs/Box_Yellow.ico");
       stages_ic.push_back(i12);
       QIcon i13(":/rec/imgs/Box_Red.ico");
       stages_ic.push_back(i13);
}

 void MainWindow::hello_user(QString st)
 {
 //    speech->say("Доброе утро  ");
     QTime tm = QTime::currentTime();
     int h = tm.hour();
     if (h <=  10) speech->say("Доброе утро  ");
     else if (h <=  18) speech->say("Добрый день  ");
     else speech->say("Добрый вечер  ");

    speech->say(st);

     bool today = false;
     bool yesterday = false;
     for (size_t i=0; i< tasklst.tasklist.size(); i++)
     {
         if ( tasklst.tasklist[i].date == cd  && tasklst.tasklist[i].type == ONCE)
          {
            if (!today)
            {
                speech->say("Список дел на сегодня  ");
                today = true;
            }
            speech->say(tasklst.tasklist[i].name);
          }
         if ( tasklst.tasklist[i].date <  cd &&  tasklst.tasklist[i].type == ONCE   && tasklst.tasklist[i].status ==  TODO)
          {
             if (!yesterday)
             {
                speech->say("Возможно вы забыли вчера  ");
                yesterday = true;
             }
                speech->say(tasklst.tasklist[i].name);
          }

     }


 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::viewCurrTasks(const QDate &dt)
{
    ui->listWidget->clear();
    for (size_t i=0; i< tasklst.tasklist.size(); i++)
    {
        QListWidgetItem* qi;
        if (tasklst.tasklist[i].type == PERM  )
        {
            qi = new QListWidgetItem( stages_ic[0], tasklst.tasklist[i].name );
             ui->listWidget->addItem(qi);
             continue;
        }
        if (tasklst.tasklist[i].type == LONG  )
        {
            qi = new QListWidgetItem( stages_ic[8], tasklst.tasklist[i].name );
            if  (tasklst.tasklist[i].date.addDays(2)  <= dt ) qi = new QListWidgetItem( stages_ic[9], tasklst.tasklist[i].name );
            if  (tasklst.tasklist[i].date.addDays(4)  <= dt ) qi = new QListWidgetItem( stages_ic[10], tasklst.tasklist[i].name );
            if  (tasklst.tasklist[i].date.addDays(7)  <= dt ) qi = new QListWidgetItem( stages_ic[11], tasklst.tasklist[i].name );
            if  (tasklst.tasklist[i].date.addDays(10)  <= dt ) qi = new QListWidgetItem( stages_ic[12], tasklst.tasklist[i].name );
             ui->listWidget->addItem(qi);
             continue;
        }

        if (tasklst.tasklist[i].type == WEEK  )
        {
            qi = new QListWidgetItem( stages_ic[6], tasklst.tasklist[i].name );
             ui->listWidget->addItem(qi);
             continue;
        }
        if ( tasklst.tasklist[i].date == dt  )
        {
            qi = new QListWidgetItem( stages_ic[5], tasklst.tasklist[i].name );
            ui->listWidget->addItem(qi);
        }
       if ( tasklst.tasklist[i].date == dt.addDays(1)  )
        {
            QListWidgetItem* qi = new QListWidgetItem( stages_ic[4], tasklst.tasklist[i].name );
            ui->listWidget->addItem(qi);
        }
       if ( tasklst.tasklist[i].date <  cd &&  tasklst.tasklist[i].type == ONCE   && tasklst.tasklist[i].status ==  TODO)
        {
            QListWidgetItem* qi = new QListWidgetItem( stages_ic[7], tasklst.tasklist[i].name );
            ui->listWidget->addItem(qi);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    dlg->show();
    if (dlg->exec())
    {
        tasklst.addTask(dlg->addTask());
    }
    viewCurrTasks(cd);
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate cdt = ui->calendarWidget->selectedDate();
    viewCurrTasks(cdt);
}


void MainWindow::on_MainWindow_destroyed()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    tasklst.saveToFile(base_file_name);
    event->accept();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

void MainWindow::on_action_triggered()
{
    //qDebug()<<"очистить все";
    tasklst.tasklist.clear();
    viewCurrTasks(cd);
}

QString MainWindow::getDataWord(int i)
{
    if (i==1) return "первое";
    if (i==2) return "второе";
    if (i==3) return "третье";
    if (i==4) return "четвертое";
    if (i==5) return "пятое";
    if (i==6) return "шестое";
    if (i==7) return "седьмое";
    if (i==8) return "восьмое";
    if (i==9) return "девятое";
    if (i==10) return "десятое";
    if (i==11) return "одиннадцатое";
    if (i==12) return "двенадцатое";
    if (i==13) return "тринадцатое";
    if (i==14) return "четырнадцатое";
    if (i==15) return "пятнадцатое";
    if (i==16) return "шестнадцатое";
    if (i==17) return "семнадцатое";
    if (i==18) return "восемнадцатое";
    if (i==19) return "девятнадцатое";
    if (i==20) return "двадцатое";
    if (i==21) return "двадцать первое";
    if (i==22) return "двадцать второе";
    if (i==23) return "двадцать третье";
    if (i==24) return "двадцать четвертое";
    if (i==25) return "двадцать пятое";
    if (i==26) return "двадцать шестое";
    if (i==27) return "двадцать седьмое";
    if (i==28) return "двадцать восьмое";
    if (i==29) return "двадцать девятое";
    if (i==30) return "тридцатое";
    if (i==31) return "тридцать первое";

}
