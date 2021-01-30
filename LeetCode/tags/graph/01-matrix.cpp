#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        int n = arr.size(), m = n>0 ? arr[0].size():0;
        int vis[n][m];
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                vis[i][j] = 0;
                if(arr[i][j]==0) {
                    vis[i][j] = 1;
                    q.push(make_pair(i,j));
                }
            }
        }
        int lvl=0, x,y,x1,y1, xm[4]={0,0,-1,1}, ym[4]={-1,1,0,0};
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto f = q.front(); q.pop();
                x = f.first, y=f.second;
                if(arr[x][y] != 0)
                    arr[x][y] = lvl;
                for(int k=0;k<4;k++) {
                    x1 = x + xm[k];
                    y1 = y + ym[k];
                    if(x1<0||x1>=n||y1<0||y1>=m)
                        continue;
                    if(vis[x1][y1]==0) {
                        vis[x1][y1] = 1;
                        q.push(make_pair(x1,y1));
                    }
                }
            }
            ++lvl;
        }
        return arr;
    }
};

