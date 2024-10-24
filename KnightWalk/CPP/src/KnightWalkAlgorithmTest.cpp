#include "../include/KnightWalkAlgorithm.hpp"
#include "../include/KnightWalkAlgorithmTest.hpp"

bool KnightWalkAlgorithmTester::test(std::vector<int>& KnightPos, std::vector<int>& TargetPos, int n, int output) {
    KnightWalkAlgorithm obj;
    int result = obj.knightwalk(KnightPos, TargetPos, n);
    if (result != output) {
        return false;
    }
    return true;
}
