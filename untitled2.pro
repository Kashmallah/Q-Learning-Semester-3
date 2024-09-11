QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    bubblesort.cpp \
    learn.cpp \
    main.cpp \
    select.cpp \
    ssqueue.cpp \
    stack.cpp

HEADERS += \
    MainWindow.h \
    bubblesort.h \
    learn.h \
    select.h \
    ssqueue.h \
    stack.h

FORMS += \
    MainWindow.ui \
    bubblesort.ui \
    learn.ui \
    select.ui \
    ssqueue.ui \
    stack.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
