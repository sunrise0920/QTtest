#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_10,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
      });
    connect(ui->pushButton_11,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
      });
    connect(ui->pushButton_12,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
      });

    ui->comboBox->addItems(QStringList()<<"你好"<<"你不好"<<"你差不多好");
    connect(ui->pushButton_13,&QPushButton::clicked,this,[=](){ui->comboBox->setCurrentIndex(0);});
}

Widget::~Widget()
{
    delete ui;
}
