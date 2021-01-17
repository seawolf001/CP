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
    void inorder(TreeNode* node, long &sm) {
        if(!node) return;
        inorder(node->left, sm);
        sm += node->val;
        inorder(node->right, sm);
    }
    long postorder(TreeNode* node, const long &total, long &prod) {
        if(node==NULL) return 0;
        long l = postorder(node->left, total, prod),
             r = postorder(node->right, total, prod),
             val = node->val;
        prod = max(prod, max(l*(total-l), (total-r)*r));
        return val+l+r;
    }
public:
    int maxProduct(TreeNode* root) {
        long total=0, prod=LONG_MIN; inorder(root, total);
        postorder(root, total, prod);
        return prod % MOD;
    }
};


