
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool ** dp = new bool*[n];
        for (int i=0;i<n;i++) {
            dp[i] = new bool[n];
            memset(dp[i], false, sizeof(bool)*n);
        }
        int maxL=0, start=0;
        for(int i=0;i<n;i++) {
            dp[i][i] = true; //strings of length 1
            start=i;
            maxL=1;
        }
        for(int i=0;i<n-1;i++) {
            if (s[i]==s[i+1]) {
                dp[i][i+1]=true;
                start=i;
                maxL=2;
            }
        }
        for(int len=3;len<=n;len++) {
            for(int i=0;i<n-len+1; i++) {
                int j=i+len-1;
                if(dp[i+1][j-1] && s[i]==s[j]) {
                    dp[i][j]=true;
                    if (len > maxL) {
                        maxL=len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxL);
    }
};

