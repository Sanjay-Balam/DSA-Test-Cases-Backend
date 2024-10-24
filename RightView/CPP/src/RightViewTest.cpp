#include "../include/RightViewTest.hpp"
#include "../include/RightView.hpp"


#include<climits>

TreeNode* generateTree(std::vector<int>& arr,int i){
  if(i >= arr.size()) return nullptr;
  if(arr[i] == INT_MIN) return nullptr;
  TreeNode* root = new TreeNode(arr[i]);
  root->left = generateTree(arr,(2*i)+1);
  root->right = generateTree(arr,(2*i)+2);
  return root;
}

bool RightviewTester::test(std::vector<int>& input,std::vector<int>& output) {
    Rightview obj;
    TreeNode* root = generateTree(input,0);
    std::vector<int> result = obj.rightview(root);
    if(result.size()!=output.size()) return false;
    for(int i = 0; i< output.size() ; i++){
      if(output[i]!=result[i]) return false;
    }
    return true;
}
