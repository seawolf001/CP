#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int>>> mp;
        int n = nums.size(); set<vector<int>> s;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                mp[nums[i]+nums[j]].push_back(make_pair(i,j));
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int r = target-(nums[i]+nums[j]);
                if(mp.find(r)!=mp.end()) {
                    for(auto p:mp[r]) {
                        set<int> check4{i,j,p.first,p.second};
                        if(check4.size()!=4) continue;
                        vector<int> t{nums[i],nums[j],nums[p.first],nums[p.second]};
                        sort(t.begin(),t.end()); // sort 4 nums
                        s.insert(t);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x: s) ans.push_back(x);
        return ans;
    }
};


