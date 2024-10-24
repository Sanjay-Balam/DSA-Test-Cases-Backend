#ifndef NQUEENSALGORITHM_HPP
#define NQUEENSALGORITHM_HPP

#include<vector>
#include<string>

class NQueensAlgorithm{
public:
  std::vector<std::vector<int>> NQueens(int n); 
  bool isValid(std::vector<std::vector<int>>& board, int row, int col, int n); // Add declaration
  void solveNQueens(std::vector<std::vector<int>>& ans, std::vector<std::vector<int>>& board, 
                      std::vector<int>& curr, int n, int col); // Add declaration
};

#endif
