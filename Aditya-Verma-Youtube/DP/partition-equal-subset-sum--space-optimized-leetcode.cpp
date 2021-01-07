/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return false;
        int S = accumulate(nums.begin(), nums.end(), 0);
        if(S&1) return false;
        int t = S/2;
        vector<bool> dp(t+1, false);
        dp[0]=true;
        for(int& num: nums) {
            for(int x=t; x>=num ;x--) {
                // dp[x] for not including `num`
                // dp[x-num] implies, num was included and hence target=(x-num)
                dp[x] = dp[x] || dp[x-num];
            }
        }
        return dp[t];
    }
};



