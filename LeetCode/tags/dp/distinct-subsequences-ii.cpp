#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
long MOD = 1000000007;

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        if(n==0) return 1;
        unordered_map<int, int> dp;  dp[-1]=1;
        unordered_map<char, int> idx;
        for(int i=0;i<n;i++) {
            char c = s[i];
            dp[i] = (MOD + dp[i-1]<<1 % MOD) % MOD;
            if(idx.find(c) != idx.end())
                dp[i] = (MOD + dp[i] - dp[idx[c]-1]) % MOD;
            idx[c] = i;
        }
        return dp[n-1] -1;
    }
};


