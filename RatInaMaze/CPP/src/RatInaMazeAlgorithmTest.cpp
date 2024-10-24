#include "../include/RatInaMazeAlgorithm.hpp"
#include "../include/RatInaMazeAlgorithmTest.hpp"

bool RatInaMazeAlgorithmTester::test(std::vector<std::vector<int>>& board, std::vector<std::string>& output) {
    RatInaMazeAlgorithm obj;
    std::vector<std::string> result = obj.Ratinamaze(board);
    if (output.size() != result.size()) {
        return false;
    }
    int n = result.size();
    for (int i = 0; i < n; ++i) {
        std::string string1 = result[i];
        std::string string2 = output[i];
        if (string1 != string2) {
            return false;
        }
    }

    return true;
}
