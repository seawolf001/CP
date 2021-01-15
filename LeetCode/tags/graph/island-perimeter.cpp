class Solution {
private:
    int n=0, m=0, X[4]={0,0,-1,1}, Y[4]={-1,1,0,0},x1=0,y1=0; // LRUD
    bool valid(vector<vector<int>> &grid, int x, int y) {
        if(x<0||x>=n||y<0||y>=m) return false;
        return grid[x][y]==1;
    }
    bool contributes(vector<vector<int>> &grid, int x, int y){
        if(x<0||x>=n||y<0||y>=m||grid[x][y]==0)
            return true;
        return false;
    }
    void dfs(vector<vector<int>> &grid, int x, int y, int &peri) {
        if(!valid(grid,x,y)) return;
        if(grid[x][y]==-1) return;
        grid[x][y]=-1;
        for(int k=0;k<4;k++) {
            x1=x+X[k], y1=y+Y[k];
            if(contributes(grid, x1, y1)) ++peri;
            else dfs(grid, x+X[k], y+Y[k], peri);
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = n>0 ? grid[0].size():0;
        int peri=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    dfs(grid,i,j, peri);
                    return peri;
                }
            }
        }
        return peri;
    }
};
