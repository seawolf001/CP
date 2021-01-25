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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, -1));
        while(!q.empty()) {
            int qs = q.size();
            int parent=INT_MIN;
            while(qs--) { // nodes of same level
                auto f = q.front(); q.pop();
                TreeNode* node = f.first;
                if(node->val==x || node->val==y) {
                    if(parent == INT_MIN) parent = f.second;
                    else return parent != f.second;
                }
                if(node->left) q.push(make_pair(node->left, node->val));
                if(node->right) q.push(make_pair(node->right, node->val));
            }
        }
        return false;
    }
};


