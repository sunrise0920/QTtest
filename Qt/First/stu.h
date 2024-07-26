#ifndef STU_H
#define STU_H

#include <iostream>
#include <string>
#include <QObject>
using namespace std;

class Stu : public QObject
{
    Q_OBJECT
public:
    explicit Stu(QObject *parent = 0);

signals:

public slots:
    //老版本QT槽要写到public slots中，新版本可以写在public或者全局下
    //返回值void，需要声明，也需要实现
    //可以有参数 可以重载
    void treat();
    void treat(QString eatwhat);
};

#endif // STU_H
