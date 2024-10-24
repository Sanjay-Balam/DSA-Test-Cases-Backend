#include "../include/LCS.hpp"
#include "../include/LCSTest.hpp"
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
    std::string s1; // First input string
    std::string s2; // Second input string
    int output;     // Expected output (length of LCS)
    bool result;

    void to_json(json& j) {
        j = json{{"s1", s1}, {"s2", s2}, {"output", output}, {"result", result}}; // Serialize s1 and s2
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
            testcase.s1 = j[i]["s1"].get<std::string>(); // Read first string
            testcase.s2 = j[i]["s2"].get<std::string>(); // Read second string
            testcase.output = j[i]["output"].get<int>(); // Read expected output
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
    LCSTester tester; 
    std::vector<TestCase>& testcases = util.testcases;
    bool failed = false;
    for (TestCase& testcase : testcases) {
        bool result = tester.test(testcase.s1, testcase.s2, testcase.output); // Pass s1 and s2 to the test function
        testcase.result = result ? true : false;
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