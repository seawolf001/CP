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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        queue<pair<TreeNode*, long>> q;
        q.push(make_pair(root, root->val));
        int cnt=0;
        unordered_set<TreeNode*> vis;
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            long curr = q.front().second;
            q.pop();
            if(curr==sum) ++cnt;
            if(node->left) {
                q.push(make_pair(node->left, curr + node->left->val));
                if(vis.find(node->left) == vis.end()) {
                    q.push(make_pair(node->left, node->left->val));
                    vis.insert(node->left);
                }
            }
            if(node->right) {
                q.push(make_pair(node->right, curr + node->right->val));
                if(vis.find(node->right) == vis.end()) {
                    q.push(make_pair(node->right, node->right->val));
                    vis.insert(node->right);
                }
            }
        }
        return cnt;
    }
};


