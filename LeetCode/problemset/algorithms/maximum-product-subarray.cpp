/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    // max in <algorithm> is only accepting int
    long maxL(long x, long y) {
        return (x > y) ? x : y;
    }
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        long max_prod = nums[0], prod_ending_here=nums[0];
        for(int i=1;i<n;i++) {
            prod_ending_here *= nums[i];
            prod_ending_here = maxL(prod_ending_here, nums[i]);
            max_prod = max(max_prod, prod_ending_here);
            // cout << prod_ending_here << " " << max_prod << endl;
        }
        return max_prod;
    }
};

