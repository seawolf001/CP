#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
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

