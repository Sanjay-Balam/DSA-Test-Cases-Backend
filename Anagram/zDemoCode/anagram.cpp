#include<iostream>
#include<string>
#include<unordered_map>

bool isAnagram(std::string s1,std::string s2){
  std::unordered_map<char,int> map;
  for(char ch:s1){
    map[ch]++;
  }
  for(char ch:s2){
    if(map.find(ch)==map.end()) return false;
    map[ch]--;
  }

  for(std::pair<char,int> item:map){
    if(item.second != 0) return false;
  }
  return true;
}


void printAnagramResult(bool val){
  if(val) std::cout << "Anagrams" << std::endl;
  else std::cout << "Not anagrams" << std::endl;
}

int main(){
  std::string s1 = "fried";
  std::string s2 = "fired";

  printAnagramResult(isAnagram(s1,s2));

  s1 = "asdb";
  s2 = "silent";
  printAnagramResult(isAnagram(s1,s2));
  
  return 0;
}