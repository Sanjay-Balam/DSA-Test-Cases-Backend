#include "../include/PalindromicPartitionsAlgorithm.hpp"
#include "../include/PalindromicPartitionsAlgorithmTest.hpp"
#include <vector> 
#include <string> 


bool PalindromicPartitionsAlgoritmTester::test(std::string &s, std::vector<std::vector<std::string>>& output) {
    PalindromicPartitionsAlgorithm obj;
    std::vector<std::vector<std::string>> result = obj.palindrmicpartition(s);
    if(result.size()!=output.size()) return false;
    for(int i=0; i<result.size(); ++i) {
        std::vector<std::string> s1 = result[i];
        std::vector<std::string> s2 = output[i];

        if(s1.size() != s2.size()) {
            return false;
        }
        for(int j=0; j<s1.size(); ++j) {
            if(s1[j] != s2[j]){
                return false;
            }
        }
    }
    return true;
}
