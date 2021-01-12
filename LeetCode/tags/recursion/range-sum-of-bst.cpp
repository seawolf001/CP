
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
private:
    void helper(TreeNode* root, int l, int h, long& s) {
        if(l <= root->val && root->val <= h) s+=root->val;
        if (root->left) helper(root->left,l,h,s);
        if(root->right) helper(root->right, l,h,s);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        long ans=0;
        helper(root, low, high, ans);
        return ans;
    }
};


