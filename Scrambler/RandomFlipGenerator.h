#ifndef RANDOMFLIPGENERATOR_H
#define RANDOMFLIPGENERATOR_H

#include "FileScramblerDefs.h"
#include <random>

namespace FileScrambler {
class RandomFlipGenerator
{
public:
    RandomFlipGenerator() = default;
    virtual ~RandomFlipGenerator() = default;
    virtual char GetByteFlip() = 0;
};

class MersenneRandFlipGen: public RandomFlipGenerator {
public:
    MersenneRandFlipGen(const SeedPack& pSeeds);
    char GetByteFlip() override;
private:
    typedef std::vector<std::mt19937_64> RandGenPack;

    RandGenPack mRandomGenerators;
    size_t mFence = 0;

    std::uniform_int_distribution<int> mDistribution;

    RandGenPack RandGenerators(const SeedPack& pSeeds);
};
}
#endif // RANDOMFLIPGENERATOR_H
