#include <QString>
#include <QtTest>
#include "../Scrambler/RandomEngines.h"

using namespace RandomEngines;

class ScramblerTest : public QObject
{
    Q_OBJECT

public:
    ScramblerTest() = default;

private Q_SLOTS:
    void TestStringToSeed();
    void TestRandomFlipGenerator();
};

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

void ScramblerTest::TestRandomFlipGenerator()
{
    SeedPack seeds = {1,2,3,4,5};
    const auto nSeeds = seeds.size();
    auto generator = RandomFlipGenerator(seeds);
    std::vector<std::mt19937_64> generators;
    generators.reserve(nSeeds);
    for (size_t i = 0 ; i < nSeeds;++i) {
        generators.emplace_back(seeds.at(i));
    }

    std::uniform_int_distribution<short> distribution(CHAR_MIN, CHAR_MAX);
    std::vector<char> expect;
    const size_t nExpect = nSeeds*10;
    expect.reserve(nExpect);
    for (size_t i = 0 ; i < nExpect; ++i) {
        const short randomValue = distribution(generators.at(i%nSeeds));
        expect.emplace_back(char(randomValue));
    }

    for (const auto &i:expect){
        QCOMPARE(generator.GetByteFlip(), i);
    }
}

QTEST_APPLESS_MAIN(ScramblerTest)

#include "TestRandomEngines.moc"
