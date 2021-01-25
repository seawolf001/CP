#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        for(int last=0;last<=n-1;last++) {
            for(int j=0;j<=last;j++) {
                string sub = s.substr(j, last-j+1);
                bool valid = find(wordDict.begin(), wordDict.end(), sub) != wordDict.end();
                dp[last] = (j>0 ? dp[j-1]: 1) && valid;
                if(dp[last]) break;
            }
        }
        return dp[n-1];
    }
};


