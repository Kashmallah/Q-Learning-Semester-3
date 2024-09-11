#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<select.h>
#include <QMainWindow>
//#include"learn.h"
//#include"testr.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    //Select t;
   //PRACTICE y;
   //Learn l;
    Select s;
};
#endif // MAINWINDOW_H
