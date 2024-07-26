#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_widget = new widgettest("世界滑动窗口",this);
    my_widget->resize(100,600);
    addDockWidget(Qt::LeftDockWidgetArea,my_widget);


}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
//    painter.drawEllipse();
    painter.drawPixmap(100,200,QPixmap(":/t.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
