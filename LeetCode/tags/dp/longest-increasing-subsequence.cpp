
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
        int dp[n]; for(int i=0;i<n;i++) dp[i]=1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i] && dp[j]+1>dp[i]) {
                    dp[i]=1+dp[j];
                }
            }
        }
        int L=INT_MIN;
        for(int i=0;i<n;i++) L = max(L,dp[i]);
        return L;
    }
};



