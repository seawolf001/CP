/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return false;
        k = abs(k);
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1] && nums[i]==0) {
                return true;
            } else if(k!=0 && (nums[i-1]+nums[i]) % k==0) {
                return true;
            }
        }
        if(k==0) return false;

        unordered_map<int, int> h;
        int s=0, r=0;
        for(int i=0;i<n;i++) {
            s+=nums[i];
            r = s%k;
            if(r==0 && i>0) return true;
            if(h.find(r)!=h.end()) {
                if(abs(h[r]-i)>=2) {
                    return true;
                }
            } else {
                h[r] = i;
            }
        }
        return false;
    }
};


