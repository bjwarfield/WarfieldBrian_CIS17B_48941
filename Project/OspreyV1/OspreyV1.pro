#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T09:46:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OspreyV1
TEMPLATE = app


SOURCES += main.cpp \
    gamewidget.cpp \
    window.cpp \
    sprite.cpp \
    playerentity.cpp \
    entity.cpp \
    shotentity.cpp

HEADERS  += \
    gamewidget.h \
    window.h \
    entity.h \
    sprite.h \
    playerentity.h \
    shotentity.h

RESOURCES += \
    resources.qrc


