/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                dp[i][j]=0;
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0||j==0) dp[i][j]=0;
                else if(A[i-1]==B[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j]=0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

