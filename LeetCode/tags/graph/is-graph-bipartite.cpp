/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        queue<int> q;
        int n = g.size();
        int color[n];
        memset(color, -1, sizeof(color));
        for(int i=0;i<n;i++) {
            if(color[i]!=-1) continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v: g[u]) {
                    if(color[v]==-1) {
                        color[v] = 1 - color[u]; // invert color
                        q.push(v);
                    } else if(color[u]==color[v]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
