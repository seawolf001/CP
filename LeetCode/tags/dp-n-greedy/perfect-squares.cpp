#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int numSquares(int n) {
        vector<long> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j*j<=i;j++) {
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};


