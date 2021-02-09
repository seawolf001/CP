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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int ans=0, l=0;
        while(!q.empty()) {
            int qs = q.size();
            auto f = q.front(); q.pop();
            int curr = 10 * f.second + f.first->val;
            if(f.first->left)
                q.push(make_pair(f.first->left, curr));
            if(f.first->right)
                q.push(make_pair(f.first->right, curr));
            if (f.first->left==NULL && f.first->right==NULL)
                ans += curr;
        }
        return ans;
    }
};


