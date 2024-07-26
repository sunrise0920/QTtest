#include "mainwindow.h"
#include"QMenuBar"
#include<QToolBar>
#include<QDebug>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QDockWidget>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,500);
    //!!!!!!!!!!!!!!新建菜单栏，返回菜单栏指针
    QMenuBar * bar = menuBar();
    //把菜单栏放入到窗口中
    setMenuBar(bar);
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");
    fileMenu->addAction("新建");
    fileMenu->addSeparator();
    fileMenu->addAction("打开");
    //!!!!!!!!!!!!!!新建工具栏
    QToolBar* toolbar = new QToolBar(this);
    addToolBar(Qt::RightToolBarArea,toolbar);
    //只允许左右 不能上下
    toolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea|Qt::BottomToolBarArea);
    //设置浮动
    toolbar->setFloatable(false);
    //设置移动
    toolbar->setMovable(true);
    //设置内容
    toolbar->addAction("画笔");
    toolbar->addSeparator();
    toolbar->addAction("工具");
    QPushButton *btn01 = new QPushButton("Help",this);
    toolbar->addWidget(btn01);
    //！！！！！！！！！！新建状态栏,最多一个
    QStatusBar *Sbar = statusBar();
    setStatusBar(Sbar);
    //设置状态栏
    QLabel *label = new QLabel("提示信息",this);
    Sbar->addWidget(label);
    QLabel *label2 = new QLabel("第一个QT",this);
    Sbar->addPermanentWidget(label2);
    //铆接部件（浮动窗口）
    QDockWidget *Fwin = new QDockWidget("浮动窗口",this);
    addDockWidget(Qt::LeftDockWidgetArea,Fwin);
    //只允许上下
    Fwin->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    //设置中心部件 只有一个
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
}
MainWindow::~MainWindow()
{

}
