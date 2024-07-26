#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H
#include "playscene.h"
#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    PlayScene *pScene = NULL;
signals:
    void chooseSceneBack();
public slots:
};

#endif // CHOOSELEVELSCENE_H
