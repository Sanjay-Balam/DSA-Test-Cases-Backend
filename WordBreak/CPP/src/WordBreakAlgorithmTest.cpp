#include "../include/WordBreakAlgorithm.hpp"
#include "../include/WordBreakAlgorithmTest.hpp"

bool WordBreakAlgorithmTester::test(std::string &s, std::vector<std::string> &dictionary, bool output) {
    WordBreakAlgorithm obj;
    bool result = obj.wordbreak(s, dictionary);
    return result == output;
}
