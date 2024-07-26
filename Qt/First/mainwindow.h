#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "teacheer.h"
#include "stu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Classover();
    void Classover02();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Teacheer *tea;
    Stu *stu;

};

#endif // MAINWINDOW_H
