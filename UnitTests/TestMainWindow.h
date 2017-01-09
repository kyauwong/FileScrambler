#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QtTest>
#include "TestCollector.h"

class TestMainWindow: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void TestKeyword();
};

ADD_TEST(TestMainWindow)

#endif // TESTMAINWINDOW_H
