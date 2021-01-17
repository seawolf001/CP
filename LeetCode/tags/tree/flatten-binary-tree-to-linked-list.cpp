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
class Solution {
private:
    TreeNode* rightMost(TreeNode* node) {
        if(!node) return NULL;
        while(node->right) node = node->right;
        return node;
    }
    void transform(TreeNode* node) {
        if(!node) return;
        if(node->left) {
            TreeNode* right_most_in_left = rightMost(node->left);
            right_most_in_left->right = node->right;
            node->right = node->left;
        }
        node->left=NULL;
        transform(node->right);
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        transform(root);
    }
};


