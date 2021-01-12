
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*Iterative solution with or without dp exists but going for recusive solution with memoization*/

class Solution {
private:
    vector<int> dp = vector<int>(40, INT_MAX);
public:
    int tribonacci(int n) {
        if(n==0) return dp[0]=0;
        else if(n==1||n==2) return dp[n]=1;
        else if(dp[n]!=INT_MAX) return dp[n];
        dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        return dp[n];
    }
};

