/* Jitendra Kumar */
//https://leetcode.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[i][j] = true implies s[i:j] is pelindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start=0, L=0;
        for(int i=0;i<n;i++) {
            // substrings of len=1
            dp[i][i]=true;
            L=1;
            start=i;
        }
        for(int i=1;i<n;i++) {
            if(s[i-1]==s[i]) {
                // substrings of len=2
                dp[i-1][i] = true;
                start=i-1;
                L=2;
            }
        }
        for(int k=3;k<=n;k++) { // calculate for smaller length substrings and reuse them
            for(int i=0;i<n-k+1; i++) {
                int j = i+k-1;
                // s[i+1...j-1] is pelindrome and s[i]==s[j]
                if(s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if(k > L) {
                        L = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, L);
    }
};


