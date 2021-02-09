#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

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
    int res;
    int preorder(TreeNode* node) {
        if(!node) return 0;
        int l = preorder(node->left);
        int r = preorder(node->right);
        l = node->left && node->left->val == node->val ? 1 + l: 0;
        r = node->right && node->right->val == node->val ? 1 + r: 0;
        res = max(res, l+r); // number of edges
        return max(l,r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        preorder(root);
        return res;
    }
};


