#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0, n = intervals.size();

        // intervals before newInterval.start
        while(idx < n && intervals[idx][1] < newInterval[0])
            ans.push_back(intervals[idx]), ++idx;

        // merge overallping intervals with newInterval;
        while(idx < n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            ++idx;
        }

        // intervals after newInterval.end
        ans.push_back(newInterval);
        while(idx < n)
            ans.push_back(intervals[idx]), ++idx;
        return ans;
    }
};


