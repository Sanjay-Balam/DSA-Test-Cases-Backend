#ifndef SUDOKUALGORITHM_HPP
#define SUDOKUALGORITHM_HPP

#include<vector>
#include<string>

class SudokuAlgorithm{
public:
  std::vector<std::vector<int>> sudoku(std::vector<std::vector<int>>& board);
};

#endif