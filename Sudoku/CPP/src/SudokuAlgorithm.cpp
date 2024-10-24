#include "../include/SudokuAlgorithm.hpp"
#define MAX 9999

// Function prototypes
bool solve(std::vector<std::vector<int>>& board);
bool isValid(const std::vector<std::vector<int>>& board, int row, int col, int num);

std::vector<std::vector<int>> SudokuAlgorithm::sudoku(std::vector<std::vector<int>>& board){
    if (solve(board)) {
        return board; 
    }
    return {{}}; 
}

bool solve(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {  // Empty cell
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // Place number
                        if (solve(board)) {
                            return true; // Return true if solved
                        }
                        board[row][col] = 0; // Undo if not solved
                    }
                }
                return false; // Return false if no number can be placed
            }
        }
    }
    return true; // Return true if the board is completely filled
}

bool isValid(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        // Check the row, column, and 3x3 grid
        if (board[row][i] == num || board[i][col] == num || 
            board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false; // Not valid if number is found
        }
    }
    return true; // Valid placement
}
