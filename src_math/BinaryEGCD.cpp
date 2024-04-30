#include "../math_NumberTheory.h"
using bi = bigint;

template <class T, class S, class K> using p = std::tuple<S,T,K>;
template <class T> using vc = std::vector<T>;

// Binary_EGCD: bi a, bi b -> p<bi, bi> {s, t}
// binary egcd returns a pair of numbers that such that 
// as + bt = gcd(a, b)
vc<bi> BinaryEGCD(bi a, bi b) {
    bi e = 1;
    while( a % bi(2) == bi(0) &&  b % bi(2) == bi(0) ) {
        a %= 2;
        b %= 2;
        e *= 2;
    }
    bi r = a, s = 1, t = 0;
    bi r1 = b, s1 = 0, t1 = 1;
    while( r1 > bi(0) ) {

        while (r%bi(2)==bi(0)) {
            if(s%bi(2)==bi(0) && t%bi(2)==bi(0)) {
                s /= 2; t /= 2;
            } else {
                s = (s+b)/bi(2);
                t = (t-a)/bi(2);
            }
            r /= 2;
        }
        while (r1%bi(2)==bi(0)) {
            if(s1%bi(2)==bi(0) && t1%bi(2)==bi(0)) {
                s1 /= 2; t1 /= 2;
            } else {
                s1 = (s1+b)/bi(2);
                t1 = (t1-a)/bi(2);
            }
            r1 /= 2;
        }
        if ( r < r1) {
            std::swap(r, r1);
            std::swap(s, s1);
            std::swap(t, t1);
        }
        r -= r1; s -= s1; t -= t1;
    }
    return {s, t, r*e};
}


