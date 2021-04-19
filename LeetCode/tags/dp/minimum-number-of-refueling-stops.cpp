#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n+1, startFuel); //dp[i] means the farest position to reach by using totally i stations
        for(int i=0;i<n;i++) {
            for(int t=i;t>=0; t--) {
                if(dp[t] < stations[i][0]) break;
                dp[t+1] = max(dp[t+1], dp[t]+stations[i][1]);
            }
        }
        for(int i=0;i<=n;i++) {
            if(dp[i]>=target)
                return i;
        }
        return -1;
    }
};
