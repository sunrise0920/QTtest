#include "mypushbotton.h"
#include <QDebug>
#include <QPropertyAnimation>

MyPushBotton::MyPushBotton(QWidget *parent) : QPushButton(parent)
{

}
MyPushBotton::MyPushBotton(QString First,QString Second){
    Firpath = First;
    Secpath = Second;
    QPixmap pix;
    if (!(pix.load(Firpath))){
        qDebug()<< "图片加载失败！!"<< endl;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
void MyPushBotton::mousePressEvent(QMouseEvent *e){
    if (Secpath != "")
    {
        QPixmap pix;
        if (!(pix.load(Secpath)))
        {
            qDebug()<< Secpath << "加载失败！！！";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}
void MyPushBotton::mouseReleaseEvent(QMouseEvent *e){
    if (Firpath != ""){
        QPixmap pix;
        if (!(pix.load(Firpath)))
        {
            qDebug()<< Firpath << "加载失败！！！";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
void MyPushBotton::zoom1(){
    //创建动画对象
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置（原坐标）
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置（跳动后的坐标）
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线，设置效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}

void MyPushBotton::zoom2(){
    //创建动画对象
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置（原坐标）
    animation1->setStartValue(QRect(this->x()+10,this->y(),this->width(),this->height()));
    //创建结束位置（跳动后的坐标）
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置缓和曲线，设置效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}
