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
    vector<vector<int>> dp;

    bool valid(int x, int y) {
        return !(x<0 || y<0 || x>=n || y>=m);
    }

    int dfs(vector<vector<int>>& arr, int x, int y) {
        if(!valid(x,y))
            return 0;
        if(dp[x][y] != INT_MIN) // visited
            return dp[x][y];
        int dist = 1;
        for(int k=0;k<4;k++) {
            int x1 = x + xm[k], y1 = y + ym[k];
            if(!valid(x1,y1) || arr[x1][y1] <= arr[x][y])
                continue;
            dist = max(dist, dfs(arr, x1, y1) + 1);
        }
        return dp[x][y] = dist;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& arr) {
        n = arr.size(), m = n > 0 ? arr[0].size() : 0;
        if(n==0) return 0;
        dp = vector<vector<int>>(n, vector<int>(m, INT_MIN));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int indegree=0;
                for(int k=0;k<4;k++) {
                    int x = i + xm[k], y = j + ym[k];
                    if(!valid(x,y)) continue;
                    if(arr[x][y] < arr[i][j]) // we can have an edge from x,y ---> i,j
                        ++indegree;
                }
                if(indegree == 0)
                    ans = max(ans, dfs(arr, i, j));
            }
        }
        return ans;
    }
};

