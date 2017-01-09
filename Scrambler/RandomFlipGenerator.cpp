#include "RandomFlipGenerator.h"

using namespace FileScrambler;

MersenneRandFlipGen::MersenneRandFlipGen(const SeedPack &pSeeds):
    RandomFlipGenerator(),
    mRandomGenerators(RandGenerators(pSeeds)),
    mDistribution(CHAR_MIN, CHAR_MAX)
{

}

char MersenneRandFlipGen::GetByteFlip()
{
    char result = mDistribution(mRandomGenerators.at(mFence++));
    if (mFence == mRandomGenerators.size()) mFence = 0;
    return result;
}

auto MersenneRandFlipGen::RandGenerators(const SeedPack &pSeeds)->RandGenPack
{
    RandGenPack result;
    for (const auto&i:pSeeds) result.emplace_back(i);
    return result;
}
