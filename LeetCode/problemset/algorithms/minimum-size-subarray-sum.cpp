/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
class Solution {
public:
    int minSubArrayLen(int S, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int curr=0, L=INT_MAX, s=0,e=-1;
        while(e < n-1) {
            // subarray to be [s..e] inclusive
            curr += nums[++e];
            while(e < n-1 && curr < S) {
                curr += nums[++e];
            }
            while(s < n && s <= e && curr-nums[s]>=S) {
                curr -= nums[s++];
            }
            if(curr >= S) L = min(L, e-s+1);
        }
        return L == INT_MAX ? 0 : L;
    }
};

