/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    int R = accumulate(A.begin(), A.end(), 0);
    bool dp[R+1]; memset(dp, false, sizeof(dp));
    dp[0]=true;
    for(int &x: A) {
        for(int s=R; s>=x; s--) {
            dp[s] = dp[s] || dp[s-x];
        }
    }
    int minimum=INT_MAX;
    for(int i=0;i<=R/2; i++) {
        if(dp[i]) {
            minimum = min(minimum, R-2*i);
        }
    }
    return minimum;
}


