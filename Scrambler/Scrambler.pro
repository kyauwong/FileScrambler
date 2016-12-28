#-------------------------------------------------
#
# Project created by QtCreator 2016-12-18T10:25:32
#
#-------------------------------------------------

QT       -= core gui

TARGET = Scrambler
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    RandomEngines.cpp

HEADERS += \
    RandomEngines.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
