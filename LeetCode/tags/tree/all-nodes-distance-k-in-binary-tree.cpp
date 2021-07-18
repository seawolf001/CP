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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int> dist;
    int findTarget(TreeNode* node, TreeNode* target) {
        if(!node) return -1;
        if(node == target)
            return dist[node] = 0;
        int d = findTarget(node->left, target);
        if(d != -1)
            return dist[node] = d + 1;
        d = findTarget(node->right, target);
        if(d != -1)
            return dist[node] = d + 1;
        return -1;
    }
    void dfs(TreeNode* node, int d, int K, vector<int> &ans) {
        if(!node) return;
        if(dist.find(node) != dist.end())
            d = dist[node];
        if(d == K) ans.push_back(node->val);
        dfs(node->left, d+1, K, ans);
        dfs(node->right, d+1, K, ans);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        if(!root) return ans;
        findTarget(root, target);
        dfs(root, dist[root], K, ans);
        return ans;
    }
};

