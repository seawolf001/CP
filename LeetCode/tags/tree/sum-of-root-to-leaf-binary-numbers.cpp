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
    int preorder(TreeNode* node, int summ) {
        if(!node) return 0;
        summ =  ((summ << 1) + node->val) % MOD;
        if(node->left==NULL && node->right==NULL)
            return summ;
        return ( preorder(node->left, summ) % MOD +
                 preorder(node->right, summ) % MOD
               ) % MOD;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int summ = preorder(root, 0);
        return summ;
    }
};


