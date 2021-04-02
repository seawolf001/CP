#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0;i<n;i++) dp[i][i] = true; // LEN=1
        for(int i=1;i<n;i++) dp[i-1][i] = s[i-1]==s[i] ? true: false; // LEN=2
        for(int l=3;l<=n;l++) { // LEN >= 3
            for(int st=0;st<=n-l;st++) {
                int end = st + l - 1;
                dp[st][end] = s[st]==s[end] && dp[st+1][end-1] ? true: false;
            }
        }
        vector<int> cuts(n, INT_MAX);
        int ans = n-1; // partitions of LEN=1
        for(int i=0;i<n;i++) {
            cuts[i] = i; // string of len i can have i-1 cuts to have i pelindrome partitions of LEN=1
            for(int j=0;j<=i; j++) {
                // check if j...i is pelindrome
                if (!dp[j][i])
                    continue;
                cuts[i] = j==0 ? 0: min(cuts[i], cuts[j-1]+1);
            }
        }
        return cuts[n-1];
    }
};

