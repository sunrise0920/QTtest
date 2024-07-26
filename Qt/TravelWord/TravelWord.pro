#-------------------------------------------------
#
# Project created by QtCreator 2024-06-05T10:29:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TravelWord
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    widgettest.cpp

HEADERS  += mainwindow.h \
    widget.h \
    widgettest.h

FORMS    += mainwindow.ui \
    widgettest.ui

RESOURCES += \
    res.qrc
