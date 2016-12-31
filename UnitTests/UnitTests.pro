#-------------------------------------------------
#
# Project created by QtCreator 2016-12-18T10:24:13
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = TestAll
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    test_run.cpp \
    TestFileScrambler.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Scrambler/release/ -lScrambler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Scrambler/debug/ -lScrambler
else:unix: LIBS += -L$$OUT_PWD/../Scrambler/ -lScrambler

INCLUDEPATH += $$PWD/../Scrambler
DEPENDPATH += $$PWD/../Scrambler

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Scrambler/release/libScrambler.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Scrambler/debug/libScrambler.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Scrambler/release/Scrambler.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Scrambler/debug/Scrambler.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Scrambler/libScrambler.a

HEADERS += \
    TestCollector.h \
    fakeit.hpp \
    TestFileScrambler.h
