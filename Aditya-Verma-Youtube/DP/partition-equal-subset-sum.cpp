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
        int _sum = accumulate(nums.begin(), nums.end(), 0);
        if(_sum % 2 != 0) return false;
        int t = _sum/2;
        // dp[i][j] represents solution for i elements [0...i-1] and j weight
        bool dp[n+1][t+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=t;j++) {
                if(i==0 && j==0)
                    dp[i][j] = true;
                else if(i==0) {
                    dp[0][j]=false;
                } else if(j==0) {
                    dp[i][0]=true;
                } else {
                    if(nums[i-1]<=j) {
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][t];
    }
};

