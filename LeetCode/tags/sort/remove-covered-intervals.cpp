
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int discrete=0, s=-1, e=-1;
        sort(intervals.begin(), intervals.end()); // sort on first key, start-time
        for(auto p:intervals) {
            if(p[0]>s && p[1]>e) {++discrete; s=p[0];}
            e = max(e, p[1]);
        }
        return discrete;
    }
};


