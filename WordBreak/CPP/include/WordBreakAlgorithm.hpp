#ifndef WORDBREAKALGORITHM_HPP
#define WORDBREAKALGORITHM_HPP

#include<vector>
#include<string>
#include <unordered_set>

class WordBreakAlgorithm{
public:
  bool wordbreak(std::string &s, std::vector<std::string>&dictionary);
  bool solve(int idx, std::string &s, std::vector<int>&dp, std::unordered_set<std::string>&st);
};

#endif