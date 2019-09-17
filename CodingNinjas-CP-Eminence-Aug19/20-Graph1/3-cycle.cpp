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

void dfs(vector<int> adj[], bool * vis, int n, int v, int s, int &count) {
    if(n==0) {
        if(find(adj[v].begin(), adj[v].end(), s) != adj[v].end())
            count++;
        return;
    }
    vis[v]=true;
    for(auto it=adj[v].begin(); it!=adj[v].end(); it++) {
        if(!vis[*it]) {
            dfs(adj, vis, n-1, *it, s, count);
        }
    }
    vis[v]=false;
}

int findCycles(vector<int> adj[], int c, int n, int m) {
    bool * vis = new bool[n];
    memset(vis, false, sizeof(vis));
    int count=0;
    for(int i=0;i<(n-(c-1)); i++) {
        dfs(adj, vis, 3-1, i, i, count);
        vis[i]=true;
    }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    vector<int> adj[n];
    for(int i=0;i<m;i++) {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    return findCycles(adj, 3, n, m);
}
