#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{   //应用程序对象，有且仅有一个
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
