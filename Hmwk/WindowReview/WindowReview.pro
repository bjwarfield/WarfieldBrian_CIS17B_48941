
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = WindoeReview
TEMPLATE = app
SOURCES += main.cpp \
    arrayclass.cpp \
    arraydialog.cpp
HEADERS += \
    arrayclass.h \
    arraydialog.h
FORMS += \
    arraydialog.ui
CONFIG  += c++11
