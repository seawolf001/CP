/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    int coinChange(vector<int>& coins, int V) {
        vector<int> dp(V+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=V; i++) {
            // Try to count for value == i
            for(int j=0;j<coins.size(); j++) {
                // try with every coin that is smaller that i.
                if(coins[j] > i) { continue; }
                int _ans = dp[i-coins[j]];
                if (_ans != INT_MAX && _ans+1 < dp[i]) {
                    dp[i] = _ans + 1;
                }
            }
        }
        return dp[V] == INT_MAX ? -1 : dp[V];
    }
};
