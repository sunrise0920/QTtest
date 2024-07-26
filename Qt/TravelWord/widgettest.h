#ifndef WIDGETTEST_H
#define WIDGETTEST_H

#include <QWidget>

namespace Ui {
class widgettest;
}

class widgettest : public QWidget
{
    Q_OBJECT

public:
    explicit widgettest(QWidget *parent = 0);
    ~widgettest();
    void paintEvent(QPaintEvent *);

private:
    Ui::widgettest *ui;
};

#endif // WIDGETTEST_H
