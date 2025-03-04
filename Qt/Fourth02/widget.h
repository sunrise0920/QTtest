#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void timerEvent(QTimerEvent *);

    int Tid1;
    int Tid2;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
