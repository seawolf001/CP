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
        int dp[amount+1]; memset(dp, 0, sizeof(dp));
        dp[0]=1;
        for(int& c: coins) {
            for(int a=0;a<=amount;a++) {
                if(c<=a) {
                    dp[a] += dp[a-c];
                }
            }
        }
        return dp[amount];
    }
};


