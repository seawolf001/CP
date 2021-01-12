
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2;i<n;i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};
