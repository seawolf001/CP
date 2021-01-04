/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int memoization(int W, int wt[], int val[], int n) {
    // TODO Implement recursive version using memoization to avoid recomputing same subproblem
    return 0;
}

int dyammic(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for(int v=0;v<=n;v++) {
        for(int w=0;w<=W;w++) {
            if(v==0||w==0) {
                dp[v][w]=0;
            } else if(wt[v-1]>w) {
                dp[v][w] = dp[v-1][w];
            } else {
                dp[v][w] = max(
                        val[v-1] + dp[v-1][w-wt[v-1]],
                        dp[v-1][w]
                    );
            }
        }
    }
    return dp[n][W];
}

int native_recursive(int W, int wt[], int val[], int n) {
    if(n==0||W==0)
        return 0;
    if(wt[n-1]>W)
        return native_recursive(W, wt, val, n-1);
    return max (
            val[n-1] + native_recursive(W-wt[n-1], wt, val, n-1),
            native_recursive(W, wt, val, n-1)
        );
}

int knapSack(int W, int wt[], int val[], int n) {
    /* return native_recursive(W, wt, val, n); */
    return dyammic(W, wt, val, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}


