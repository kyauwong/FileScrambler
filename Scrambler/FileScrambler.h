#ifndef FILESCRAMBLER_H
#define FILESCRAMBLER_H

#include <string>
#include <vector>
#include <random>
#include "ProgressBarProcess.h"
#include "FileScramblerDefs.h"
#include "RandomFlipGenerator.h"

namespace FileScrambler
{

SeedPack StringToSeed(const std::string& pString);

void ScrambleFile(const std::string& pFilePath,
                   const std::string& pKeyword);


class ReadFileBytes: public ProgressBarProcess {
public:
    BinaryData Read(const std::string& pPath);
};

class WriteBytesToFile: public ProgressBarProcess {
public:
    void Write(BinaryData& pData, const std::string& pOutputFile);
};

class FlipBits: public ProgressBarProcess {
public:
    void Encode(BinaryData& pData, RandomFlipGenerator& pRandFlipGen);
};

} //End namespace FileScrambler

#endif // FILESCRAMBLER_H
