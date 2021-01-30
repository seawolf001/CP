#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {
        int n = arr.size(), m = n > 0 ? arr[0].size() : 0, mx=INT_MIN;
        int dp[n][m];
        for(int i=0;i<n;i++)
            memset(dp[i], 0, sizeof(dp[i]));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || j==0 || arr[i][j] == '0')
                    dp[i][j] = arr[i][j] - '0';
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                mx = max(mx, dp[i][j]);
            }
        }
        return mx*mx;
    }
};


