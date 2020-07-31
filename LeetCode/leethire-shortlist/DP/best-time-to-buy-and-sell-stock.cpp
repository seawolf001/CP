/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),
            profit=0,
            lowest=INT_MAX;
        if(!n)
            return 0;
        for(int i=0;i<n;i++) {
            lowest = min(lowest, prices[i]);
            profit = max(profit, prices[i]-lowest);
        }
        return profit;
    }
};
