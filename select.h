#ifndef SELECT_H
#define SELECT_H
//#include<encry.h>
#include <QWidget>
#include"stack.h"
#include <QApplication>
#include"ssqueue.h"
// #includ"<sorting.h>
namespace Ui {
class Select;
}

class Select : public QWidget
{
    Q_OBJECT

public:
    explicit Select(QWidget *parent = nullptr);
    ~Select();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Select *ui;
    Stack s;
    //SortVisualization b;
   // Encry e;
    SSqueue ss;
    // sorting

};

#endif // SELECT_H
