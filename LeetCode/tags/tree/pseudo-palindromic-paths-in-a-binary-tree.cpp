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
    void preorder(TreeNode* node, int * f, int &count) {
        if(!node) return;
        f[node->val]++;
        if(node->left==NULL && node->right==NULL) {
            int odds=0;
            for(int i=1;i<=9;i++)
                if(f[i]%2==1) ++odds;
            if(odds<=1) // to form a pelindrome, at most one element can have odd frequency.
                ++count;
        }
        if(node->left !=NULL) {
            preorder(node->left, f, count);
            --f[node->left->val];
        }
        if(node->right !=NULL) {
            preorder(node->right, f, count);
            --f[node->right->val];
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int f[10]={0}; int count=0;
        preorder(root, f, count);
        return count;
    }
};




