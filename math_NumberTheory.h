#include "bigint.h"
#include <vector>

using bi = bigint;
template<class T> using vc = std::vector<T>;

#ifndef NUMBER_THEORY_FUNCTIONS
#define NUMBER_THEORY_FUNCTIONS

// Number Theoretic Funcions being used:
vc<bi> BinaryEGCD(bi a, bi b);
bi ChineseRemainder(vc<bi> ListOfCoPrimes, vc<bi> ListOfModuli);
vc<bi> BinaryAdvancedEGCD(bi a, bi b, bi r_max);
bool MillerRabinAlgorithm(bi n); 

#endif
