#include "../math_NumberTheory.h"

// Inverse function returns the Multiplicative Inverse of x, with respect to mod n;
bi InverseOfNumber(bi x, bi n) {
    auto result = BinaryEGCD(x, n);
    bi a = result[0], b = result[1], gcd = result[3];
    if(gcd != bi(1)) return bi(-1);
    else return a;
}


// Chinese Remainder Theorem:
bi ChineseRemainder(vc<bi> ListOfCoPrimes, vc<bi> ListOfModuli) {
    bi N = 1, result = 0;
    for(auto x: ListOfCoPrimes) N *= x;
    for(int i = 0; i < ListOfCoPrimes.size(); i++) {
        bi Ni = N/ListOfCoPrimes[i];
        bi InverseOfNi = InverseOfNumber(Ni, ListOfCoPrimes[i]);
        result = (result + Ni*InverseOfNi*ListOfModuli[i]) % N;
    }
    return result;
}
