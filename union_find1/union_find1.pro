#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T14:12:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = union_find1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    maze.cpp

HEADERS += \
        mainwindow.h \
    union_find.h \
    maze.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pointer/1.png \
    pointer/1.png \
    pointer/2.png \
    pointer/3.png \
    pointer/4.png \
    pointer/5.png \
    pointer/6.png \
    pointer/7.png \
    pointer/8.png \
    pointer/9.png \
    pointer/10.png \
    pointer/11.png \
    pointer/12.png \
    pointer/13.png \
    pointer/14.png \
    pointer/15.png

RESOURCES += \
    r.qrc
