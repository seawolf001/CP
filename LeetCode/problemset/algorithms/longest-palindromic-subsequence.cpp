/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    // longestPalindromeSubseq of string s is LCS of s & reverse(s)
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==0) return 0;
        string r = s;
        reverse(r.begin(), r.end()); // r is reverse of s
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                if(i==0||j==0) dp[i][j]=0;
                else if(s[i-1]==r[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
