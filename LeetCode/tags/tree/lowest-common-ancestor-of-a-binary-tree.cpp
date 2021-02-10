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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    /*Solution becomes smaller because
     * 1. Given both the values exists in the tree.
     * 2. All the values are unique.
     * */
    TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node)
            return NULL;
        else if(node->val == p->val || node->val == q->val)
            return node;
        TreeNode* l1 = LCA(node->left, p, q);
        TreeNode* l2 = LCA(node->right, p, q);
        if(l1 && l2)
            return node; // 1-1 in each side.
        return l1 != NULL ? l1 : l2;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p,q);
    }
};


