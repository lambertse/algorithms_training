//112. Path Sum
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    int curSum = 0;
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        curSum+=root->val;
        if(!root->left && !root->right)
            return curSum == targetSum;
        if(root->left){
            if(hasPathSum(root->left, targetSum))
                return true;
            curSum-=root->left->val;
        }
        if(root->right){
            if(hasPathSum(root->right, targetSum))
                return true;
            curSum-=root->right->val;
        }
        return false;
    }    
};