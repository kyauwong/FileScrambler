#ifndef TESTFILESCRAMBLER_H
#define TESTFILESCRAMBLER_H

#include <QtTest>
#include "TestCollector.h"
#include <string>

class TestFileScrambler : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void TestStringToSeed();
    void TestRandomFlipGenerator();
    void TestFileScramblerFunction();
    void TestFileScramblerIntegratedFunction();
    static std::string ReadFileFirstLine(const std::string& pFilePath);
};

ADD_TEST(TestFileScrambler)

#endif // TESTFILESCRAMBLER_H
