#include "../include/PowerOfNumber.hpp"
#define MOD 1000000007

long long PowerOfNumber::powerofnumber(int N, int R) {
    // Base case
    if (R == 0) {
        return 1;
    }
    

    long long res = powerofnumber(N, R / 2);
    

    if (R & 1) {
        return ((N * res) % MOD * res) % MOD;
    }
    
    return (res * res) % MOD;
}
