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
    map<int, int> hash;
    int preorder(TreeNode* node) {
        if(node==NULL) return 0;
        int summ = node->val + preorder(node->left) + preorder(node->right);
        hash[summ]++;
        return summ;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        preorder(root);
        vector<int> ans; int f=INT_MIN;
        for(auto x:hash) f=max(f, x.second);
        for(auto x:hash) { if(x.second==f) ans.push_back(x.first); }
        return ans;
    }
};


