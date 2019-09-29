/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

int knapsack(int * wt, int * v, int n, int w) {
    int ** dp = new int * [n+1];
    for (int i=0;i<=n;i++) {
        dp[i] = new int[w+1];
        memset(dp[i], 0, (w+1)*sizeof(int));
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=w;j++) {
            if(i==0||j==0) {
                dp[i][j] = 0;
            } else if(wt[i-1]>j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    return dp[n][w];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n=0; cin>>n;
    int * v = new int[n];
    int * w = new int[n];
    for (int i=0;i<n;i++) cin>>v[i];
    for (int i=0;i<n;i++) cin>>w[i];
    int W=0; cin >> W;
    cout << knapsack(w, v, n, W) << endl;
    return 0;
}


