#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T13:41:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScramblerGUI
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    License.cpp \
    About.cpp \
    Encoding.cpp

HEADERS  += MainWindow.h \
    License.h \
    About.h \
    Encoding.h

FORMS    += MainWindow.ui \
    License.ui \
    About.ui \
    Encoding.ui

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
