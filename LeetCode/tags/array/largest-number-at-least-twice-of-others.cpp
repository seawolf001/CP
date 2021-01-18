#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxA=-1, maxB=-1, idx=-1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>maxA) {
                maxB = maxA;
                maxA = nums[i];
                idx=i;
            } else if(nums[i]>maxB) {
                maxB = nums[i];
            }
        }
        if(maxB*2 <= maxA)
            return idx;
        return -1;
    }
};


