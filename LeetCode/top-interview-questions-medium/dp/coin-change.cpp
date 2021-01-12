#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int coinChange(vector<int>& coins, int N) {
        int n = coins.size();
        if(n==0||N==0) return 0;
        vector<int> dp(N+1, INT_MAX); dp[0]=0;
        for(int i=1;i<=N;i++) {
            for(int& c:coins) {
                if(c>i||dp[i-c]==INT_MAX) continue;
                dp[i] = min(dp[i], 1+dp[i-c]);
            }
        }
        return dp[N]==INT_MAX ? -1 : dp[N];
    }
};
