#ifndef FILESCRAMBLER_H
#define FILESCRAMBLER_H

#include <string>
#include <vector>
#include <climits>
#include <random>

namespace FileScrambler
{
typedef unsigned long long ULong64;
typedef std::vector<ULong64> SeedPack;

const unsigned int mCharPerSeed = sizeof(ULong64)/sizeof(char);
const unsigned int mCharBits = CHAR_BIT;

SeedPack StringToSeed(const std::string& pString);

class RandomFlipGenerator {
public:
    RandomFlipGenerator(const SeedPack& pSeeds);
    char GetByteFlip();
private:
    typedef std::vector<std::mt19937_64> RandGenPack;

    RandGenPack mRandomGenerators;
    size_t mFence = 0;

    std::uniform_int_distribution<int> mDistribution;

    RandGenPack RandGenerators(const SeedPack& pSeeds);
};

void FileScrambler(const std::string& pFilePath,
                   RandomFlipGenerator& pRandomFlipGen);

void FileScrambler(const std::string& pFilePath,
                   const std::string& pKeyword);
};

#endif // FILESCRAMBLER_H
