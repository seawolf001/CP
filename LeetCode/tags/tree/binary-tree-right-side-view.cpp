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
    void inorder(TreeNode* node, int level, map<int,int> &rightview) {
        if(node==NULL) return;
        inorder(node->left, level+1, rightview);
        rightview[level] = node->val;
        inorder(node->right, level+1, rightview);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> rightview;  vi ans;
        inorder(root, 0, rightview);
        for(auto &p:rightview) ans.push_back(p.second);
        return ans;
    }
};


