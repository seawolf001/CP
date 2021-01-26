/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int integerBreak(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1, 1); // dp[i] contains prod of subset [1....n-1] such that sum(subset)==n
        dp[0] = dp[1] = 0; // atleast 2 numbers required.
        dp[2] = 1; // 2==1+1 hence 1*1
        for(int i=3;i<=n;i++) {
            for(int j=1; j<i;j++) {
                // Either only 2 elements, j & i-j
                // more that 2 elements. i === j+S
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
