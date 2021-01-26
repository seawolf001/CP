#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

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
                if(dp[t]) return true;
            }
        }
        for(bool x:dp) cout << x << " ";
        return dp[t];
    }
};
