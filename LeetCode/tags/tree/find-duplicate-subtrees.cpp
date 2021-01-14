
#include<bits/stdc++.h>
using namespace std;

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
    unordered_map<string, vector<TreeNode*>> tracker;
    string preorder(TreeNode* root) {
        if(root==NULL) return "";
        string hash = to_string(root->val) +
                      "(" + preorder(root->left) + ")" +
                      "(" + preorder(root->right) + ")";
        tracker[hash].push_back(root);
        return hash;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        vector<TreeNode*> ans;
        for(auto it=tracker.begin(); it!=tracker.end(); it++) {
            if(it->second.size()>1) ans.push_back(it->second[0]);
        }
        return ans;
    }
};

