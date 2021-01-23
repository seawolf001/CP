#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int leftToRight=true;
        while(!q.empty()) {
            int n = q.size();
            vector<int> curr(n,0);
            for(int i=0;i<n;i++) {
                auto f = q.front(); q.pop();
                int idx = leftToRight ? i : n-i-1;
                curr[idx] = f->val;
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(curr);
        }
        return ans;
    }
};


