// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    int minEffort=INT_MAX, n=0,m=0;
    int X[4]={1,0,-1,0};
    int Y[5]={0,1,0,-1};

    bool valid(int x, int y, vii &vis) {
        if(x<0||x>=n||y<0||y>=m) return false;
        return vis[x][y]==0;
    }

    void dfs(vii &h, vii &vis, int x, int y, int e) {
        if(e >= minEffort) return;
        if(x==n-1 && y==m-1) {
            minEffort = min(minEffort, e);
            return;
        }
        vis[x][y]=1;
        for(int k=0;k<4;k++) {
            int x1=x+X[k], y1=y+Y[k];
            if(valid(x1,y1,vis)) {
                dfs(h, vis, x1, y1, max(e, abs(h[x1][y1]-h[x][y])));
                vis[x1][y1]=false;
            }
        }
    }
public:
    int minimumEffortPath(vii &h) {
        n = h.size(), m = n>0 ? h[0].size():0;
        vii vis(n,vi(m,0));
        dfs(h,vis,0,0,0);
        return minEffort;
    }
};

