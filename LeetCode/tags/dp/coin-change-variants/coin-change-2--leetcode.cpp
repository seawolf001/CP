/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0) return 1;
        if(n==0) return 0;
        int dp[n+1][amount+1];

        for(int i=0;i<=n;i++) {
            for(int j=0;j<=amount;j++) {
                if(i==0 && j==0) dp[0][0]=1;
                else if(i==0) dp[0][j]=0;
                else if(j==0) dp[i][0]=1;
                else if(coins[i-1]<=j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]; // unbounded knapsack
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};

