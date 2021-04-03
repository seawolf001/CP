#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n==0)
            return 0;
        sort(points.begin(), points.end(),
                [](const vector<int> a, const vector<int> b) {
                    return a[1] < b[1];
                });
        int pos = points[0][1], count=1;
        for(int i=1;i<n;i++) {
            if(points[i][0] <= pos)
                continue;
            pos = points[i][1];
            ++count;
        }
        return count;
    }
};

