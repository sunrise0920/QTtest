#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QpaintEvent>
namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MainScene();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
