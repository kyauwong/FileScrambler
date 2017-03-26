#include "TestFileScrambler.h"
#include "../Scrambler/FileScrambler.h"
#include <iostream>
#include <fstream>

using namespace FileScrambler;

void TestFileScrambler::TestStringToSeed()
{
    std::vector<ULongLong> expect;
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

void TestFileScrambler::TestReadFileBytes()
{
    auto test = FileScrambler::ReadFileBytes();
    const std::string filename = "TestBytes.txt";
    {//Creating file
        std::ofstream file(filename.data(), std::ios::trunc);
        file<<"Test";
    }
    const auto result = test.Read(filename);
    std::vector<char> expect = {'T', 'e', 's', 't'};
    QVERIFY(4==test.GetTotalSteps());
    QVERIFY(4==test.GetCompletedSteps());
    QCOMPARE(result, expect);
}

class MockRandomFlipGenerator: public RandomFlipGenerator {
public:
    char GetByteFlip() override {
        return mValue++;
    }
    char mValue = 1;
    void Reset() {
        mValue = 1;
    }
};

void TestFileScrambler::TestFlipBits()
{
    std::vector<char> data = {'a', 'b', 'c', 'd'};
    std::vector<char> expect = data;

    FlipBits test;
    MockRandomFlipGenerator mockFlipper;
    test.Encode(data, mockFlipper);
    QVERIFY(data!=expect);

    mockFlipper.Reset();
    test.Encode(data, mockFlipper);
    QVERIFY(data==expect);
}
