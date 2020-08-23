
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j] &&
                    dp[j]>dp[i]) {
                    dp[i]=dp[j];
                }
            }
            dp[i]++;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

