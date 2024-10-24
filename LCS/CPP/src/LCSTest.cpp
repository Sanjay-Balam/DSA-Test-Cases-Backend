#include "../include/LCSTest.hpp"
#include "../include/LCS.hpp"
#include <string> 

bool LCSTester::test(std::string s1, std::string s2, int output) {
    LCS obj; 
    int result = obj.lcs(s1, s2); 

    return result == output; 
}
