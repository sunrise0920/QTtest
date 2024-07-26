#include "stu.h"
#include<Qdebug>
Stu::Stu(QObject *parent) : QObject(parent)
{

}
void Stu::treat(){
    qDebug() << "学生请老师吃饭";
}
void Stu::treat(QString eatwhat){
    qDebug() << "学生请老师吃饭" << eatwhat.toUtf8().data();
}
