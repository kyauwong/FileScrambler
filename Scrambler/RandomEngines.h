#ifndef SCRAMBLER_H
#define SCRAMBLER_H

#include <string>
#include <vector>
#include <climits>
#include <random>

namespace RandomEngines
{
typedef unsigned long long ULong64;
typedef std::vector<ULong64> SeedPack;
std::vector<std::mt19937_64> GetGenerators(const SeedPack& pSeeds);

const unsigned int mCharPerSeed = sizeof(ULong64)/sizeof(char);
const unsigned int mCharBits = CHAR_BIT;

SeedPack StringToSeed(const std::string& pString);

};

#endif // SCRAMBLER_H
