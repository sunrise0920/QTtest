#ifndef MYPUSHBOTTON_H
#define MYPUSHBOTTON_H
#include <QPushButton>
#include <QWidget>

class MyPushBotton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushBotton(QWidget *parent = 0);
    MyPushBotton(QString First,QString Second = "");
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    //按钮跳跃，下降
    void zoom1();
    void zoom2();
    QString Firpath;
    QString Secpath;

signals:


public slots:
};

#endif // MYPUSHBOTTON_H
