#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int xm[4] = {0,0,-1,1};
    int ym[4] = {-1,1,0,0};
    int n=0, m=0;
    bool valid(int x, int y) { return !(x<0 || y<0 || x>=n || y>=m); }
public:
    int longestIncreasingPath(vector<vector<int>>& arr) {
        n = arr.size(), m = n > 0 ? arr[0].size() : 0;
        if(n==0) return 0;
        vector<vector<int>> indegree(n, vector<int>(m, 0));
        queue<vector<int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int k=0;k<4;k++) {
                    int x = i+xm[k], y = j+ym[k];
                    if(!valid(x,y)) continue;
                    if(arr[x][y] < arr[i][j]) // we can have an edge from x,y ---> i,j
                        ++indegree[i][j];
                }
                if(indegree[i][j] == 0)
                    q.push({i,j,1}); // we can start DFS from i,j
            }
        }
        int ans = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto f = q.front(); q.pop();
                int x = f[0], y=f[1], d=f[2];
                cout << x << " " << y << " " << d << endl;
                ans = max(ans, d);
                for(int k=0;k<4;k++) {
                    int x1 = x + xm[k], y1 = y + ym[k];
                    // enqueue only if the neighbour element is strictly greater
                    if(!valid(x1,y1) || arr[x1][y1] <= arr[x][y]) continue;
                    else q.push({x1, y1, d+1});
                }
            }
        }
        return ans;
    }
};


