
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

// NOT WORKING. ERROR: AddressSanitizer: allocator is out of memory trying to allocate 0x1dcd65008 bytes

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (!n || !K)
            return 0;
        int **dp = new int*[K+1];
        for(int i=0;i<=K;i++)
            dp[i] = new int[n+1]();
        for(int i=0;i<=K;i++)
            dp[i][0]=0; // on day zero, can't earn profit as need to buy first
        for(int i=0;i<=n;i++)
            dp[0][i]=0; // zero transactions
        for(int i=1; i<=K; i++) {
            for(int j=1; j<n; j++) {
                int profit = INT_MIN;
                for(int k=0; k<j; k++) {
                    profit = max(profit, (prices[j]-prices[k]) + dp[i-1][k]);
                }
                dp[i][j] = max(dp[i][j-1], profit);
            }
        }
        int ans = dp[K][n-1];
        for(int i=0;i<=K;i++)
            delete[] dp[i];
        delete[] dp;
        return ans;
    }
};

