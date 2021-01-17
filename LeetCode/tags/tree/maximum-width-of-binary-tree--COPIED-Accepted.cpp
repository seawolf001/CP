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
public:
    int widthOfBinaryTree(TreeNode* root) {
		if(!root)
			return 0;
		queue<pair<TreeNode *, int>> que;
		que.push({root, 1});
		int res = 0;
		while(!que.empty()){
			int size = que.size();
			int offset = -1, r = -1;
			while(size--){
				auto cur = que.front().first;
				int index = que.front().second;
				que.pop();
				if(offset == -1){
					offset = index;//set offset of each level
				}
				index -= offset;//each index subtract the offset, fix the overflow.
				r = index;
				if(cur->left)
					que.push({cur->left, 2 * index});
				if(cur->right)
					que.push({cur->right, 2 * index + 1});
			}
			res = max(res, r+1);//l==0, length = r-l+1
		}
		return res;
	}
};
