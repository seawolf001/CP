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
    void inorder(TreeNode* node, vector<int> &arr) {
        if(!node) return;
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vi arr; inorder(root, arr);
        int l=0, r=arr.size()-1, s=0;
        while(l<r) {
            s = arr[l]+arr[r];
            if(s==k) return true;
            else if(s>k) --r;
            else ++l;
        }
        return false;
    }
};


