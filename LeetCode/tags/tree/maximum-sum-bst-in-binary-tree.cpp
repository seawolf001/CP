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
    struct Info {
        int sum; // Sum till now of the present node value and it's left and right subtree
        int max; // Min value in subtree
        int min; // Max value in subtree
        int ans; // Sum of largest BST which which is a subtree of the present node
        bool isbst; // If subtree is BST
    };
    Info post_order(TreeNode* node, int &res) {
        if(node == NULL)
            return {0, INT_MIN, INT_MAX, 0, true};
        else if(node->left == NULL && node->right == NULL)
            return {node->val, node->val, node->val, node->val, true};

        Info l = post_order(node->left, res);
        Info r = post_order(node->right, res);

        Info ret;
        ret.sum = l.sum + r.sum + node->val;

        if(l.isbst && r.isbst && l.max < node->val && node->val < r.min) {
            ret.min = min({ l.min, node->val });
            ret.max = max({ r.max, node->val });
            ret.isbst = true;
            ret.ans = ret.sum;

            res = max(res, ret.ans);
            return ret;
        }
        ret.ans = max(l.ans, r.ans);
        ret.isbst = false;
        res = max(res, ret.ans);
        return ret;
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        post_order(root, res);
        return res;
    }
};




