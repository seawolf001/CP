#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool dp[n+1][m+1];

        for(int i=0;i<=n;i++)
            dp[i][0] = false; // empty pattern

        dp[0][0] = true; // empty string, empty pattern

        for(int j=1;j<=m;j++)
            dp[0][j] = dp[0][j-1] && p[j-1]=='*'; // if *, take previous otherwise false;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};


