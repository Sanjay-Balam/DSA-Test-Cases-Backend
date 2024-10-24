#include "../include/GenerateParanthesis.hpp"
#include "../include/GenerateParanthesisTest.hpp"

bool GenerateParanthesisTester::test(int n, std::vector<std::string>& output) {
    GenerateParanthesis obj;
    std::vector<std::string> result = obj.generateparanthesis(n);
    if(result.size() != output.size()) {
        return false;
    }
    for(int i=0; i<result.size(); ++i) {
        if(result[i] != output[i]) {
            return false;
        }
    }
    return true;
}


