#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

/*
 * Always choose the interval with earliest end time.
 * This way, maximum number of non-overlapping intervals can be scheduled.
 * In the otherwise case, as in this questions context, we need to remove that interval;
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(), intervals.end(),
                [](const vector<int> &a, const vector<int> &b){
                    return a[1] < b[1];
                });
        int end = INT_MIN, count=0;
        for(vector<int> &e: intervals) {
            if(e[0] >= end)
                end = e[1];
            else
                ++count;
        }
        return count;
    }
};

