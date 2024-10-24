#include "../include/ScrambledStringAlgorithm.hpp"
#include<algorithm>
#include<unordered_map>


bool ScrambledStringAlgorithm::solve(std::string s1, std::string s2, std::unordered_map<std::string, int>& memo) {

    if (s1 == s2) {
        return true;
    }


    if (s1.length() != s2.length()) {
        return false;
    }


    std::string key = s1 + "#" + s2;


    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    bool result = false;
    int n = s1.length();


    for (int i = 1; i < n; ++i) {

        bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i), memo) && 
            solve(s1.substr(i, n - i), s2.substr(0, n - i), memo);
        
        if (swapped) {
            return memo[key] = true;
        }


        bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i), memo) && 
                           solve(s1.substr(i, n - i), s2.substr(i, n - i), memo);
        
        if (not_swapped) {
            return memo[key] = true;
        }
    }


    return memo[key] = result;
}


bool ScrambledStringAlgorithm::scrambledstring(std::string s1, std::string s2) {
    std::unordered_map<std::string, int> memo;
    return solve(s1, s2, memo);
}
