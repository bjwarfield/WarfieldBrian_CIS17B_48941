#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T23:17:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TetrisGroupProject
TEMPLATE = app


SOURCES += main.cpp \
    startwindow.cpp \
    tetrisboard.cpp \
    tetriswindow.cpp \
    tetrispiece.cpp \
    control.cpp

HEADERS  += \
    startwindow.h \
    tetrisboard.h \
    tetriswindow.h \
    tetrispiece.h \
    control.h

FORMS    +=

RESOURCES += \
    images.qrc
