#ifndef TESTRANDOMENGINES_H
#define TESTRANDOMENGINES_H

#include <QtTest>
#include "TestCollector.h"

class TestRandomEngines : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void TestStringToSeed();
    void TestRandomFlipGenerator();
};

ADD_TEST(TestRandomEngines)

#endif // TESTRANDOMENGINES_H
