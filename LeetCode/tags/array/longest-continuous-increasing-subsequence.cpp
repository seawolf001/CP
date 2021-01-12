
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int curr=1, ans=1;
        for(int i=1;i<n;i++) {
            if(nums[i-1]<nums[i]) {
                curr++;
                ans = max(ans, curr);
            } else {
                ans = max(ans, curr);
                curr=1;
            }
        }
        return ans;
    }
};
