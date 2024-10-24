#ifndef FINDPOSSIBLEPATHS_HPP
#define FINDPOSSIBLEPATHS_HPP

#include <vector>

class FindPossiblePaths {
public:
    std::vector<std::vector<int>> findpossiblepaths(std::vector<std::vector<int>>& grid);
    void solve(int i, int j, int n, int m, std::vector<int>& output, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& v);
};

#endif