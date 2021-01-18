#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hs; int n=nums.size();
        for(int i=0;i<n;i++) {
            if(i>k) hs.erase(nums[i-k-1]);
            if(hs.count(nums[i])==1) return true;
            hs.insert(nums[i]);
        }
        return false;
    }
};


