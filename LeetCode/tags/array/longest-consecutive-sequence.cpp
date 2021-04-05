#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n), Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> s;
        for(int x: nums)  s.insert(x);
        int ans = 1;
        for(int x: s) {
            if(s.find(x-1) != s.end()) continue;
            int y = x+1;
            while(s.find(y) != s.end())  ++y;
            ans = max(ans, y-x);
        }
        return ans;
    }
};


