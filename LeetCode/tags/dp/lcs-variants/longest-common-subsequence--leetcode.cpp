/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int m = a.size();
    int n = b.size();
    int dp[m+1][n+1];
    bool vis[m+1][n+1];
    for(int i=0;i<=m;i++)  memset(dp[i], 0, sizeof(dp[i]));
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    vector<int> ans;
    int L=dp[m][n];
    for(int i=m;i>=1 && L>0;) {
        for(int j=n;j>=1 && L>0;) {
            if(a[i-1]==b[j-1]) {
                ans.push_back(a[i-1]);
                L--;
                i--;
                j--;
            } else if(dp[i-1][j]>=dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


