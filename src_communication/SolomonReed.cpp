#include "../communication_numbertheory.h"
#include "../math_NumberTheory.h"
#include <cstdlib>

// Constructor:
SolomonReeds::SolomonReeds() {
    MaxMessageSize = 100;        
}

// Sending a signal:
void SolomonReeds::SolomonReedsSend(bi Message, TransmissionChannel &Medium) {
    vc<bi> Transmited = {};
    for(bi p: Medium.primes) {
        Transmited.push_back(Message%p);
    }
    Medium.TransmitSendMessage(Transmited);
}

// Recieving a signal:
bi SolomonReeds::SolomonReedRecieve(TransmissionChannel &Medium) {
    // How does this work????
    vc<bi> MessageRecieved = Medium.TransmitRecieveMessage();

    // Reconstruction phase:
    // Step 1: Chinese Remainder Theorem:
    bi b = ChineseRemainder(Medium.primes, MessageRecieved);
    // Step 2: Recovering Message:
    bi M = Medium.MaxMessageSize();
    vc<bi> ResultRST = BinaryAdvancedEGCD(Medium.ProductOfPrimes,b,Medium.MaxLPrimes()*MaxMessageSize);
    if(ResultRST[0] < bi(0)) ResultRST[0] += Medium.ProductOfPrimes;
    if(ResultRST[0] % ResultRST[2] == bi(0)) {
        return ResultRST[0]/ResultRST[2];
    } else return bi(-1);
}

