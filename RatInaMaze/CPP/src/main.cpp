#include "../include/RatInaMazeAlgorithm.hpp"
#include "../include/RatInaMazeAlgorithmTest.hpp"
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
    std::vector<std::vector<int>> input;
    std::vector<std::string> output;
    bool result;

    void to_json(json& j) {
        j = json{{"input", input}, {"output", output}, {"result", result}};
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
        if (!configFile.is_open()) {
            throw std::runtime_error("Could not open config file.");
        }
        
        json configJson;
        configFile >> configJson;
        if (configJson.is_null()) {
            throw std::runtime_error("Config file is empty or invalid.");
        }
        
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
            testcase.input = j[i]["input"].get<std::vector<std::vector<int>>>();
            testcase.output = j[i]["output"].get<std::vector<std::string>>();
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
    RatInaMazeAlgorithmTester tester;
    std::vector<TestCase>& testcases = util.testcases;
    bool failed = false;
    for(TestCase& testcase:testcases){
        bool result = tester.test(testcase.input,testcase.output);
        testcase.result = result ? true : false;
        if(!result){
            failed = true;
        }
    }
    util.writeResult();
    if (failed) {
        std::cout<<"Some test cases failed"<<std::endl;
        return 1;
    }
    std::cout << "All test cases passed" << std::endl;
    return 0;
}
