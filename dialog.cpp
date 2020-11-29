#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());

}

Dialog::~Dialog()
{
    delete ui;
}

Task Dialog::addTask()
{
    Task tsk;
    //тут заполним его потом

    tsk.set_name(ui->lineEdit->text());
    tsk.set_text(ui->textEdit->toPlainText());
    tsk.set_date( ui->dateEdit->date());
    QString s = ui->comboBox->currentText() ;
    TaskType tp = LONG;
    if (s == "ONCE") tp = ONCE;
    if (s == "WEEK") tp = WEEK;
    if (s == "MONTH") tp = MONTH;
    if (s =="PERM") tp = PERM;
    tsk.set_type( tp );
    tsk.set_status(TODO);
    tsk.set_processed(0);

    return tsk;
}

void Dialog::on_buttonBox_accepted()
{

}
