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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> vs;
        queue<pair<TreeNode*, string>> q;
        q.push(make_pair(root,to_string(root->val)));
        while(!q.empty()) {
            auto f = q.front(); q.pop();
            if(f.first->left==NULL && f.first->right==NULL) {
                vs.push_back(f.second);
            } else {
                if(f.first->left)
                    q.push(make_pair(f.first->left, f.second+"->"+to_string(f.first->left->val)));
                if(f.first->right)
                    q.push(make_pair(f.first->right, f.second+"->"+to_string(f.first->right->val)));
            }
        }
        return vs;
    }
};


