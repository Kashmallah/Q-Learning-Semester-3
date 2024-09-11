#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Test; }
QT_END_NAMESPACE

class Test : public QMainWindow
{
    Q_OBJECT

public:
    Test(QWidget *parent = nullptr);
    ~Test();
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
    Ui::Test *ui;
};
#endif // TEST_H
