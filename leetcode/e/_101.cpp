//101. Symmetric tree
#include <iostream>
#include <vector>
using namespace std;

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
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool recur(TreeNode* l, TreeNode* r){
        if(!l) return !r;
        if(!r) return !l;
        if(l->val != r->val)
            return false;
        return recur(l->left,r->right) && recur(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) { 
        if(!root)
            return true;
        return recur(root->left, root->right);
    }
};