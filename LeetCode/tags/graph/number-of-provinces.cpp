#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int n,m;
    void dfs(int x, bool * vis, vector<vector<int>>& isConnected) {
        vis[x] = true;
        for(int y=0;y<m;y++){
            if(isConnected[x][y]==1 && vis[y]==false)
                dfs(y, vis, isConnected);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province=0;
        n = isConnected.size(), m = n > 0? isConnected[0].size() : 0;
        bool vis[n]; memset(vis, 0, n*sizeof(bool));
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                ++province;
                dfs(i,vis,isConnected);
            }
        }
        return province;
    }
};


