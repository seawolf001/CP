
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n]; memset(dp, false, sizeof(dp));
        dp[0]=true;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(dp[j] && j+nums[j]>=i) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};


