#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    unordered_map<int, int> hs;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        hs.clear();
        for(int &x: nums) hs[x]++;
        auto comparator= [&](const int &a, const int &b) { return hs[a] > hs[b]; };
        priority_queue<int, vector<int>, decltype(comparator)> minh(comparator);
        for(auto &x:hs) {
            minh.push(x.first);
            if(minh.size()>k) minh.pop();
        }
        vi ans;
        while(minh.empty()==false) {
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
};


