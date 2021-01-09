/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) {
            memset(dp[i], 0, sizeof(dp[i]));
        }
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0 || j==0) {
                    dp[i][j]=0;
                } else if(a[i-1]==b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans="";
        int L = dp[n][m], i=n, j=m;
        while(i>=1 && j>=1) {
            if(a[i-1]==b[j-1]){
                ans = a[i-1] + ans;
                i--; j--;
            } else if(dp[i-1][j]>=dp[i][j-1]) {
                ans = a[i-1] + ans;
                i--;
            } else {
                ans = b[j-1] + ans;
                j--;
            }
        }
        while(i>=1) {ans = a[i-1]+ans; i--;}
        while(j>=1) {ans = b[j-1]+ans; j--;}
        return ans;
    }
};



