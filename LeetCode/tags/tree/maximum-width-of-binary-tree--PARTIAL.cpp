// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define MOD 1000000007
// typedef vector<int> vi;
// typedef vector<vector<int>> vii;

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
    unordered_map<int, int> Left,Right;
    int MaxLevel=INT_MIN;
    void postorder(TreeNode* node, int d, int lvl) {
        if(!node) return;
        cout << lvl << " " << d << endl;
        postorder(node->left, d-1, lvl+1);
        postorder(node->right, d+1, lvl+1);
        MaxLevel = max(MaxLevel, lvl);
        Left[lvl] = min(Left[lvl], d);
        Right[lvl] = max(Right[lvl], d);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0; MaxLevel=INT_MIN;
        postorder(root,0,0);
        for(int i=0;i<=MaxLevel;i++) {
            int x=abs(Left[i]), y=abs(Right[i]), z=0;
            cout << "Level="<<i<<" left="<<Left[i]<< " right="<<Right[i]<<endl;
            z = (1<<x)/2 + (1<<y)/2;
            if(z>ans) ans=z;
        }
        return ans;
    }
};


