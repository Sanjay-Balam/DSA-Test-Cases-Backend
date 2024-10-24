#include "../include/Anagram.hpp"
#include "../include/AnagramTest.hpp"

bool AnagramTester::test(std::vector<std::string> input,bool output){
  Anagram obj;
  return output == obj.isAnagram(input[0],input[1]);
}