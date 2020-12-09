
/* Jitendra Kumar */
//https://leetcode.com/problems/subsets-ii/
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
        if(idx>=N) {
            result.push_back(st);
            // for(int x:st) cout << x << " "; cout << endl;
            return;
        }
        // Include ith element
        st.push_back(nums[idx]);
        helper(nums, idx+1);

        st.pop_back(); // backtrack

        // Discard identical elements
        while(idx<N-1 && nums[idx]==nums[idx+1]) idx++;
        helper(nums, idx+1); // Exclude ith element.
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)  {
        N = nums.size();
        if(N==0) return result;
        sort(nums.begin(), nums.end());
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


