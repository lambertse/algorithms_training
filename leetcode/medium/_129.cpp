//129. Sum Root to Leaf Numbers
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recur(TreeNode* cur, int& res, int tmp){
    tmp=tmp*10+cur->val;
    if(!(cur->left || cur->right)) res += tmp;
    if(cur->left) recur(cur->left, res,tmp);
    if(cur->right) recur(cur->right, res,tmp);
}
int sumNumbers(TreeNode* root) {
    int res = 0;
    int tmp = 0;
    recur(root, res, tmp);
    return res;
}

int main(){
    TreeNode* r = new TreeNode(1);
    TreeNode* l = new TreeNode(0);
    r->left = l;
    std::cout << sumNumbers(r);
}