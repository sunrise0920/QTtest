#include "widgettest.h"
#include "ui_widgettest.h"
#include <QPainter>

widgettest::widgettest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgettest)
{
    ui->setupUi(this);

}

void widgettest::paintEvent(QPaintEvent *){
    QPainter painter(this);
//    painter.drawEllipse();
    painter.drawPixmap(100,200,QPixmap(":/t.jpg"));
}
widgettest::~widgettest()
{
    delete ui;
}
