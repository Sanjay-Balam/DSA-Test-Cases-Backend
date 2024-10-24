#include "../include/KnightWalkAlgorithm.hpp"
#include "../include/KnightWalkAlgorithmTest.hpp"
#include "../include/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using json = nlohmann::json;

class Config {
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase {
public:
    int N; // Board size
    std::vector<int> knightPos; // Knight's position
    std::vector<int> targetPos; // Target position
    int output; // Expected output
    bool result;

    void to_json(json& j) {
        j = json{{"N", N}, {"knightPos", knightPos}, {"targetPos", targetPos}, {"output", output}, {"result", result}};
    }
};

json serialize(std::vector<TestCase> testcases) {
    json outputJson = json::array();
    for (TestCase testcase : testcases) {
        json j;
        testcase.to_json(j);
        outputJson.push_back(j);
    }
    return outputJson;
}

class Util {
public:
    std::vector<TestCase> testcases;
    Config config;

    Util() {
        config = readConfig();
        testcases = readTestcases();
    }

    Config readConfig() {
        std::ifstream configFile;
        configFile.open("../../conf/config.json");
        json configJson;
        configFile >> configJson;
        configFile.close();
        Config config;
        config.testcasesFile = configJson["testcasesFile"];
        config.CppResultFile = configJson["CppResultFile"];
        return config;
    }

    std::vector<TestCase> readTestcases() {
        std::ifstream testcaseFile;
        testcaseFile.open("../../" + config.testcasesFile);
        json j;
        testcaseFile >> j;
        testcaseFile.close();
        std::vector<TestCase> testcases;
        for (int i = 0; i < j.size(); i++) {
            TestCase testcase;
            testcase.N = j[i]["N"].get<int>(); // Get board size
            testcase.knightPos = j[i]["knightPos"].get<std::vector<int>>(); // Get knight position
            testcase.targetPos = j[i]["targetPos"].get<std::vector<int>>(); // Get target position
            testcase.output = j[i]["output"].get<int>(); // Get expected output
            testcases.push_back(testcase);
        }
        return testcases;
    }

    void writeResult() {
        std::ofstream resultFile;
        resultFile.open("../../" + config.CppResultFile);
        json j = serialize(testcases);
        resultFile << j.dump(2);
        resultFile.close();
    }
};

int main() {
    Util util;
    KnightWalkAlgorithmTester tester; // Change to KnightWalkAlgorithmTester
    std::vector<TestCase>& testcases = util.testcases;
    bool failed = false;
    for (TestCase& testcase : testcases) {
        int result = tester.test(testcase.knightPos, testcase.targetPos, testcase.N,testcase.output); // Use knightPos, targetPos, and N
        testcase.result = (result == testcase.output); // Compare result with expectedOutput
        if (!testcase.result) {
            failed = true;
        }
    }
    util.writeResult();
    if (failed) {
        std::cout << "Some test cases failed" << std::endl;
        return 1;
    }
    std::cout << "All test cases passed" << std::endl;
    return 0;
}