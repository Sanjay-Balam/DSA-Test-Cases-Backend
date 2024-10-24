#include "../include/SudokuAlgorithm.hpp"
#include "../include/SudokuAlgorithmTest.hpp"

bool SudokuAlgorithmTester::test(std::vector<std::vector<int>>& input,std::vector<std::vector<int>>& output){
  SudokuAlgorithm obj;
  std::vector<std::vector<int>> result = obj.sudoku(input);
  if(result.size()!=output.size()) return false;
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result.size();j++){
      if(result[i][j] != output[i][j]) return false;
    }
  }

  return true;
}