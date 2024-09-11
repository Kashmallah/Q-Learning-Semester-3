#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QWidget>
#include <QVector>
#include <QListWidget>
namespace Ui {
class Bubblesort;
}

class Bubblesort : public QWidget
{
    Q_OBJECT

public:
    explicit Bubblesort(QWidget *parent = nullptr);
    ~Bubblesort();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Bubblesort *ui;
    QVector<int> m_numbers;

    void bubbleSortStepByStep();
    void updateListWidget(QListWidget *listWidget, const QVector<int> &numbers);
    void setupListWidgets();
};

#endif // BUBBLESORT_H
