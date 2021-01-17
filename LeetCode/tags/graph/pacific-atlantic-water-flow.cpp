#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    int X[4]={0,0,-1,1}, Y[4]={-1,1,0,0};
    void dfs(vii &matrix, int x, int y, vii &vis, int n, int m) {
        if(x<0||x>=n||y<0||y>=m||vis[x][y]==1) return;
        vis[x][y]=1;
        for(int k=0;k<4;k++) {
            int x1=x+X[k], y1=y+Y[k];
            if(x1<0||x1>=n||y1<0||y1>=m) continue;
            if(vis[x1][y1]==0 && matrix[x][y]<=matrix[x1][y1])
                dfs(matrix,x1,y1,vis,n,m);
        }
    }
public:
    vii pacificAtlantic(vii &matrix) {
        int n = matrix.size(), m = n > 0 ? matrix[0].size() : 0;
        vii pacific(n,vi(m,0)), atlantic(n,vi(m,0));
        for(int i=0;i<n;i++) {
            dfs(matrix,i,0,pacific,n,m);
            dfs(matrix,i,m-1,atlantic,n,m);
        }
        for(int j=0;j<m;j++) {
            dfs(matrix,0,j,pacific,n,m);
            dfs(matrix,n-1,j,atlantic,n,m);
        }
        vii coordinates;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j]==1 && atlantic[i][j]==1) {
                    coordinates.push_back({i,j});
                }
            }
        }
        return coordinates;
    }
};


