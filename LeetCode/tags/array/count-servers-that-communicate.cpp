
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n > 0 ? grid[0].size(): 0;
        unordered_map<int,int> r,c;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) continue;
                r[i]++;
                c[j]++;
            }
        }
        int count=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) continue;
                if(r[i]>1||c[j]>1) count++;
            }
        }
        return count;
    }
};


