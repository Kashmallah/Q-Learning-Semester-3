#ifndef STACK_H
#define STACK_H
#include<QListView>
#include<QStringListModel>
#include <QWidget>

namespace Ui {
class Stack;
}

class Stack : public QWidget
{
    Q_OBJECT

public:
    explicit Stack(QWidget *parent = nullptr);
    ~Stack();

private slots:
    void on_pushButton_clicked();
    void pushItem();
    void on_pushButton_2_clicked();
    void popItem();

private:
    Ui::Stack *ui;
};

#endif // STACK_H
