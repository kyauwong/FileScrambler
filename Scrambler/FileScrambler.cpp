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

BinaryData ReadFileBytes::Read(const std::string &pPath)
{
    using namespace std;
    fstream file(pPath.data(), ios::in | ios::binary | ios::ate);
    if (!file.good()) throw std::runtime_error(pPath+" doesn't exist.");
    const auto end = file.tellg();
    file.seekg(0);
    const auto begin = file.tellg();
    const size_t nBytes = end-begin;
    SetTotalSteps(nBytes);

    BinaryData result(nBytes);
    for (size_t i = 0; i < nBytes; ++i) {
        file.read(&result[i], 1);
        AddOneCompletedStep();
    }
    return result;
}

void FlipBits::Encode(BinaryData &pData, RandomFlipGenerator &pRandFlipGen)
{
    SetTotalSteps(pData.size());
    for (auto &iByte: pData) {
        iByte^= pRandFlipGen.GetByteFlip();
        AddOneCompletedStep();
    }
}

void FileScrambler::ScrambleFile(const std::string &pFilePath,
                                  const std::string &pKeyword)
{
    const auto seeds = StringToSeed(pKeyword);
    auto data = ReadFileBytes().Read(pFilePath);
    auto randFlipGen = MersenneRandFlipGen(seeds);
    auto flipBitsAlgo = FlipBits();
    flipBitsAlgo.Encode(data, randFlipGen);
    WriteBytesToFile().Write(data, pFilePath);
}

void WriteBytesToFile::Write(BinaryData &pData, const std::string &pOutputFile)
{
    using namespace std;
    fstream file(pOutputFile.data(), ios::out | ios::binary | ios::trunc);
    SetTotalSteps(pData.size());
    for (auto &i: pData) {
        file.write(&i, 1);
        AddOneCompletedStep();
    }
}
