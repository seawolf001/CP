#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int xm[4] = {0,0,-1,1}, ym[4] = {-1,1,0,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = n > 0 ? grid[0].size() : 0, fresh=0, minutes=0;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) ++fresh;
                if(grid[i][j] == 2) q.push(make_pair(i,j));
            }
        }
        if(fresh==0) return 0;

        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto f = q.front(); q.pop();
                for(int k=0;k<4;k++) {
                    int i = f.first + xm[k];
                    int j = f.second + ym[k];
                    if(i<0||i>=n||j<0||j>=m) continue;
                    if(grid[i][j]==1) {
                        grid[i][j] = 2; --fresh;
                        q.push(make_pair(i,j));
                    }
                }
            }
            ++minutes;
        }
        return fresh == 0 ? minutes-1 : -1;
    }
};

