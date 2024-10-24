#ifndef KNIGHTWALKALGORITHM_HPP
#define KNIGHTWALKALGORITHM_HPP

#include <vector>
#include <string>

class KnightWalkAlgorithm {
public:
    int knightwalk(std::vector<int>& KnightPos, std::vector<int>& TargetPos, int n); // Ensure std:: is used
    bool isValid(int x, int y, int N);
};

#endif
