#include "test.h"
#include "ui_test.h"
#include <QDebug>


Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    void(QSpinBox::*spin) (int i)= &QSpinBox::valueChanged;
    connect(ui->spinBox,spin,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}
void Test::setNum(int num){
    ui->spinBox->setValue(num);
}
int Test::getNum(){
    return ui->spinBox->value();
}
Test::~Test()
{
    delete ui;
}
