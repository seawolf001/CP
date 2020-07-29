
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
private:
    void __rotate(vector<int>& nums, int l, int h) {
        while(l<=h) {
            swap(nums[l], nums[h]);
            l++; h--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k>0) {
            __rotate(nums, 0, n-1);
            __rotate(nums, 0, k-1);
            __rotate(nums, k, n-1);
        }
    }
};

