#include "chooselevelscene.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>
#include "mypushbotton.h"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320,588);
    //设置页面的图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡");

    QMenuBar *mb = this->menuBar();
    this->setMenuBar(mb);
    QMenu *startM = mb->addMenu("开始");
    QAction *quit = startM->addAction("退出");

    connect(quit,&QAction::triggered,[=]{
                this->close();
            });
    MyPushBotton *closebt = new MyPushBotton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closebt->setParent(this);
    closebt->move(this->width()-closebt->width(),this->height()-closebt->height());
    QSound *backSound = new QSound(":/res/BackButtonSound.wav");
    connect(closebt,&MyPushBotton::clicked,[=](){
        backSound->play();
        QTimer::singleShot(500,this,[=]{
            this->hide();
            emit this->chooseSceneBack();
        });
    });
    for(int i = 0; i < 20; i++){
        //创建按钮
        MyPushBotton *choosebt = new MyPushBotton(":/res/LevelIcon.png");
        choosebt->setParent(this);
        choosebt->move(25 + (i%4)*70 , 130+ (i/4)*70);
        //按钮上显示字体
        QLabel*label = new QLabel;
        label->setParent(this);
        label->setFixedSize(choosebt->width(),choosebt->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label->move(25 + (i%4)*70 , 130+ (i/4)*70);
        //为了把事件穿透给label下面的botton里面
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);

        QSound *chooseSound = new QSound(":/res/TapButtonSound.wav");
        connect(choosebt,&MyPushBotton::clicked,[=]{
            if(pScene == NULL){
               chooseSound->play();
               this->hide();
               pScene = new PlayScene(i+1);
               pScene->setGeometry(this->geometry());
               pScene->show();
               connect(pScene,&PlayScene::chooseSceneBack,[=]{
                   this->setGeometry(pScene->geometry());
                   this->show();
                   delete pScene;
                   pScene = NULL;
               });
            }
        });
    }
    
}
void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
