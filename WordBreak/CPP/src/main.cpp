#include "../include/WordBreakAlgorithm.hpp"
#include "../include/WordBreakAlgorithmTest.hpp"
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
    std::string inputString; // Change to store the input string
    std::vector<std::string> wordDict; // Change to store the vector of strings
    bool output; // Expected output
    bool result; // Result of the test case

    void to_json(json& j) {
        j = json{{"input", {inputString, wordDict}}, {"output", output}, {"result", result}}; // Serialize input as a pair
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
            testcase.inputString = j[i]["input"][0].get<std::string>(); // Get the input string
            testcase.wordDict = j[i]["input"][1].get<std::vector<std::string>>(); // Get the vector of strings
            testcase.output = j[i]["output"].get<bool>(); // Get expected output
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
    WordBreakAlgorithmTester tester; // Ensure this is the correct tester class
    std::vector<TestCase>& testcases = util.testcases;
    bool failed = false;
    for (TestCase& testcase : testcases) {
        // Call the test function with the input string and word dictionary
        bool result = tester.test(testcase.inputString, testcase.wordDict,testcase.output);
        testcase.result = result; // Store the result
        if (!result) {
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
