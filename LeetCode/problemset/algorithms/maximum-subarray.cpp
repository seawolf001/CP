/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
// https://leetcode.com/problems/maximum-subarray/submissions/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int max_so_far = nums[0], max_ending_here=nums[0];
        for(int i=1;i<n;i++) {
            max_ending_here += nums[i];
            max_ending_here = max(max_ending_here, nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};


