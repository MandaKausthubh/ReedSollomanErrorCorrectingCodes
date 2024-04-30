#include "../math_NumberTheory.h"
using bi = bigint;

template <class T, class S, class K> using p = std::tuple<S,T,K>;
template <class T> using vc = std::vector<T>;

// Binary_EGCD: bi a, bi b -> p<bi, bi> {s, t}
// binary egcd returns a pair of numbers that such that 
// as + bt = gcd(a, b)
vc<bi> BinaryAdvancedEGCD(bi a, bi b, bi r_max) {
    
    bi r = a, s = 1, t = 0;
    bi r1 = b, s1 = 0, t1 = 1;

    if(r <= r_max) return {r,s,t};
    if(r1 <= r_max) return {r1,s1,t1};

    while(r1 != bi(0)) {
        bi r_t = r1, s_t = s1, t_t = t1;
        r1 = r % r1;
        s1 = s % s1;
        t1 = t % t1;

        r = r_t, s = s_t, t = t_t;
        if(r1 <= r_max) return {r1,s1,t1};
    }

    return {r,s,t};
}


