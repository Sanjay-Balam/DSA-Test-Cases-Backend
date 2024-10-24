#include "../include/FindPossiblePaths.hpp"

void FindPossiblePathsSolver::solve(int i, int j, int n, int m, std::vector<int>& output, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& v) {

    if (i >= n || j >= m) {
        return;
    }

    output.push_back(grid[i][j]);


    if (i == n - 1 && j == m - 1) {
        v.push_back(output);
    } 
    else {
        solve(i + 1, j, n, m, output, grid, v);
        solve(i, j + 1, n, m, output, grid, v);
    }
    output.pop_back();
}

std::vector<std::vector<int>> FindPossiblePathsSolver::findpossiblepaths(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    std::vector<std::vector<int>> v;
    std::vector<int> output;
    solve(0, 0, n, m, output, grid, v);
    return v;
}
