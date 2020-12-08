/* Jitendra Kumar */
// https://leetcode.com/problems/3sum/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*
 * Method 1: Use 3 loops and check for every triplet: O(n^3) Time | O(1) Space
 * Method 2: Sort the array, Fix 1 number and then use 2-pointer technique for other 2 numbers. O(n^2)
 * */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end()); // O(nlogn)
        int n = nums.size();
        for(int i=0;i<n-2;) {
            int j=i+1, k=n-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                    while(j<k && nums[k-1]==nums[k]) k--;
                    k--;
                } else if(sum > 0){
                    while(j<k && nums[k-1]==nums[k]) k--;
                    k--;
                } else {
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1]) i++;
            i++;
        }
        return triplets;
    }
};

