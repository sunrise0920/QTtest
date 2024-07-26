#-------------------------------------------------
#
# Project created by QtCreator 2024-06-21T17:32:36
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Last_0621
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbotton.cpp \
    chooselevelscene.cpp \
    playscene.cpp \
    mycoin.cpp \
    dataconfig.cpp

HEADERS  += mainscene.h \
    mypushbotton.h \
    chooselevelscene.h \
    playscene.h \
    mycoin.h \
    dataconfig.h

FORMS    += mainscene.ui

RESOURCES += \
    res.qrc

CONFIG += resources_big

CONFIG += c++11
