#ifndef SSQUEUE_H
#define SSQUEUE_H

#include <QWidget>
#include <QMainWindow>
#include <QTableWidget>
//#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
namespace Ui {
class SSqueue;
}

class SSqueue : public QWidget
{
    Q_OBJECT

public:
    explicit SSqueue(QWidget *parent = nullptr);
    ~SSqueue();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_lcdNumber_overflow();

private:
    Ui::SSqueue *ui;
    int currentValue=0;  // Initialize to 0

    int totalDigitCount = 0; // Initialize to zero
};

#endif // SSQUEUE_H
