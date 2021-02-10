#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int xm[8] = {0,1,1,1,0,-1,-1,-1};
    int ym[8] = {-1,-1,0,1,1,1,0,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int steps=1, n = grid.size(), x,y,x1,y1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        grid[0][0]=2; // visited;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                x = q.front().first; y = q.front().second; q.pop();
                if(x==n-1 && y==n-1)
                    return steps;
                for(int k=0;k<8;k++) {
                    x1 = x+xm[k], y1=y+ym[k];
                    if(x1<0 || x1>=n || y1<0 || y1>=n || grid[x1][y1]!=0)
                        continue;
                    q.push(make_pair(x1,y1));
                    grid[x1][y1]=2;
                }
            }
            ++steps;
        }
        return -1;
    }
};


