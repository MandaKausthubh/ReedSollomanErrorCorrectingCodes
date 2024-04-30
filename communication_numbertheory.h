#include "bigint.h"
#include <vector>

using bi = bigint;
template<class T> using vc = std::vector<T>;

#ifndef NUMBER_THEORY_CLASSES
#define NUMBER_THEORY_CLASSES

// Classes and Objects being used for Coding Theory and Communication Channel:
class TransmissionChannel {
    private:
        vc<bi> Message;
        float mu;
        bi MaxSizeOfMessage;
        bi MaxNumberOfErrors;
    public:
        bi ProductOfPrimes;
        vc<bi> primes;

        TransmissionChannel( bi MaxSizeOfMessage , float Corruption, bi LimitOfErrors);
        void TransmitSendMessage(vc<bi> MessageSent);
        vc<bi> TransmitRecieveMessage();
        bi MaxMessageSize();
        bi MaxSizeofErrors();
        bi MaxLPrimes();
};

class SolomonReeds {
    private:
    public:
        SolomonReeds();
        void SolomonReedsSend(bi Message, TransmissionChannel &Medium);
        bi SolomonReedRecieve(TransmissionChannel &Medium);
};

#endif
