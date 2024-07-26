#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QTimer>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *time = new QTimer(this);

    connect(time,&QTimer::timeout,[=](){
        posX -=10;
        update();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        posX +=100;
        update();

    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
       time->start(100);
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        time->stop();
    });

}



void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if (posX == -800){ posX=0;}
    painter.drawPixmap(QPoint(posX,240),QPixmap(":/300.jpg"));
    painter.drawPixmap(QPoint(10,510),QPixmap(":/5.jpg"));


}
Widget::~Widget()
{
    delete ui;
}
