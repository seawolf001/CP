
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum=0;
        vector<vector<int>> ans;
        for(int x=0;x<n-2;) {
            int y=x+1, z=n-1;
            while(y<z) {
                sum = nums[x]+nums[y]+nums[z];
                if(sum==0) {
                    ans.push_back(vector<int>{nums[x], nums[y], nums[z]});
                    while (y<z && nums[y]==nums[y+1]) y++;
                    y++;
                    while (y<z && nums[z-1]==nums[z]) z--;
                    z--;
                } else if(sum < 0) {
                    while (y<z && nums[y]==nums[y+1]) y++;
                    y++;
                } else {
                    while (y<z && nums[z-1]==nums[z]) z--;
                    z--;
                }
            }
            while(x<n-2 && nums[x]==nums[x+1]) x++;
            x++;
        }
        return ans;
    }
};

