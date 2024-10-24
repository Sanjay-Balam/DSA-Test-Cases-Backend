#ifndef PALINDROMICPARTITIONSALGORITHM_HPP
#define PALINDROMICPARTITIONSALGORITHM_HPP

#include <vector> 
#include <string> 

class PalindromicPartitionsAlgorithm {
public:
    std::vector<std::vector<std::string>> palindrmicpartition(std::string s);
    void solvePartitions(int index, std::string &s, std::vector<std::string> &path, std::vector<std::vector<std::string>> &result);
    bool isPalindrome(std::string &str, int start, int end);
};

#endif
