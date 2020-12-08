/* Jitendra Kumar */
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cout << #x << " is " << (x) << endl;

class Solution {
public:
    int is_miss_placed(vector<int>& nums, int i, int size) {
        if(i==0)
            return (nums[i] > nums[i+1]);
        else if(i==size-1)
            return (nums[i] < nums[i-1]);
        else return (
                (nums[i] > nums[i+1]) ||
                (nums[i] < nums[i-1])
            );
    }

    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), shortest = 0;
        if(n < 2) return 0;
        int smallest_miss_placed = INT_MAX, largest_miss_placed = INT_MIN;
        for(int i=0;i<n;i++) {
            if(is_miss_placed(nums, i, n)) {
                smallest_miss_placed = min(smallest_miss_placed, nums[i]);
                largest_miss_placed = max(largest_miss_placed, nums[i]);
            }
        }
        if(smallest_miss_placed==INT_MAX || largest_miss_placed==INT_MIN) return 0;
        int i=0, j=n-1;
        while(nums[i]<=smallest_miss_placed) i++;
        while(nums[j]>=largest_miss_placed) j--;
        return (abs(j-i)+1);
    }
};

