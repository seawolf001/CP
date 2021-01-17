#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int> &p1, const vector<int> &p2){ return p1[0]<p2[0]; });
        int dp[n]; memset(dp, 0, sizeof(dp)); dp[0]=1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(pairs[j][1]<pairs[i][0] && 1+dp[j]>dp[i])
                    dp[i] = 1 + dp[j];
                else
                    dp[i] = max(dp[i], dp[j]);
            }
        }
        return dp[n-1];
    }
};


