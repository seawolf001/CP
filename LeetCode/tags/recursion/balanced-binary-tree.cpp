
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
    bool balanced(TreeNode* node, int &h) {
        if(!node) { h=0; return true; }
        int lh = 0, rh=0;
        bool lb = balanced(node->left, lh);
        bool rb = balanced(node->right, rh);
        h = 1 + max(lh, rh);
        if(abs(lh-rh)>1) return false;
        return lb && rb;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int h=0;
        return balanced(root, h);
    }
};
