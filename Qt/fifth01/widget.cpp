#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Pixmap绘图设备
//    QPixmap pix(300,300);
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(100,100),50,50);

//    pix.save("C:\\Users\\xyWang\\Desktop\\C\\Qt\\fifth01\\fix.png");

    //Qimage绘图设备
//    QImage test(300,300,QImage::Format_RGB32);
//    test.fill(Qt::white);
    resize(1000,200);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\xyWang\\Desktop\\C\\Qt\\fifth01");
        ui->lineEdit->setText(path);
        QFile file(path);
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll();
        QByteArray array02;
        while(!file.atEnd()){
            array02 += file.readLine();
        }
        ui->textEdit->setText(array02);
        file.close();
        //写文件
//        file.open(QIODevice::Append);
//        file.write("-----wxy,make.");
        QFileInfo info(path);
        qDebug()<< "文件名称" << info.fileName() << "size:" << info.size()<< "文件的后缀名" << info.suffix();
        qDebug()<< "创建日期：" << info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<< "最后修改日期：" << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}
