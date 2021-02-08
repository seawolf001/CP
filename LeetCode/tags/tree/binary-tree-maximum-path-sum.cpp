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
    int postorder(TreeNode* node) {
        if(!node) return 0;
        int lsum = max(postorder(node->left), 0); // ignore if < 0
        int rsum = max(postorder(node->right), 0);// ignore if < 0
        res = max(res, lsum + rsum + node->val);
        return max({lsum + node->val, rsum + node->val});
    }
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        postorder(root);
        return res;
    }
};


