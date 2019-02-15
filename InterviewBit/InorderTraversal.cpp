/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void util(TreeNode* root, vector<int> &v) {
    if(root->left) util(root->left, v);
    v.push_back(root->val);
    if(root->right) util(root->right, v);
}
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> v;
    util(root, v);
    return v;
}

