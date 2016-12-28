#include <QString>
#include <QtTest>
#include "../Scrambler/RandomEngines.h"
#include <iostream>

using namespace RandomEngines;

class ScramblerTest : public QObject
{
    Q_OBJECT

public:
    ScramblerTest();

private Q_SLOTS:
    void TestStringToSeed();
    void TestGetGenerators();
};

ScramblerTest::ScramblerTest()
{
}

void ScramblerTest::TestStringToSeed()
{
    std::vector<ULong64> expect;
    QCOMPARE(StringToSeed(""), expect);

    expect={0x41};
    QCOMPARE(StringToSeed("A"), expect);

    expect={0x6A};
    QCOMPARE(StringToSeed("j"), expect);

    expect={0x7465737463617365};
    QCOMPARE(StringToSeed("testcase"), expect);

    expect={0x7465737463617365, 0x414243};
    QCOMPARE(StringToSeed("testcaseABC"), expect);
}

void ScramblerTest::TestGetGenerators()
{

}

QTEST_APPLESS_MAIN(ScramblerTest)

#include "TestRandomEngines.moc"
