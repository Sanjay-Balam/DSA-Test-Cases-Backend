#include "../include/NQueensAlgorithmTest.hpp"
#include "../include/NQueensAlgorithm.hpp"

bool NQueensAlgorithmTester::test(int input, std::vector<std::vector<int>>& output) {
    NQueensAlgorithm obj;
    std::vector<std::vector<int>> result = obj.NQueens(input);
    if(result.size()!=output.size()) return false;
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
        if(result[i][j] != output[i][j]) return false;
        }
    }

  return true;
}