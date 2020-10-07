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
private:
    unordered_map<int, int> indexes;
    TreeNode* buildTree_recurr(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) return nullptr;
        int curr = preorder[ps];
        TreeNode* node= new TreeNode(curr);
        if(ps == pe) return node;
        int idx = indexes[curr];
        int diff = idx - is;
        node->left = buildTree_recurr(preorder, inorder, ps+1, pe+diff, is, idx-1);
        node->right = buildTree_recurr(preorder, inorder, ps+1+diff, pe, idx+1, ie);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        if(n==0 || m==0) return nullptr;
        this->indexes.clear();
        for(int i=0;i<m;i++) { indexes[inorder[i]]=i; }
        return buildTree_recurr(preorder, inorder, 0, n-1, 0, m-1);
    }
};



