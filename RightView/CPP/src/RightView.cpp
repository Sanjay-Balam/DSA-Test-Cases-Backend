#include "../include/RightView.hpp"
#include <queue>

std::vector<int> Rightview::rightview(TreeNode* root) {
    std::vector<int> v;
    std::queue<TreeNode*> q;
    
    if (root == nullptr) return v; 
    
    q.push(root);
    TreeNode* t = nullptr;
    
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            t = q.front(); 
            q.pop();
            
            if (t->left != nullptr) {
                q.push(t->left);
            }
            if (t->right != nullptr) {
                q.push(t->right);
            }
        }
        v.push_back(t->val);
    }
    
    return v;
}
