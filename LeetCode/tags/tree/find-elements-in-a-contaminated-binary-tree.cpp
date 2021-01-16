#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
private:
    TreeNode* root;
public:
    FindElements(TreeNode* node) {
        root=node;
        root->val = 0;
        recover(root);
    }

    void recover(TreeNode* node) {
        if(node==NULL) return;
        int val = node->val;
        if(node->left != NULL) node->left->val = 2 * val + 1, recover(node->left);
        if(node->right != NULL) node->right->val = 2 * val + 2, recover(node->right);
    }
    bool find(int target) {
        return finder(target, root);
    }
    bool finder(int target, TreeNode* node=NULL) {
        if(node==NULL) return false;
        if(node->val == target) return true;
        return finder(target, node->left) || finder(target, node->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */


