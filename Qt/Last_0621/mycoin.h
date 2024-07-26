#ifndef MYCOIN_H
#define MYCOIN_H
#include <QPushButton>
#include <QWidget>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = 0);
    MyCoin(QString butImg);
    void changeFlag();
    QTimer *time1;
    QTimer *time2;
    int min = 1;
    int max = 8;
    int posX;
    int posY;
    bool flag;
    bool isAnimation=false;
    void mousePressEvent(QMouseEvent *e);
    bool isWin = false;

signals:


public slots:
};

#endif // MYCOIN_H
