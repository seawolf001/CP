
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    int X[4]={1,0,-1,0}, Y[5]={0,1,0,-1}, n=0, m=0;
    vii vis;
    bool valid(vii &grid, int x, int y, int o) {
        if(x<0||x>=n||y<0||y>=m)
            return false;
        return grid[x][y]==o;
    }
    bool checkBorderAndDir(vii &grid, int x, int y, int o) {
        if(!valid(grid, x, y,o))
            return false;
        // implies grid[x][y]==o
        if(x==0||x==n-1||y==0||y==m-1)
            return true;
        for(int k=0;k<4;k++) {
            int x1=x+X[k], y1=y+Y[k];
            if (x1<0||x1>=n||y1<0||y1>=m) continue;
            if(grid[x1][y1]!=o && vis[x1][y1]==0)
                return true;
        }
        return false;
    }
    void dfs(vii &grid, int x, int y, int o, int c) {
        if(!valid(grid,x,y,o)) return;
        if(vis[x][y]==1) return;
        vis[x][y]=1;
        if(checkBorderAndDir(grid,x,y,o))
            grid[x][y]=c;
        for(int k=0;k<4;k++)
            dfs(grid,x+X[k],y+Y[k],o,c);
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int sr, int sc, int color) {
        n = grid.size(), m = n>0 ? grid[0].size() : 0;
        if(grid[sr][sc]==color)
            return grid;
        vis = vii(n,vi(m,0));
        dfs(grid, sr, sc, grid[sr][sc], color);
        return grid;
    }
};

