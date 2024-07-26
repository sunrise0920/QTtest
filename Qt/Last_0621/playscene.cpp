#include "playscene.h"
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QSound>
#include <QPropertyAnimation>
#include "mycoin.h"
#include "mypushbotton.h"
#include "dataconfig.h"
PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}

PlayScene::PlayScene(int choosenum){
    levalIndex = choosenum;
    this->setFixedSize(320,588);
    this->setWindowTitle("翻金币");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    QMenuBar *bar = new QMenuBar;
    this->setMenuBar(bar);
    QMenu *startmenu = bar->addMenu("开始");
    QAction *start_quit = startmenu->addAction("退出");
    connect(start_quit,&QAction::triggered,[=]{
        this->close();
    });
    MyPushBotton *back = new MyPushBotton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    back->setParent(this);
    back->move(this->width()-back->width(),this->height()-back->height());
    QSound *backSound = new QSound(":/res/BackButtonSound.wav");
    connect(back,&MyPushBotton::clicked,[=]{
        backSound->play();
        QTimer::singleShot(500,this,[=]{
            this->hide();
            emit this->chooseSceneBack();
        });
    });
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setBold(true);
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Level:%1").arg(this->levalIndex);
    label->setText(str);
    label->setGeometry(QRect(30,this->height()-50,120,50));

    QLabel *winlabel = new QLabel;
    QPixmap winpix;
    winpix.load(":/res/LevelCompletedDialogBg.png");
    winlabel->setGeometry(0,0,winpix.width(),winpix.height());
    winlabel->setParent(this);
    winlabel->setPixmap(winpix);
    winlabel->move((this->width()-winpix.width())*0.5, -winpix.height());
    dataConfig config;
    QSound *FCoinSound = new QSound(":/res/ConFlipSound.wav");
    QSound *WinSound = new QSound(":/res/LevelWinSound.wav");
    //创建金币的背景图片
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            QLabel *backlabel = new QLabel;
            backlabel->setGeometry(0,0,50,50);
            backlabel->setPixmap(QPixmap(":/res/BoardNode.png"));
            backlabel->setParent(this);
            backlabel->move(57 + i*50,200+j*50);
            gameArray[i][j] = config.mData[this->levalIndex][i][j];
            QString img;
            if (gameArray[i][j] == 1){
               img = ":/res/Coin0001.png";
            }
            else{
               img = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];

            coinbtn[i][j]= coin;
            connect(coin,&MyCoin::clicked,[=]{
                FCoinSound->play();
                coin->changeFlag();
                gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0;
                QTimer::singleShot(300,this,[=]{
                    if (coin->posX+1 <= 3){
                        coinbtn[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] = gameArray[i][j] == 0 ? 1 : 0;
                    }
                    if (coin->posX-1 >= 0){
                        coinbtn[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] = gameArray[i][j] == 0 ? 1 : 0;
                    }
                    if (coin->posY+1 <= 3){
                        coinbtn[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] = gameArray[i][j] == 0 ? 1 : 0;
                    }
                    if (coin->posY-1 >= 0){
                        coinbtn[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] = gameArray[i][j] == 0 ? 1 : 0;
                    }
                    this->isWin = true;
                    for(int i = 0; i < 4; i++){
                        for(int j = 0; j < 4; j++){
                            if (coinbtn[i][j]->flag == false){
                                this->isWin = false;
                                break;
                            }

                        }
                    }
                    if (this->isWin){
                        qDebug()<<"Win!!";
                        WinSound->play();
                        QPropertyAnimation  *animation = new QPropertyAnimation(winlabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winlabel->x(),winlabel->y(),winlabel->width(),winlabel->height()));
                        animation->setEndValue(QRect(winlabel->x(),winlabel->y()+200,winlabel->width(),winlabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                        for(int i = 0 ; i < 4;i++)
                              {
                                for(int j = 0 ; j < 4; j++)
                                {
                                  coinbtn[i][j]->isWin = true;
                                }
                        }
                    }
                });

            });

        }
    }

}

void PlayScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
