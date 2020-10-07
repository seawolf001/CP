
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        result.push_back(vector<int>{root->val});
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> nextLevel;
            int len = q.size();
            bool flag = false;
            while(len--) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left) {
                    nextLevel.push_back(front->left->val);
                    q.push(front->left);
                    flag = true;
                }
                if (front->right) {
                    nextLevel.push_back(front->right->val);
                    q.push(front->right);
                    flag = true;
                }
            }
            if (flag) {
                result.push_back(nextLevel);
            }
        }
        return result;
    }
};

