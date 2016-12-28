#include "RandomEngines.h"

using std::vector;
using std::string;

RandomEngines::SeedPack RandomEngines::StringToSeed(const string &pString)
{
    SeedPack result;
    for (size_t i=0;i<pString.size();++i) {
        if (i%mCharPerSeed == 0) result.emplace_back(0);

        result.back()<<=mCharBits;
        result.back()|=pString.at(i);
    }
    return result;
}

vector<std::mt19937_64> RandomEngines::GetGenerators(const SeedPack& pSeeds)
{
//    const size_t discardSize= 1000;
//    vector<std::mt19937_64> result;
//    result.reserve(pSeeds.size());
//    for (unsigned int i = 0; i < pSeeds.size();++i) {
//        result.emplace_back(pSeeds.at(i));
//        result.at(i).discard(i*discardSize);
//    }
    return {};
}
