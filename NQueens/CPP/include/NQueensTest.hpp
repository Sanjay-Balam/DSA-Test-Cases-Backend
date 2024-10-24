#ifndef NQUEENS_TEST_HPP
#define NQUEENS_TEST_HPP

#include <vector>

class NQueensTester {
public:
    bool test(std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& expectedSolution);
};

#endif