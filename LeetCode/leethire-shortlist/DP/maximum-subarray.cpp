/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long max_ending_here=0, max_so_far=INT_MIN;
        for (int x: nums) {
            max_ending_here += x;
            if (max_ending_here < 0) max_ending_here = 0;
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};
