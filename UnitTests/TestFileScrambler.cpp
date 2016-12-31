#include "TestFileScrambler.h"
#include "../Scrambler/FileScrambler.h"
#include <iostream>
#include <fstream>

using namespace FileScrambler;

void TestFileScrambler::TestStringToSeed()
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

void TestFileScrambler::TestRandomFlipGenerator()
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

void TestFileScrambler::TestFileScramblerFunction()
{
    using namespace std;
    const string filename = "TempTestFile.txt";
    const string inputData = "FileScramblerTestDatatr";

    ofstream file(filename.data(), ios::trunc );
    file<<inputData;
    file.close();

    auto scrambleFile1 = [&](){
        FileScrambler::SeedPack seeds = {1,2};
        RandomFlipGenerator flipGen(seeds);
        FileScrambler::FileScrambler(filename, flipGen);
    };

    auto scrambleFile2 = [&](){
        FileScrambler::SeedPack seeds = {4};
        RandomFlipGenerator flipGen(seeds);
        FileScrambler::FileScrambler(filename, flipGen);
    };

    scrambleFile1();
    const auto scrambled1 = ReadFileFirstLine(filename);
    QVERIFY(inputData!=scrambled1);

    scrambleFile1();
    const auto unscrambled1 = ReadFileFirstLine(filename);
    QVERIFY(inputData==unscrambled1);

    scrambleFile2();
    const auto scrambled2 = ReadFileFirstLine(filename);
    QVERIFY(scrambled1!=scrambled2);

    scrambleFile2();
    const auto unscrambled2 = ReadFileFirstLine(filename);
    QVERIFY(unscrambled1==unscrambled2);

}

void TestFileScrambler::TestFileScramblerIntegratedFunction()
{
    using namespace std;
    const string filename = "TempTestFile.txt";
    const string inputData = "FileScramblerTestDatatr";
    const string password = "password";

    ofstream fileWriting(filename.data(), ios::trunc );
    fileWriting<<inputData;
    fileWriting.close();

    FileScrambler::FileScrambler(filename, password);
    QVERIFY(inputData!=ReadFileFirstLine(filename));

    FileScrambler::FileScrambler(filename, password);
    QVERIFY(inputData==ReadFileFirstLine(filename));
}

std::string TestFileScrambler::ReadFileFirstLine(const std::string &pFilePath)
{
    std::string result;
    std::ifstream file(pFilePath.data());
    file>>result;
    return result;
}
