/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int D) {
        int n = nums.size();
        if(n==0) return 0;
        int S = accumulate(nums.begin(), nums.end(), 0);
        if(D>S) return 0;
        if((S+D) & 1) return 0;
        int T = (S+D)/2;
        // count subsets whose sum is (S+D)/2 == T
        vector<long> dp(T+1, 0);
        dp[0] = 1;
        for(int &x: nums) {
            for(int t=T; t>=x; t--) {
                dp[t] += dp[t-x];
            }
        }
        return dp[T];
    }
};

