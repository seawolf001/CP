#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), l=0, r=n-1;
        while(l<=r) {
            int m = (l+r)/2;
            if(nums[m]==target) {
                return m;
            } else if(nums[l] <= nums[m]) { // l...m is sorted
                if(nums[l] <= target && target < nums[m]) r = m-1;
                else l = m+1;
            } else if(nums[m] < target && target <= nums[r]){
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return -1;
    }
};


