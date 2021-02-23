#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

#define RED 2
#define BLUE 3

class Solution {
private:
    unordered_map<int, list<int>> adj;
    bool bfs(int s, vector<int> &vis) {
        queue<int> q;
        q.push(s);
        vis[s] = BLUE;
        int color = RED;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int u = q.front(); q.pop();
                vis[u] = color;
                for(int &v: adj[u]) {
                    if(vis[v] == 0)
                        q.push(v);
                    else if(vis[v] == vis[u])
                        return false;
                }
            }
            color = color == RED ? BLUE: RED;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        adj.clear();
        for(auto &e: dislikes) {
            adj[e[0]].push_front(e[1]);
            adj[e[1]].push_front(e[0]);
        }
        vector<int> vis(N+1, 0);
        for(int i=1; i<=N; i++) {
            if(vis[i]==0 && false == bfs(i, vis))
                return false;
        }
        return true;
    }
};


