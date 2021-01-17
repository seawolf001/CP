#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    void dfs(vi &nums, vi &curr, set<vi> &ans, int idx, int n) {
        if(idx >= n) {
            if (curr.size() >= 2)
                ans.insert(curr);
            return;
        }
        if(curr.size()==0 || curr.back() <= nums[idx]) {
            curr.push_back(nums[idx]); // Include
            dfs(nums, curr, ans, idx+1, n);
            curr.pop_back(); // backtrack
        }
        dfs(nums, curr, ans, idx+1, n); // Exclude
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vi> ans; int n = nums.size(); vi curr;
        dfs(nums, curr, ans, 0, n);
        return vii(ans.begin(), ans.end());
    }
};


