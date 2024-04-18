//222. Count complete tree nodes
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
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int recur(TreeNode* root, int& cur){
        cur++;
        if(root->left) recur(root->left, cur);
        if(root->right) recur(root->right, cur);
    }
    int countNodes(TreeNode* root) {
        int res = 0;
        if(!root)
            return res;
        recur(root, res);
        return res;  
    }
};