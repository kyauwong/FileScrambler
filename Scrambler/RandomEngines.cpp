#include "RandomEngines.h"

using std::vector;
using std::string;
using std::mt19937_64;
using namespace RandomEngines;

SeedPack RandomEngines::StringToSeed(const string &pString)
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
