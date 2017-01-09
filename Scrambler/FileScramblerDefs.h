#ifndef FILESCRAMBLERDEFS_H
#define FILESCRAMBLERDEFS_H

#include <climits>
#include <vector>

namespace FileScrambler {
typedef unsigned long long ULongLong;
typedef std::vector<ULongLong> SeedPack;
typedef std::vector<char> BinaryData;

const unsigned int mCharPerSeed = sizeof(ULongLong)/sizeof(char);
const unsigned int mCharBits = CHAR_BIT;
}

#endif // FILESCRAMBLERDEFS_H
