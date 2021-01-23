// Passing locally but TLE on leetcode submission
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        long ans=0;
        for(int i=0;i<n;i++) {
            dp[i][i]=arr[i];
            ans = (ans % MOD + dp[i][i]) % MOD;
        }
        for(int i=0;i<n-1;i++) {
            dp[i][i+1] = min(arr[i],arr[i+1]);
            ans = (ans % MOD + dp[i][i+1]) % MOD;
        }
        for(int k=3;k<=n;k++) {
            for(int i=0;i<n-k+1;i++) {
                int j = i+k-1;
                dp[i][j] = min(min(arr[i], arr[j]), dp[i+1][j-1]);
                ans = (ans % MOD + dp[i][j]) % MOD;
            }
        }
        return ans % MOD;
    }
};


