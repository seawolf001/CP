#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int idx=0; idx < nums.size(); idx++) {
            if(q.front() == idx-k) // invalidate old entry
                q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[idx]) // maintain the monotonic queue property
                q.pop_back();
            q.push_back(idx);
            if(idx-k+1 >= 0) // nums[q.front() is max in (idx-k, idx];
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
