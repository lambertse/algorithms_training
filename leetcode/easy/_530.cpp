//530. Minimum Absolute Difference in BST

#include "../component/tree_node.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    void DFS(TreeNode* root, int& minn){
        if(root->left){
            minn = min(root->val - root->left->val, minn);
            DFS(root->left, minn);
        }
        if(root->right){
            minn = min( root->right->val - root->val, minn);
            DFS(root->right, minn);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int ret = INT_MAX;
        DFS(root, ret);
        return ret;
    }
};