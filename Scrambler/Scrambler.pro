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
    FileScrambler.cpp \
    ProgressBarProcess.cpp \
    RandomFlipGenerator.cpp

HEADERS += \
    FileScrambler.h \
    ProgressBarProcess.h \
    RandomFlipGenerator.h \
    FileScramblerDefs.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
