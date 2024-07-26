#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"
#include <QTimer>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,ui->spinBox,[=](){
        int i=ui->spinBox->value();
        ui->spinBox->setValue(i+1);});
    Tid1 = startTimer(1000);
    Tid2 = startTimer(2000);
    QTimer * timer = new QTimer();
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });
    connect(ui->pushButton_2,&QPushButton::clicked,timer,[=](){
        timer->start(500);
    });
    connect(ui->pushButton_3,&QPushButton::clicked,timer,[=](){
        timer->stop();
    });
}


void Widget::timerEvent(QTimerEvent *ev){
    static int num = 1;
    if (ev->timerId()==Tid1){
        ui->label_2->setText(QString::number(num++));
    }
    else if(ev->timerId()==Tid2) {
        ui->label_3->setText(QString::number(num++));
    }

}


Widget::~Widget()
{
    delete ui;
}
