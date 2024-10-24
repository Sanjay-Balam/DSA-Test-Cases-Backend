#include "../include/WordBreakAlgorithm.hpp"
#include <unordered_set>
#define MAX 9999

bool WordBreakAlgorithm::solve(int idx, std::string &s, std::vector<int> &dp, std::unordered_set<std::string> &st) {
    if (idx >= s.size()) {
        return true; 
    }
    
    if (dp[idx] != -1) {
        return dp[idx];  
    }

    for (int l = 1; l <= s.size() - idx; ++l) {
        std::string temp = s.substr(idx, l);  
        if (st.find(temp) != st.end() && solve(idx + l, s, dp, st)) {
            return dp[idx] = true;  
        }
    }
    return dp[idx] = false;  
}

bool WordBreakAlgorithm::wordbreak(std::string &s, std::vector<std::string> &dictionary) {
    std::unordered_set<std::string> st(dictionary.begin(), dictionary.end());  
    std::vector<int> dp(s.size(), -1);  
    return solve(0, s, dp, st);  
}
