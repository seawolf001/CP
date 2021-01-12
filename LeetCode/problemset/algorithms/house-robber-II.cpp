/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
private:
    int robbery(vector<int>& nums, int l, int r) {
        int prev1=0, prev2=0, tmp=0;
        for(int i=l;i<=r;i++) {
            tmp = prev1;
            prev1 = max(prev2+nums[i], prev1);
            prev2 = tmp;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n==1 ? nums[0] : 0;
        // 0 & n-1 are neighbours now so can not be included in single set
        return max(robbery(nums, 0, n-2), robbery(nums, 1, n-1));
    }
};

