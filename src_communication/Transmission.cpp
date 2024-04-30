
#include "../communication_numbertheory.h"
#include "../math_NumberTheory.h"
#include <cstdlib>
#include<algorithm>
#include<set>


// Constructor:
TransmissionChannel::TransmissionChannel(bi MaxSizeOfMessage , float Corruption, bi LimitOfErrors) {
    this->MaxSizeOfMessage = MaxSizeOfMessage;
    mu = Corruption;
    MaxNumberOfErrors = LimitOfErrors;
    Message = {};
    primes = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,71,73,79,83,87,91,97};
    ProductOfPrimes = 1;
    for(bi &x: primes) ProductOfPrimes *= x;
}

// Methods Provided by TransmissionChannel
bi TransmissionChannel::MaxMessageSize() {return bi(MaxSizeOfMessage);}
bi TransmissionChannel::MaxSizeofErrors() {return bi(MaxNumberOfErrors);}
bi TransmissionChannel::MaxLPrimes() {
    sort(primes.begin(), primes.end(), std::greater<>());
    bi Product = 1;
    std::vector<bi>::iterator iter = primes.begin();
    for(bi i = 0; i < MaxNumberOfErrors ; i++) {
        Product *= *iter; iter++;
    }
    return Product;
}

// Fuction to send through the TransmissionChannel
void TransmissionChannel::TransmitSendMessage(vc<bi> MessageSent) {
    Message = MessageSent;
}

        // Method to recieve any sent Message:
        //  With Errors.
vc<bi>TransmissionChannel:: TransmitRecieveMessage() {
    bi l = (bi) (rand() % ((int) (mu*primes.size())));
    std::set<bi> CorruptedIndexes;
    vc<bi> CorruptedMessage;

    for(int i = 0; i < l; i++) {
        bi j =  (bi) (rand() % ((int) (mu*primes.size())));
        while(CorruptedIndexes.find(j) != CorruptedIndexes.end()) {
            j =  (bi) (rand() % ((int) (primes.size())));
        }
        CorruptedIndexes.insert(j);
    }
    for(int i = 0; i < Message.size(); i++) {
        if(CorruptedIndexes.find(i) == CorruptedIndexes.end()) {
            CorruptedMessage.push_back(Message[i]);
        } else {
            bi random =  (bi) (rand() % (Message[i]));
            while(random == Message[i]) {random =  (bi) (rand() % (Message[i]));}
            CorruptedMessage.push_back(random);
        }
    }
    return CorruptedMessage;
}


