#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max({
                nums[0]*nums[1]*nums[n-1],
                nums[0]*nums[n-2]*nums[n-1],
                nums[n-3]*nums[n-2]*nums[n-1]
            });
    }
};



