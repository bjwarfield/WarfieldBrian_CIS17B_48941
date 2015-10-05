#-------------------------------------------------
#
# Project created by QtCreator 2015-09-23T15:13:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polymorphism
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    virtual.cpp \
    base.cpp \
    derived.cpp

HEADERS  += mainwindow.h \
    virtual.h \
    base.h \
    derived.h

FORMS    += mainwindow.ui
