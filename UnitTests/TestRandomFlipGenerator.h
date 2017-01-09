#ifndef TESTRANDOMFLIPGENERATOR_H
#define TESTRANDOMFLIPGENERATOR_H

#include <QtTest>
#include "TestCollector.h"


class TestRandomFlipGenerator: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void TestMersenneRandFlipGen();
};

ADD_TEST(TestRandomFlipGenerator)

#endif // TESTRANDOMFLIPGENERATOR_H
