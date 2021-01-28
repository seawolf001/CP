#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++){
                if(i==0 && j==0) dp[i][j]=0;
                else if(i==0) dp[i][j] = j; // w1=="", delete all j chars in w2
                else if(j==0) dp[i][j] = i; // w2=="", delete all i chars in w1
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1]; // same chars, 0 operations
                else
                    // delete one from either words if that operation leads to optimal answer.
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
