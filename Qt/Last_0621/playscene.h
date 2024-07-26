#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "mycoin.h"
#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = 0);
    PlayScene(int choosenum);
    void paintEvent(QPaintEvent *);
    int levalIndex;
    int gameArray[4][4];
    MyCoin *coinbtn[4][4];
    bool isWin = false;

signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
