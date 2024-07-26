#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
//老师 学生
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//（1）普通的窗口
//    resize(1080,600);
//    setFixedHeight(600);
//    QPushButton *btn01 = new QPushButton("First",this);
//    btn01->move(100,250);
//    setWindowTitle("NUIST");
//    btn01->setText("rename");
//    btn01->resize(100,100);
//    connect(btn01,&QPushButton::clicked,this,&MainWindow::close);
//（2）无参数信号
//    this->tea = new Teacheer(this);
//    this->stu = new Stu(this);
//    //连接
//    connect(tea,&Teacheer::hungry,stu,&Stu::treat);
//    //触发信号
//    Classover();
//（3）有参数信号与槽
//      this->tea = new Teacheer(this);
//      this->stu = new Stu(this);
//    !!!!!!!!!!!!!!!!!!有参，信号连接槽
//      void (Teacheer:: *teafun)(QString)= &Teacheer::hungry;
//      void (Stu:: *stufun)(QString)= &Stu::treat;
//      connect(tea,teafun,stu,stufun);
//      Classover02();
//      QPushButton *btn = new QPushButton("下课",this);
//      this->resize(500,500);
//      connect(btn,&QPushButton::clicked,this,&MainWindow::Classover02);
//    !!!!!!!!!!!!!!!!!!无参，信号连接信号
//      QPushButton *btn = new QPushButton("下课啦",this);
//      void (Teacheer:: *teafun2)(void)= &Teacheer::hungry;
//      void (Stu:: *stufun2)(void)= &Stu::treat;
//      connect(tea,teafun2,stu,stufun2);
//      connect(btn, &QPushButton::clicked, tea,teafun2);
//    !!!!!!!!!!!!!断开信号
//      disconnect(tea,teafun2,stu,stufun2);
//    !!!!!!!!!!!!!一个信号可以连接多个槽函数
//    !!!!!!!!!!!!!多个信号可以连接一个槽函数
//    !!!!!!!!!!!!!信号和槽函数的参数类型必须匹配！信号的参数可以多余槽的参数个数
//(4)利用lambda表达式实现点击按钮关闭窗口
    QPushButton *btn = new QPushButton("happy",this);
//    connect(btn,&QPushButton::clicked,this,&MainWindow::close);
    connect(btn,&QPushButton::clicked,this,[=](){
//        this->close();
        btn->setText("aaa");
    });
}
void MainWindow::Classover(){
    qDebug()<<"下课啦";
    emit tea->hungry();
}
void MainWindow::Classover02(){
    qDebug()<<"you下课啦";
    emit tea->hungry("麻辣小龙虾");
}

MainWindow::~MainWindow()
{
    delete ui;
}
