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
    int diameter(TreeNode* node, int &h) {
        if(!node) return 0;
        int lh=0, rh=0, ld=0, rd=0;
        ld = diameter(node->left, lh), rd = diameter(node->right, rh);
        h = 1 + max(lh, rh);
        return max(1+lh+rh, max(ld, rd));
    }
public:
    int diameterOfBinaryTree(TreeNode* node) {
        int h=0; int nodes = diameter(node, h);
        return max(0, nodes-1); //  with n nodes, n-1 edges.
    }
};


