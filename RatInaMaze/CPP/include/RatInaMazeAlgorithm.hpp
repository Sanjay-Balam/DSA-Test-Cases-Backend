#ifndef RATINAMAZEALGORITHM_HPP
#define RATINAMAZEALGORITHM_HPP

#include <vector>
#include <string>

class RatInaMazeAlgorithm {
public:
    std::vector<std::string> Ratinamaze(std::vector<std::vector<int>>& board);
    void solve(int x, int y, std::vector<std::vector<int>>& mat, int n, std::vector<std::string>& ans, std::string move, std::vector<std::vector<int>>& vis, int Row[], int Col[]); 
};

#endif
