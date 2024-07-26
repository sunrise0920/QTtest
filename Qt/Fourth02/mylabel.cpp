#include "mylabel.h"
#include <QDebug>
#include<QMouseEvent>
Mylabel::Mylabel(QWidget *parent) : QLabel(parent)
{

}

void Mylabel::enterEvent(QEvent * event){
    qDebug() << "鼠标进入了";
}
void Mylabel::leaveEvent(QEvent *){
    qDebug() << "鼠标离开了";
}
void Mylabel::mouseMoveEvent(QMouseEvent *ev){
    QString str = QString("鼠标正在移动：x = %1, y =%2 ").arg(ev->x()).arg(ev->y());
    qDebug() << str;

}
void Mylabel::mousePressEvent(QMouseEvent *ev){
    qDebug() << "鼠标点击了";

}
void Mylabel::mouseReleaseEvent(QMouseEvent *ev){
    qDebug() << "鼠标释放了";

}
