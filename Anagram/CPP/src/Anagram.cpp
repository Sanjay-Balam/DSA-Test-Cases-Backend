#include "../include/Anagram.hpp"
#include<algorithm>
#include<unordered_map>

bool Anagram::isAnagram(std::string s1,std::string s2){
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