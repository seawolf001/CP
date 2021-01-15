typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    int n=0,m=0;
    int X[4]={1,0,-1,0};
    int Y[5]={0,1,0,-1};

    bool valid(int x, int y, vii &vis) {
        if(x<0||x>=n||y<0||y>=m) return false;
        return vis[x][y]==0;
    }

    bool dfs(vii &h, vii &vis, int x, int y, int e, int AllowedEfforts) {
        if(e > AllowedEfforts) return false;
        if(x==n-1 && y==m-1) return true;
        vis[x][y]=1;
        for(int k=0;k<4;k++) {
            int x1=x+X[k], y1=y+Y[k];
            if(valid(x1,y1,vis)) {
                if (dfs(h, vis, x1, y1, max(e, abs(h[x1][y1]-h[x][y])), AllowedEfforts))
                    return true;
                vis[x1][y1]=0;
            }
        }
        return false;
    }
public:
    int minimumEffortPath(vii &h) {
        n = h.size(), m = n>0 ? h[0].size():0;
        int left=0, right=INT_MIN, mid=0, minEffort=INT_MAX;
        for(auto row:h) right = max(right, *max_element(row.begin(), row.end()));
        while(left<=right) {
            mid = (left+right)/2;
            vii vis(n,vi(m,0));
            if(dfs(h,vis,0,0,0, mid)) {
                minEffort = min(minEffort, mid);
                right=mid-1;
            } else left=mid+1;
        }
        return minEffort;
    }
};

