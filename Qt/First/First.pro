#-------------------------------------------------
#
# Project created by QtCreator 2024-05-21T10:14:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = First
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    teacheer.cpp \
    stu.cpp

HEADERS  += mainwindow.h \
    teacheer.h \
    stu.h

FORMS    += mainwindow.ui

CONFIG += c++11
