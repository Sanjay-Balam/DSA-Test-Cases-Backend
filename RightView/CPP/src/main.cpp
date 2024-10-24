#include "../include/RightView.hpp"
#include "../include/RightViewTest.hpp"
#include "../include/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include<climits>

using json = nlohmann::json;

class Config
{
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase
{
public:
    std::vector<int> input;
    std::vector<int> output;
    bool result;

    void to_json(json &j)
    {
        std::vector<json> inputJson;
        for(int& val:input){
            if(val == INT_MIN) inputJson.push_back(nullptr);
            else inputJson.push_back(val);
        }
        j = json{{"input", inputJson}, {"output", output}, {"result", result}};
    }
};

json serialize(std::vector<TestCase> testcases)
{
    json outputJson = json::array();
    for (TestCase testcase : testcases)
    {
        json j;
        testcase.to_json(j);
        outputJson.push_back(j);
    }
    return outputJson;
}

class Util
{
public:
    std::vector<TestCase> testcases;
    Config config;

    Util()
    {
        config = readConfig();
        testcases = readTestcases();
    }

    Config readConfig()
    {
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

    std::vector<TestCase> readTestcases()
    {
        std::ifstream testcaseFile;
        testcaseFile.open("../../" + config.testcasesFile);
        json j;
        testcaseFile >> j;
        testcaseFile.close();
        std::vector<TestCase> testcases;
        for (int i = 0; i < j.size(); i++)
        {
            TestCase testcase;
            for(const auto& val : j[i]["input"]){
                if(val.is_null())
                    testcase.input.push_back(INT_MIN);
                else 
                    testcase.input.push_back(val);
            }
            testcase.output = j[i]["output"].get<std::vector<int>>();
            testcases.push_back(testcase);
        }
        return testcases;
    }

    void writeResult()
    {
        std::ofstream resultFile;
        resultFile.open("../../" + config.CppResultFile);
        json j = serialize(testcases);
        resultFile << j.dump(2);
        resultFile.close();
    }
};

int main()
{
    try
    {
        Util util;
        RightviewTester tester;
        std::vector<TestCase> &testcases = util.testcases;
        bool failed = false;
        for (TestCase testcase : testcases)
        {
            bool result = tester.test(testcase.input,testcase.output);
            testcase.result = result ? true : false;
            if(!result){
                failed = true;
            }
        }
        util.writeResult();
        if (failed)
        {
            std::cout << "Some test cases failed" << std::endl;
            return 1;
        }
        std::cout << "All test cases passed" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
