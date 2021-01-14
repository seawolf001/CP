
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int &count, int n, int m) {
        if(i<0||i>=n||j<0||j>=m) return;
        if(grid[i][j]!=1) return;
        grid[i][j]=INT_MAX; count++;
        dfs(grid,i-1,j,count,n,m);
        dfs(grid,i+1,j,count,n,m);
        dfs(grid,i,j-1,count,n,m);
        dfs(grid,i,j+1,count,n,m);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n>0 ? grid[0].size():0;
        int MaxArea=0, curr=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    curr=0; dfs(grid,i,j,curr,n,m);
                    MaxArea = max(MaxArea, curr);
                }
            }
        }
        return MaxArea;
    }
};


