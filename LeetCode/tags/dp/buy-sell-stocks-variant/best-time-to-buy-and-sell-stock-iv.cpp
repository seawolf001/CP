#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int maxProfit(vector<int>& prices, int k=2) {
        int n = prices.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
        // dp[i][j]: max profit by making i trasactions upto jth day.
        for(int i=0;i<=k;i++) dp[i][0] = 0; // no profit on day-0
        for(int j=0;j<=n;j++)  dp[0][j] = 0; // zero trasactions
        for(int i=1; i<=k; i++) {
            for(int j=1; j<n; j++) {
                int maxx = INT_MIN;
                for(int m=0;m<j;m++) {
                    maxx = max(maxx, prices[j] - prices[m] + dp[i-1][m]);
                }
                dp[i][j] = max(dp[i][j-1], maxx);
            }
        }
        return dp[k][n-1];
    }
};


