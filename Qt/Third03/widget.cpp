#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"技能");
    QTreeWidgetItem * Fitem = new QTreeWidgetItem(QStringList()<<"法师");
    ui->treeWidget->addTopLevelItem(Fitem);
    QTreeWidgetItem * Fitem1 = new QTreeWidgetItem(QStringList()<<"妲己"<<"魅惑");
    Fitem->addChild(Fitem1);
    QTreeWidgetItem * Fitem2 = new QTreeWidgetItem(QStringList()<<"安其拉"<<"眩晕");
    Fitem->addChild(Fitem2);
    QTreeWidgetItem * Fitem3 = new QTreeWidgetItem(QStringList()<<"貂蝉"<<"闪避");
    Fitem->addChild(Fitem3);

    QTreeWidgetItem * Ditem = new QTreeWidgetItem(QStringList()<<"打野");
    ui->treeWidget->addTopLevelItem(Ditem);
    QTreeWidgetItem * Ditem1 = new QTreeWidgetItem(QStringList()<<"妲己"<<"魅惑");
    Ditem->addChild(Ditem1);
    QTreeWidgetItem * Ditem2 = new QTreeWidgetItem(QStringList()<<"安其拉"<<"眩晕");
    Ditem->addChild(Ditem2);
    QTreeWidgetItem * Ditem3 = new QTreeWidgetItem(QStringList()<<"貂蝉"<<"闪避");
    Ditem->addChild(Ditem3);
    QTreeWidgetItem * Yitem = new QTreeWidgetItem(QStringList()<<"游走");
    ui->treeWidget->addTopLevelItem(Yitem);
    QTreeWidgetItem * Yitem1 = new QTreeWidgetItem(QStringList()<<"妲己"<<"魅惑");
    Yitem->addChild(Yitem1);
    QTreeWidgetItem * Yitem2 = new QTreeWidgetItem(QStringList()<<"安其拉"<<"眩晕");
    Yitem->addChild(Yitem2);
    QTreeWidgetItem * Yitem3 = new QTreeWidgetItem(QStringList()<<"貂蝉"<<"闪避");
    Yitem->addChild(Yitem3);
}

Widget::~Widget()
{
    delete ui;
}
