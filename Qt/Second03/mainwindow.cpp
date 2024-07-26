#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QDebug>
#include<QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮弹出对话窗
    connect(ui->actionTest,&QAction::triggered,[=](){
    //模态对话框：不可以对其他窗口操作。
    //模态创建 阻塞
//    QDialog dlg(this);
//    dlg.resize(200,100);
//    dlg.exec();
    //消息对话框
//    QMessageBox::critical(this,"critical","出错啦");
    //消息对话框
//    QMessageBox::information(this,"消息","nihao");
    //提问对话框
//    QMessageBox::question(this,"ask","请选择：",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
//     QMessageBox::warning(this,"jinggao","jinggao");
    //颜色
//    QColor color = QColorDialog::getColor(QColor(255,0,0));
//    qDebug() << color.red() << color.green() << color.blue();
    //文件对话框 父亲，标题，打开路径，过滤格式
//     QString str = QFileDialog::getOpenFileName(this,"打开对应文件","C:\\Users\\xyWang\\Desktop\\C","(*.txt)"); //返回值是路径
    //字体对话框
//     bool flag;
//     QFont font = QFontDialog::getFont(&flag,QFont("楷体",36));
//     qDebug() << font.family().toUtf8().data() << font.pointSize() << font.bold() << font.italic();
    });
    connect(ui->actionOpen,&QAction::triggered,[=](){
    //非模态对话框：可以对其他窗口操作。
    //非模态创建
    QDialog *dlg2 = new QDialog(this);  //防止直接被释放
    dlg2->resize(300,100);
    dlg2->show();
    dlg2->setAttribute(Qt::WA_DeleteOnClose);
    });
    //消息对话框

}

MainWindow::~MainWindow()
{
    delete ui;
}
