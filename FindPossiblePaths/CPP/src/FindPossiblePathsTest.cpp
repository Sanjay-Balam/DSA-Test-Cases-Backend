#include "../include/FindPossiblePathsTest.hpp"
#include "../include/FindPossiblePaths.hpp"


bool FindPossiblePathsTester::test(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& output) {
    FindPossiblePaths obj;
  std::vector<std::vector<int>> result = obj.findpossiblepaths(input);
  if(result.size()!=output.size()) return false;
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result.size();j++){
      if(result[i][j] != output[i][j]) return false;
    }
  }

  return true;
}