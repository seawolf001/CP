#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        long dp[n+1][m+1];
        for(int i=0;i<=n;i++)
            memset(dp[i],0,sizeof(dp[i]));
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else if(s[i-1]==t[j-1])
                    /*
                     * last char matched, now this could be possible with and without s[i-1]
                     * with s[i-1] : dp[i-1][j-1], t[j-1] taken as well
                     * without s[i-1]: drop s[i-1] but keep t[j-1] to match elsewhere.
                     */
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    /* drop s[i-1] and search again for s[0..i-2] & t[0..j-1], t remains as is. */
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};

