#include "FileScrambler.h"
#include <fstream>
#include <iostream>
#include <cstdio>

using std::vector;
using std::string;
using std::mt19937_64;
using namespace FileScrambler;

SeedPack FileScrambler::StringToSeed(const string &pString)
{
    SeedPack result;
    for (size_t i=0;i<pString.size();++i) {
        if (i%mCharPerSeed == 0) result.emplace_back(0);

        result.back()<<=mCharBits;
        result.back()|=pString.at(i);
    }
    return result;
}

RandomFlipGenerator::RandomFlipGenerator(const SeedPack &pSeeds):
    mRandomGenerators(RandGenerators(pSeeds)),
    mDistribution(CHAR_MIN, CHAR_MAX)
{

}

char RandomFlipGenerator::GetByteFlip()
{
    char result = mDistribution(mRandomGenerators.at(mFence++));
    if (mFence == mRandomGenerators.size()) mFence = 0;
    return result;
}

auto RandomFlipGenerator::RandGenerators(const SeedPack &pSeeds)->RandGenPack
{
    RandGenPack result;
    for (const auto&i:pSeeds) result.emplace_back(i);
    return result;
}

void FileScrambler::FileScrambler(const std::string &pFilePath,
                                  RandomFlipGenerator &pRandomFlipGen)
{
    using namespace std;
    fstream file(pFilePath.data(), ios::in | ios::out | ios::binary | ios::ate);
    const auto end = file.tellg();
    file.seekg(0);
    const auto begin = file.tellg();
    const size_t nBytes = end-begin;

    std::vector<char> fileByte(nBytes);
    file.read(&fileByte[0], nBytes);
    file.seekp(0);
    for (unsigned int i = 0 ; i < nBytes; ++i) {
        fileByte[i] ^= pRandomFlipGen.GetByteFlip();
        file.write(&fileByte[i], 1);
    }
}

void FileScrambler::FileScrambler(const std::string &pFilePath,
                                  const std::string &pKeyword)
{
    const auto seeds = StringToSeed(pKeyword);
    RandomFlipGenerator generator(seeds);
    FileScrambler(pFilePath, generator);
}
