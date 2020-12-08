/* Jitendra Kumar */
//https://leetcode.com/problems/subsets/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    int N=0;
    vector<vector<int>> result;
    vector<int> st;
    void helper(vector<int>& nums, int idx) {
        result.push_back(st);
        if(idx >= N) return;
        for(int i=idx;i<N;i++) {
            st.push_back(nums[i]);
            helper(nums, i+1);
            st.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        if(N==0) return result;
        helper(nums, 0);
        return result;
    }
};

// int main() {
//     Solution s;
//     vector<int> v{1,2,3};
//     s.subsets(v);
//     return 0;
// }

