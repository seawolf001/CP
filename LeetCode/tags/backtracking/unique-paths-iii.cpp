#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int n=0, m=0, sx=0, sy=0;
    int xmove[4] = {0,0,-1,1};
    int ymove[4] = {-1,1,0,0};

    bool validIndex(int x, int y) {
        return !(x<0 || x>=n || y<0 || y>=m);
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int empty, int &paths) {
        if(!validIndex(x,y) || grid[x][y]==INT_MAX || grid[x][y]==-1 ) return;
        if(grid[x][y]==2) {
            if (empty==0) ++paths;
            return;
        }
        int prev=grid[x][y];
        grid[x][y]=INT_MAX; // visited
        for(int k=0;k<4;k++) {
            int x1 = x + xmove[k], y1 = y + ymove[k];
            if(!validIndex(x1,y1)) continue;
            if(grid[x1][y1]==0 || grid[x1][y1]==2)
                dfs(grid,x1,y1,empty-1, paths);
        }
        grid[x][y] = prev; // backtrack
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = n > 0 ? grid[0].size() : 0;
        int paths = 0, empty=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    sx=i, sy=j;
                } else if(grid[i][j]==0) {
                    ++empty;
                }
            }
        }
        grid[sx][sy] = INT_MIN;
        dfs(grid, sx, sy, empty, paths);
        return  paths;
    }
};
