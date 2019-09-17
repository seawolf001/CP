/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

void dfs(vector<int> adj[], int s, bool* vis) {
    vis[s]=true;
    for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
        if(vis[*it]==false) dfs(adj, *it, vis);
    }
}

int solve(int n, int m, vector<int> u, vector<int> v) {
    bool * vis = new bool[n+1];
    memset(vis, false, (n+1)*sizeof(bool));
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false) {
            count++;
            dfs(adj,i,vis);
        }
    }
    delete[] vis;
    return count;
}
