#ifndef LEARN_H
#define LEARN_H

#include <QWidget>
#include<QMainWindow>
#include <QMessageBox>
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTextStream>
#include <QBuffer>
#include <QProcess>
#include <QTimer>
#include <QThread>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QEvent>
#include <QWindowStateChangeEvent>

namespace Ui {
class Learn;
}

class Learn : public QWidget
{
    Q_OBJECT

public:
    explicit Learn(QWidget *parent = nullptr);
    ~Learn();
    bool eventFilter(QObject *obj, QEvent *event);
    void showMinimizedMessageBox();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_start_2_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();
private:
    Ui::Learn *ui;

};

#endif // LEARN_H
