#ifndef SCRAMBLENDSTRINGALGORITHM_HPP
#define SCRAMBLENDSTRINGALGORITHM_HPP

#include <vector>
#include <string>
#include <unordered_map> // Include this for unordered_map

class ScrambledStringAlgorithm {
public:
    bool scrambledstring(std::string s1, std::string s2);

    bool solve(std::string s1, std::string s2, std::unordered_map<std::string, int>& memo);
};

#endif
