#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    void dfs(vector<vector<int>>& rooms, int x, vector<bool> &vis) {
        if(vis[x])
            return;
        vis[x] = true;
        for(auto &e: rooms[x]) {
            if(!vis[e])
                dfs(rooms, e, vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        bool ans = true;
        for(auto e: vis)
            ans = ans & e;
        return ans;
    }
};


