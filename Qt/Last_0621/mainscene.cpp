#include "mainscene.h"
#include "ui_mainscene.h"
#include <QObject>
#include <QAction>
#include <QPainter>
#include <QTimer>
#include <QSound>
#include "mypushbotton.h"
#include "chooselevelscene.h"

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币小游戏");
    QSound *backGround = new QSound(":/res/New.wav");
    connect(ui->actionQuit,QAction::triggered,[=](){
//        backGround->play();
        this->close();
    });

    MyPushBotton *mbt = new MyPushBotton(":/res/MenuSceneStartButton.png");
    mbt->setParent(this);
    mbt->move(this->width()*0.5-mbt->width()*0.5,this->height()*0.7);
    ChooseLevelScene *chooselevel = new ChooseLevelScene();
    connect(mbt,&MyPushBotton::clicked,[=](){
//        mbt->zoom1();
        mbt->zoom2();
        QTimer::singleShot(500,this,[=]{
            this->hide();
            chooselevel->setGeometry(this->geometry());
            chooselevel->show();
        });
    });
    connect(chooselevel,&ChooseLevelScene::chooseSceneBack,[=]{
        this->setGeometry(chooselevel->geometry());
        this->show();});
}
void MainScene::paintEvent(QPaintEvent *){
    //创建画家，并制定设备
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //标题
    pix.load(":/res/Title.png");
    pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}
MainScene::~MainScene()
{
    delete ui;
}
