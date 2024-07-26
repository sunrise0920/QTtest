#ifndef TEACHEER_H
#define TEACHEER_H
#include <iostream>
#include <string>
#include <QObject>
using namespace std;

class Teacheer : public QObject
{
    Q_OBJECT
public:
    explicit Teacheer(QObject *parent = 0);

signals:
    //自定义信号
    //没有返回值void，只需要声明，不需要实现
    //可以有参数 可以重载
    void hungry();
    void hungry(QString eatwhat);
public slots:
};

#endif // TEACHEER_H
