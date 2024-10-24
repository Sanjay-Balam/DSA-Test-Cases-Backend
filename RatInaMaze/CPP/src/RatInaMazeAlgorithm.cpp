#include "../include/RatInaMazeAlgorithm.hpp"
#include <iostream>

#define MAX 9999

void RatInaMazeAlgorithm::solve(int x, int y, std::vector<std::vector<int>>& mat, int n, std::vector<std::string>& ans, std::string move, std::vector<std::vector<int>>& vis, int Row[], int Col[]) {
    // Check if the destination is reached
    if (x == n - 1 && y == n - 1) {
        ans.push_back(move);
        return;
    }

    // Possible moves: Up, Left, Right, Down
    std::string str = "ULRD";
    for (int i = 0; i < 4; ++i) {
        int newx = x + Row[i];
        int newy = y + Col[i];

        // Check for valid moves
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && !vis[newx][newy] && mat[newx][newy] == 1) {
            vis[x][y] = 1; // Mark current cell as visited
            solve(newx, newy, mat, n, ans, move + str[i], vis, Row, Col);
            vis[x][y] = 0; // Backtrack
        }
    }
}

std::vector<std::string> RatInaMazeAlgorithm::Ratinamaze(std::vector<std::vector<int>>& board) {
    std::vector<std::string> ans;
    int n = board.size();
    std::vector<std::vector<int>> vis(n, std::vector<int>(n, 0)); // Visited array
    int Row[] = {-1, 0, 0, 1}; // Direction vectors for rows
    int Col[] = {0, -1, 1, 0}; // Direction vectors for columns

    // Start solving from the top-left corner if it's valid
    if (board[0][0] == 1) {
        solve(0, 0, board, n, ans, "", vis, Row, Col);
    }

    return ans; // Return all possible paths
}
