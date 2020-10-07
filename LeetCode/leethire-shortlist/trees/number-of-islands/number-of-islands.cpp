/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
private:
    vector<int> X{0, 1, 0, -1};
    vector<int> Y{-1, 0, 1, 0};
    void dfs(vector<vector<char>>& grid, int i, int j, int M, int N) {
        grid[i][j] = 'X';
        for(int c=0;c<4;c++) {
            int x = i+X[c];
            int y = j+Y[c];
            if(x<0 || x>=M || y<0 || y>=N) continue;
            if(grid[x][y]=='1') dfs(grid, x, y, M, N);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        size_t M = grid.size();
        if (M==0) return 0;
        size_t N = grid[0].size();
        int count=0;
        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                if(grid[i][j]=='1') {
                    count++;
                    dfs(grid, i, j, M, N);
                }
            }
        }
        return count;
    }
};

