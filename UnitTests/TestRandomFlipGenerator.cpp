#include "TestRandomFlipGenerator.h"
#include "../Scrambler/RandomFlipGenerator.h"

void TestRandomFlipGenerator::TestMersenneRandFlipGen()
{
    FileScrambler::SeedPack seeds = {1,2,3,4,5};
    const auto nSeeds = seeds.size();
    auto generator = FileScrambler::MersenneRandFlipGen(seeds);
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
