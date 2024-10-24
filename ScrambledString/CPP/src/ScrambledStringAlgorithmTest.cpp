#include "../include/ScrambledStringAlgorithm.hpp"
#include "../include/ScrambledStringAlgorithmTest.hpp"

bool ScrambledStringAlgorithmTester::test(std::vector<std::string> input,bool output){
  ScrambledStringAlgorithm obj;
  return output == obj.scrambledstring(input[0],input[1]);
}