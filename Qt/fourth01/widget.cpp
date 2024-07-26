#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){qDebug()<<ui->widget->getNum();});
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){ui->widget->setNum(125);});
}

Widget::~Widget()
{
    delete ui;
}
