#include "bigint.h"
#include "communication_numbertheory.h"
#include "math_NumberTheory.h"
#include <iostream>

int main(void) {
    
    bi MaxMessageSize = bi("999999999999999999999999");
    float RateOfCorruption = 0.01;

    SolomonReeds SolomonReedPoint;
    TransmissionChannel Medium = TransmissionChannel(MaxMessageSize, RateOfCorruption, bi("999999999999999999999"));
    SolomonReedPoint.SolomonReedsSend((bi)("23205349999999999"), Medium);
    std::cout << SolomonReedPoint.SolomonReedRecieve(Medium) << std::endl;
    return 0;
}
