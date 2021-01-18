#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

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
    int maxf=INT_MIN;
    typedef unordered_map<int, int> ump;
    void preorder(TreeNode* node, ump &mp) {
        if(!node) return;
        mp[node->val]++;
        maxf = max(maxf, mp[node->val]);
        preorder(node->left, mp);
        preorder(node->right, mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        ump mp; vi ans; maxf=INT_MIN;
        preorder(root, mp);
        for(auto &p: mp) if(p.second==maxf) ans.push_back(p.first);
        return ans;
    }
};


