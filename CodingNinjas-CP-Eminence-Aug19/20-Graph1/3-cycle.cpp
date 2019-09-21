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

void DFS(vector<int> g[], bool* vis, int N, int v, int s, int &count) {
    if(N==0) {
        bool cycle = find( g[v].begin(), g[v].end(), s ) != g[v].end();
        if(cycle) { count++; }
        return;
    }
    vis[v]=true;
    for(auto it=g[v].begin(); it!=g[v].end(); it++){
        if(!vis[*it]) DFS(g, vis, N-1, *it, s, count);
    }
    vis[v]=false;
}

int count_cyles(vector<int> g[], int n, int N) {
    bool * vis = new bool[n];
    memset (vis, false, sizeof vis);
    int count=0;
    for(int i=0;i<n-(N-1);i++) {
        DFS(g, vis, N-1, i, i, count);
        vis[i]=true;
    }
    delete[] vis;
    return count/2;
}

int solve(int n,int m,vector<int>u,vector<int>v) {
    vector<int> g[n]; int N=3;
    int x,y;
    for(int i=0;i<m;i++) {
        x = u[i]-1;
        y = v[i]-1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    return count_cyles(g,n,N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,m,x;
    cin>>n>>m;
    vector<int> u,v;
    for(int i=0;i<m;i++) { cin>>x; u.push_back(x); }
    for(int i=0;i<m;i++) { cin>>x; v.push_back(x); }
    cout << solve(n,m,u,v) << endl;
    return 0;
}


