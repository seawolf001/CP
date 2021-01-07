/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        if(l==0) return 0;
        int dp[l+1][m+1][n+1];
        for(int i=0;i<=l;i++) {
            for(int j=0;j<=m;j++) {
                for(int k=0;k<=n;k++) {
                    dp[i][j][k]=0;
                }
            }
        }
        for(int i=1;i<=l;i++) {
            // using l strings [0...l-1]
            string s= strs[i-1];
            int ones = count(s.begin(), s.end(), '1');
            int zeroes = s.size()-ones;
            for(int j=0;j<=m;j++) {
                // max j zeroes
                for(int k=0;k<=n;k++) {
                    // max k ones
                    if(zeroes<=j && ones<=k) {
                        dp[i][j][k] = max(dp[i-1][j][k], 1+dp[i-1][j-zeroes][k-ones]);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};

