
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), s=0, e=0, ans=0;
        multiset<int> m;
        while(e<n) {
            m.insert(nums[e++]);
            while(s<=e && *m.rbegin()-*m.begin()>limit)
                m.erase(m.find(nums[s++]));
            ans = max(ans, e-s);
        }
        return ans;
    }
};


