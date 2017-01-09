#ifndef TESTPROGRESSBARPROCESS_H
#define TESTPROGRESSBARPROCESS_H

#include <QtTest>
#include "TestCollector.h"


class TestProgressBarProcess: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void TestInterface();
};

ADD_TEST(TestProgressBarProcess)

#endif // TESTPROGRESSBARPROCESS_H
