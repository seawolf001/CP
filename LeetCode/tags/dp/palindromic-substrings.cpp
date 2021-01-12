
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // dp[i][j] = true implies s[i:j] is pelindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        long count=0;
        for(int i=0;i<n;i++) {
            // substrings of len=1
            dp[i][i]=true;
            count++;
        }
        for(int i=1;i<n;i++) {
            if(s[i-1]==s[i]) {
                // substrings of len=2
                dp[i-1][i] = true;
                count++;
            }
        }
        for(int k=3;k<=n;k++) { // calculate for smaller length substrings and reuse them
            for(int i=0;i<n-k+1; i++) {
                int j = i+k-1;
                // s[i+1...j-1] is pelindrome and s[i]==s[j]
                if(s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};



