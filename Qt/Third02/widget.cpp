#include "widget.h"
#include "ui_widget.h"
#include <QStringData>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"职业"<<"年龄");
    ui->tableWidget->setRowCount(5);
    QStringList names;
    names<<"孙悟空"<<"程咬金"<<"甄姬"<<"大司命"<<"明世隐";
    QStringList Sex;
    Sex<<"打野"<<"坦克"<<"法师"<<"刺客"<<"游走";
    QStringList ages;
    ages<<"100000"<<"66"<<"35"<<"32"<<"18";
    for(int i = 0; i < 5; i++){
        int col=0;
        ui->tableWidget->setItem(i,col,new QTableWidgetItem(names[i]));
        col++;
        ui->tableWidget->setItem(i,col,new QTableWidgetItem(Sex[i]));
        col++;
        ui->tableWidget->setItem(i,col,new QTableWidgetItem(ages[i]));
    }

}

Widget::~Widget()
{
    delete ui;
}
