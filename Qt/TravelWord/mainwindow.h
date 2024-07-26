#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <widgettest.h>
#include <qdockwidget.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

    ~MainWindow();


    widgettest *my_widget;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
