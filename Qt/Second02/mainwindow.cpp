#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->actionNew->setIcon(QIcon("C:\\Users\\xyWang\\Pictures\\Saved Pictures\\test.jpg"));
    //添加到QT资源文件中
    ui->actionNew->setIcon(QIcon(":/F/Saved Pictures/1.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
