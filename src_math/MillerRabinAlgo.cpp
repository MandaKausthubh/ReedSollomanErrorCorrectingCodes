#include "../math_NumberTheory.h"
#include <cstdlib>
#include <set>

bi PowerFunction(bi &a, bi &b) {
    if(b == bi(0)) return bi(1);
    else if(b == bi(1)) return a;
    else {
        bi half = b/ bi(2);
        bi halfPow = PowerFunction(a, half);
        if(b%bi(2) == bi(0)) return halfPow * halfPow;
        else return halfPow * halfPow * a;
    }
}

vc<bi> ValueOfTH(bi n) {
    bi t = n-bi(1);
    bi h = 1;
    while(t%bi(2) == bi(0)) {
        h *= 2; t /= 2;
    }
    return {t, h};
}

bool Conditional(bi a, bi t, bi h, bi n) {
    bi beta = PowerFunction(a, t);
    if(beta == bi(1)) return true;
    bi i = 0;    
    while(i < h) {
        if( beta == bi(-1) ) return true;
        if( beta == bi(1) ) return false;
        beta *= beta;
        i += 1;
    }
    return false;
}

void CreateWitnessSet(std::set<bi> &x, const bi &n) {
    // What the hell am I doing???? 
    // This is hell - AHHHHHHHH}!!!
    //
    bi Tvalue, HValue;
    vc<bi> Vals = ValueOfTH(n);
    Tvalue = Vals[0], HValue = Vals[1];
    for(bi i = 1; i < n; i++) {
        bi a = i, y = n-1;
        if(PowerFunction(a, y) % bi(n) == bi(1) && Conditional(i, Tvalue, HValue, n)) { x.insert(i); }
    }
}

bool MillerRabinAlgorithm(bi n) {
    bi i = 0; bi T = (long long)10e9 + 7;
    std::set<bi> WitnessSet; bi a;

    do { a = random() % n; i++; } while(i < T && WitnessSet.find(a) != WitnessSet.end());

    return (WitnessSet.find(a) != WitnessSet.end());
}
