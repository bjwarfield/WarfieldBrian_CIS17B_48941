# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW_Qt-Windows
TARGET = Blocks
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += blocksboard.cpp blockspiece.cpp blockswindow.cpp main.cpp
HEADERS += blocksboard.h blockspiece.h blockswindow.h
FORMS += blockswindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW_Qt-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 