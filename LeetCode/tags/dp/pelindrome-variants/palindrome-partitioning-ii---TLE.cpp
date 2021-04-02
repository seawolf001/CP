#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    void dfs(string s, int idx, int size, int &curr, int &ans, vector<vector<bool>> &dp) {
        if(idx == size) {
            ans = min(ans, curr);
            return;
        }
        for(int i=idx; i<size; i++) {
            if(dp[idx][i]) {
                ++curr; // idx...i is another partition
                dfs(s, i+1, size, curr, ans, dp);
                --curr; // backtrack
            }
        }
    }
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
        int ans = INT_MAX, curr = 0; // LEN=1 is pelindrome
        dfs(s, 0, n, curr, ans, dp);
        return ans-1; // cuts = partitions-1
    }
};


