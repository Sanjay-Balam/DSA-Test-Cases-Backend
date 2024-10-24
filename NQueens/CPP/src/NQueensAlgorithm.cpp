#include "../include/NQueensAlgorithm.hpp"

// Helper function to check if placing a queen is valid
bool NQueensAlgorithm::isValid(std::vector<std::vector<int>>& board, int row, int col, int n) {
    // Check left side of the current row
    for (int i = col; i >= 0; i--) {
        if (board[row][i] == 1) return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Recursive function to solve N-Queens problem
void NQueensAlgorithm::solveNQueens(std::vector<std::vector<int>>& ans, std::vector<std::vector<int>>& board, 
                                     std::vector<int>& curr, int n, int col) {
    if (col >= n) {
        ans.push_back(curr); // Store the solution
        return;
    }

    // Try placing a queen in all rows of the current column
    for (int row = 0; row < n; row++) {
        if (isValid(board, row, col, n)) {
            board[row][col] = 1;
            curr.push_back(row + 1);  // Store the row number in the solution

            // Recur to place the rest of the queens
            solveNQueens(ans, board, curr, n, col + 1);

            // Backtrack and remove the queen from the current position
            curr.pop_back();
            board[row][col] = 0;
        }
    }
}

// Main function to find all solutions to the N-Queens problem
std::vector<std::vector<int>> NQueensAlgorithm::NQueens(int n) {
    std::vector<std::vector<int>> ans;
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));  // Initialize the board
    std::vector<int> curr;  // Store current solution

    // Start solving from the first column
    solveNQueens(ans, board, curr, n, 0);

    return ans;
}
