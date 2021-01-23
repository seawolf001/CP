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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        queue<pair<TreeNode*, pair<vector<int>,int>>> q;
        q.push({root, {{root->val}, root->val}});
        vector<vector<int>> ans;
        while(!q.empty()) {
            auto f=q.front(); q.pop();
            TreeNode* node=f.first;
            if(node->left==NULL && node->right==NULL) {
                if(f.second.second==targetSum)
                    ans.push_back(f.second.first);
            } else {
                if(node->left) {
                    vector<int> l(f.second.first.begin(), f.second.first.end());
                    l.push_back(node->left->val);
                    q.push(make_pair(
                            node->left,
                            make_pair(
                                l,
                                f.second.second + node->left->val
                            )
                        )
                    );
                }
                if(node->right) {
                    vector<int> r(f.second.first.begin(), f.second.first.end());
                    r.push_back(node->right->val);
                    q.push(make_pair(
                            node->right,
                            make_pair(
                                r,
                                f.second.second + node->right->val
                            )
                        )
                    );
                }
            }
        }
        return ans;
    }
};

