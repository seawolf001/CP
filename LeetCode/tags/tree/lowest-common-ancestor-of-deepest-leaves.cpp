
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
private:
    unordered_map<TreeNode*, int> h;
    int process_heights(TreeNode* node) {
        if(node == NULL)
            return 0;
        return h[node] = 1 + max(process_heights(node->left), process_heights(node->right));
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        h.clear();
        process_heights(root);
        int lh=INT_MIN, rh=INT_MIN;
        while(root) {
            lh = root->left ? h[root->left] : INT_MIN;
            rh = root->right ? h[root->right] : INT_MIN;
            if((root->left == NULL && root->right == NULL) || (lh == rh))
                return root;
            root = lh > rh ? root->left : root->right;
        }
        return root;
    }
};






