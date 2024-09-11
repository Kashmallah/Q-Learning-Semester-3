#include "sortvisualization.h"
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
#include<QAnimationGroup>
#include <QtGlobal>
#include<QAbstractAnimation>
SortVisualization::SortVisualization(QWidget *parent)
    : QMainWindow(parent) {
    // Initialize UI elements
    addArrayButton = new QPushButton("Add Array", this);
    addArrayButton->setStyleSheet("QPushButton { background-color: #008CBA; color: white; border-radius: 5px; padding: 5px; }"
                                  "QPushButton:hover { background-color: #006D9C; }"
                                  "QPushButton:pressed { background-color: #004C66; }");
    addArrayButton->setGeometry(10, 10, 100, 30);
    connect(addArrayButton, &QPushButton::clicked, this, &SortVisualization::addArray);

    removeArrayButton = new QPushButton("Remove Array", this);
    removeArrayButton->setStyleSheet("QPushButton { background-color: #008CBA; color: white; border-radius: 5px; padding: 5px; }"
                                     "QPushButton:hover { background-color: #006D9C; }"
                                     "QPushButton:pressed { background-color: #004C66; }");
    removeArrayButton->setGeometry(120, 10, 100, 30);
    connect(removeArrayButton, &QPushButton::clicked, this, &SortVisualization::removeArray);

    startSortingButton = new QPushButton("Start Sorting", this);
    startSortingButton->setStyleSheet("QPushButton { background-color: #008CBA; color: white; border-radius: 5px; padding: 5px; }"
                                      "QPushButton:hover { background-color: #006D9C; }"
                                      "QPushButton:pressed { background-color: #004C66; }");
    startSortingButton->setGeometry(10, 50, 100, 30);
    connect(startSortingButton, &QPushButton::clicked, this, &SortVisualization::startSorting);

    pauseSortingButton = new QPushButton("Pause Sorting", this);
    pauseSortingButton->setStyleSheet("QPushButton { background-color: #008CBA; color: white; border-radius: 5px; padding: 5px; }"
                                      "QPushButton:hover { background-color: #006D9C; }"
                                      "QPushButton:pressed { background-color: #004C66; }");
    pauseSortingButton->setGeometry(120, 50, 100, 30);
    connect(pauseSortingButton, &QPushButton::clicked, this, &SortVisualization::pauseSorting);

    stopSortingButton = new QPushButton("Stop Sorting", this);
    stopSortingButton->setStyleSheet("QPushButton { background-color: #008CBA; color: white; border-radius: 5px; padding: 5px; }"
                                     "QPushButton:hover { background-color: #006D9C; }"
                                     "QPushButton:pressed { background-color: #004C66; }");
    stopSortingButton->setGeometry(10, 90, 100, 30);
    connect(stopSortingButton, &QPushButton::clicked, this, &SortVisualization::stopSorting);

    speedSlider = new QSlider(Qt::Horizontal, this);
    speedSlider->setStyleSheet("QSlider { background-color: #008CBA; }"
                               "QSlider::handle { background-color: white; border-radius: 5px; }"
                               "QSlider::add-page { background-color: #006D9C; }"
                               "QSlider::sub-page { background-color: #004C66; }");
    speedSlider->setGeometry(10, 130, 100, 30);
    speedSlider->setRange(1, 100);
    speedSlider->setValue(50);
    connect(speedSlider, &QSlider::valueChanged, this, &SortVisualization::updateSpeed);
    speedLabel = new QLabel("Speed: 50%", this);
    speedLabel->setGeometry(10, 160, 100, 30);
    //animationGroup = new QAnimationGroup(this);
    animationroup->setLoopCount(-1);

    resize(300, 200);
}

void SortVisualization::addArray() {
    QVector<int> array(rand() % 50 + 50);
    for (int i = 0; i < array.size(); i++) {
        array[i] = rand() % 100 + 1;
    }
    arrays.append(array);
}

void SortVisualization::removeArray() {
    if (!arrays.isEmpty()) {
        arrays.removeLast();
    }
}

void SortVisualization::startSorting() {
    for (QVector<int> &array : arrays) {
        for (int i = 0; i < array.size(); i++) {
            QPropertyAnimation *animation = new QPropertyAnimation(this, QByteArray::number(i) + "value");
            animation->setDuration(speedSlider->value());
            animation->setStartValue(array[i]);
            animation->setEndValue(i);
            animation->setEasingCurve(QEasingCurve::OutQuad);
            animationroup->addAnimation(animation);
        }
    }
    animationroup->start();
}

void SortVisualization::pauseSorting() {
    animationroup->pause();
}

void SortVisualization::stopSorting() {
    animationroup->stop();
    for (QVector<int> &array : arrays) {
        array.clear();
    }
}

void SortVisualization::updateSpeed(int value) {
    speedLabel->setText(QString("Speed: %1%").arg(value));
    for (int i = 0; i < animationroup->animationCount(); ++i) {
        QAbstractAnimation *animation = animationroup->animationAt(i);
        if (QPropertyAnimation *propertyAnimation = qobject_cast<QPropertyAnimation *>(animation)) {
            propertyAnimation->setDuration(value);
        }
    }
}

void SortVisualization::painEvent() {
    QPainter painter(this);
    int yOffset = 0;
    for (QVector<int> &array : arrays) {
        for (int i = 0; i < array.size(); i++) {
            painter.fillRect(QRect(150 + i * 10, yOffset, 10, array[i]), QColor(255, 0, 0));
        }
        yOffset += 30;
    }
}

void SortVisualization::animate() {
    animationroup->start();
}

