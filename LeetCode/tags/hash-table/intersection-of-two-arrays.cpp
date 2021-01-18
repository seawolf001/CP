#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hs, hs2;
        for(int &x: nums1) hs.insert(x);
        for(int &x:nums2) if(hs.count(x)!=0) hs2.insert(x);
        return vector<int>(hs2.begin(), hs2.end());
    }
};


