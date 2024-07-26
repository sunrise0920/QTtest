#include "mycoin.h"
#include <QPushButton>
#include <QDebug>

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString butImg){
    QPixmap pix;
    if(!pix.load(butImg)){
        qDebug()<<butImg<<"图片加载失败";
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    time1 = new QTimer(this);
    time2 = new QTimer(this);
    connect(time1,&QTimer::timeout,[=]{
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min > this->max){
            this->min = 1;
            time1->stop();
            isAnimation = false;
        }
    });
    connect(time2,&QTimer::timeout,[=]{
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->max < this->min){
            this->max = 8;
            time2->stop();
            isAnimation = false;
        }
    });

}
void MyCoin::changeFlag(){
    if (flag){
        time1->start(30);
        isAnimation = true;
        flag = false;
    }
    else{
        time2->start(30);
        flag = true;
        isAnimation = true;
    }
}
void MyCoin::mousePressEvent(QMouseEvent *e){
    if (this->isAnimation || isWin == true){
        return;
    }
    else {
        return QPushButton::mousePressEvent(e);
    }
}
