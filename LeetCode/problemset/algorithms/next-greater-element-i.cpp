/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ng;
        stack<int>st;
        for(int x:nums2) {
            while(!st.empty() && st.top()<x) {
                ng[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> ans(nums1.size(), -1);
        for(int i=0;i<nums1.size();i++) {
            auto itr=ng.find(nums1[i]);
            if(itr!=ng.end()) {
                ans[i]=itr->second;
            }
        }
        return ans;
    }
};

