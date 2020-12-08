/* Jitendra Kumar */
//https://leetcode.com/problems/next-permutation/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;
        if(n==2) {
            swap(nums[0], nums[1]);
            return;
        }
        int i=0, j=n-1, flag=false;
        while(j>0) {
            if(nums[j-1]<nums[j]) {
                flag=true;
                break;
            }
            j--;
        }
        if(!flag) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int k=INT_MAX, x=INT_MAX;
        for(i=j; i<n;i++) {
            if(nums[i]>nums[j-1]) {
                if(nums[i]<x) {
                    x = nums[i];
                    k=i;
                }
            }
        }
        if(k!=INT_MAX) {
            swap(nums[j-1], nums[k]);
        }
        sort(nums.begin()+j, nums.end());
    }
};

