#include "../include/GenerateParanthesis.hpp"

void GenerateParanthesis::solve(int open, int close, std::vector<std::string>& ans, std::string s, int n) {

    if(s.length() == 2 * n) {
        ans.push_back(s);
        return;
    }
    if(open < n) {
        solve(open + 1, close, ans, s + "(", n);
    }
    if(close < open) {
        solve(open, close + 1, ans, s + ")", n);
    }
}

std::vector<std::string> GenerateParanthesis::generateparanthesis(int n) {
    int open = 0, close = 0;
    std::string s = "";
    std::vector<std::string> ans;
    solve(open, close, ans, s, n);
    return ans;
}
