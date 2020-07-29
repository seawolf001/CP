/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


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
public:
    bool isValidBST(TreeNode* root) {
        return __isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool __isValidBST(TreeNode* root, long MIN, long MAX) {
        if (!root) return true;
        if (MIN >= root->val || MAX <= root->val) return false;
        return __isValidBST(root->left, MIN, root->val) &&
                __isValidBST(root->right, root->val, MAX);
    }
};
