#include "../include/PalindromicPartitionsAlgorithm.hpp"
#include <vector>
#include <string>

bool PalindromicPartitionsAlgorithm::isPalindrome(std::string &str, int start, int end) {
    while (start <= end) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}

void PalindromicPartitionsAlgorithm::solvePartitions(int index, std::string &s, std::vector<std::string> &path, std::vector<std::vector<std::string>> &result) {
    if (index >= s.size()) {
        result.push_back(path);
        return;
    }
    
    for (int i = index; i < s.size(); ++i) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            solvePartitions(i + 1, s, path, result);
            path.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> PalindromicPartitionsAlgorithm::palindrmicpartition(std::string s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> path;
    solvePartitions(0, s, path, result);
    return result;
}
