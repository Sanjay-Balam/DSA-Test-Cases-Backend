#include "../include/PowerOfNumber.hpp"
#include "../include/PowerOfNumberTest.hpp"

bool PowerOfNumberTester::test(int N, int R, long long output){
    PowerOfNumber obj;
    long long result = obj.powerofnumber(N,R);
    return result == output;
}