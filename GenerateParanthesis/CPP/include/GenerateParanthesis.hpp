#ifndef GENERATEPARANTHESIS_HPP
#define GENERATEPARANTHESIS_HPP

#include <vector> 
#include <string> 

class GenerateParanthesis {
public:
    std::vector<std::string> generateparanthesis(int n);
    void solve(int open, int close, std::vector<std::string>& ans, std::string s, int n);
};

#endif
