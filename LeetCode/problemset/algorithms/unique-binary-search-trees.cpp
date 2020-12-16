/* Jitendra Kumar */
// https://leetcode.com/problems/unique-binary-search-trees/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]= dp[1] = 1; // zero or 1 node
        for(int i=2;i<=n;i++) { // number of elements
            for(int j=0;j<i;j++) { // jth as root
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};



