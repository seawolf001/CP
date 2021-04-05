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
    int maxLevelSum(TreeNode* root) {
        if(!root)  return 0;
        int ans=1, maxs=root->val, l=1;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            int qs = q.size();
            int curr = 0;
            while(qs--) {
                TreeNode* f = q.front(); q.pop();
                curr += f->val;
                if(f->left)  q.push(f->left);
                if(f->right) q.push(f->right);
            }
            if(curr > maxs) maxs = curr, ans = l;
            ++l;
        }
        return ans;
    }
};


