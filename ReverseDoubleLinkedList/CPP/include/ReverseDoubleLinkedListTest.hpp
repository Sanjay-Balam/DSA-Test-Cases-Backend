#ifndef REVERSEDOUBLYLINKEDLIST_TEST_HPP
#define REVERSEDOUBLYLINKEDLIST_TEST_HPP

#include<vector>
#include<string>
#include "json.hpp"


using json = nlohmann::json;


class ReverseDoublyLinkedlistTester{
public:
    bool test(json& input, json& output);
};

#endif