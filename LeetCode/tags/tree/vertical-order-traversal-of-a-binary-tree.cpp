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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, vector<pair<int,int>>> tracker;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int l=0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto f = q.front(); q.pop();
                tracker[f.second].push_back(make_pair(f.first->val, l));
                if(f.first->left)
                    q.push(make_pair(f.first->left, f.second-1));
                if(f.first->right)
                    q.push(make_pair(f.first->right, f.second+1));
            }
            ++l;
        }
        vector<vector<int>> ans;
        for(auto &p: tracker) {
            sort(p.second.begin(), p.second.end(), [&](const pair<int,int> x, const pair<int,int> y){
                                                            if(x.second==y.second)
                                                                return x.first < y.first;
                                                            return x.second < y.second;
                                                    });
            vector<int> curr;
            for(auto &val:p.second) curr.push_back(val.first);
            ans.push_back(curr);
        }
        return ans;
    }
};


