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
    bool subtreeExists=false;
    string preorder(TreeNode* node, string pre="") {
        if(node==NULL) return "$";
        string s = "(" + to_string(node->val) +
                    preorder(node->left, pre) +
                    preorder(node->right, pre) + ")";
        if(pre!="" && s==pre)
            subtreeExists=true;
        return s;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==t) return true;
        string pre=preorder(t); preorder(s, pre);
        return subtreeExists;
    }
};

