#ifndef SORTVISUALIZATION_H
#define SORTVISUALIZATION_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QComboBox>
#include <QVector>
#include <QPropertyAnimation>
#include <QVariantAnimation>
#include <QTimer>
#include <QWidget>
#include <QPainter>
#include <QAnimationDriver>
#include <QByteArray>
#include<QLabel>
class SortVisualization : public QMainWindow {
    Q_OBJECT

public:
    SortVisualization(QWidget *parent = nullptr);
    QAnimationGroup *animationroup;
     QLabel *speedLabel;
private slots:
    void addArray();
    void removeArray();
    void startSorting();
    void pauseSorting();
    void stopSorting();
    void updateSpeed(int value);

private:
    QPushButton *addArrayButton;
    QPushButton *removeArrayButton;
    QPushButton *startSortingButton;
    QPushButton *pauseSortingButton;
    QPushButton *stopSortingButton;
    QSlider *speedSlider;
    QLineEdit *arrayInput;
    QComboBox *algorithmComboBox;
    QWidget *canvas;
    QTimer *timer;
    QVector<QVector<int>> arrays;
    QVector<QPropertyAnimation*> animations;
    int arrayIndex;
    int algorithmIndex;
    bool isPaused;
    int animationIndex;
    int sortingTime;

    QVector<int> generateRandomArray(int size);
    QVector<QPropertyAnimation*> generateAnimations(QVector<int> &array);
    void swap(int &a, int &b);
    QVector<int> bubbleSort(QVector<int> array);
    void updateCanvas();
    void animate();
    void painEvent();
};

#endif // SORTVISUALIZATION_H
