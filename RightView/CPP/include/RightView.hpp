#ifndef RIGHTVIEW_HPP
#define RIGHTVIEW_HPP

#include<vector>
#include<string>



class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class Rightview{
public:
  std::vector<int> rightview(TreeNode* root);
};

#endif