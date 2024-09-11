#ifndef TESTR_H
#define TESTR_H

#include <QWidget>
#include<QtNetwork/qnetworkreply.h>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QtNetwork>
#include<QtGui>
#include<QtCore>
#include <QtNetwork/QNetworkAccessManager>
namespace Ui {
class Testr;
}

class Testr : public QWidget
{
    Q_OBJECT

public:
    explicit Testr(QWidget *parent = nullptr);
    ~Testr();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_stack_clicked();

    void on_pushButton_queue_clicked();

    void on_pushButton_linklist_clicked();

    void on_pushButton_trees_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_diff_level_2_activated(int index);

private:
    Ui::Testr *ui;
};

#endif // TESTR_H
