// strange TIMEOUT on leetcode
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
 public:
     int jump(vector<int>& nums) {
         int n = nums.size();
         if(n<2) return 0;
         vector<int>dp(n, INT_MAX);
         if(nums[0]!=0) dp[0]=0;
         for(int i=1;i<n;i++) {
             for(int j=0;j<i;j++) {
                 if(dp[j]!=INT_MAX && j+nums[j]>=i) {
                     dp[i] = min(dp[i], dp[j]+1);
                 }
             }
         }
         // for(int x:dp) cout << x << " ";
         return dp[n-1];
     }
 };


