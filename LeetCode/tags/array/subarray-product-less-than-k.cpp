#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prod=1; int n=nums.size(), s=0, e=0, count=0;
        for(int e=0;e<n;e++) {
            prod *= nums[e];
            while(prod>=k) prod /= nums[s++];
            count += e-s+1;
        }
        return count;
    }
};


