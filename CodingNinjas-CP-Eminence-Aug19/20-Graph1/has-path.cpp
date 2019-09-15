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

bool BFS(vi adj[], int n, int s, int e, bool * vis) {
    if(s==e) return true;
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int f = q.front();
        if(f==e) return true;
        q.pop();
        for(auto i=adj[f].begin(); i!=adj[f].end(); i++){
            if(!vis[*i]) {
                vis[*i]=true;
                q.push(*i);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,e,x,y;
    cin >> n >> e;
    vi adj[n];
    for (int i=0;i<e;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>x>>y;
    bool * vis = new bool[n];
    memset(vis, false, n*sizeof(bool));
    if(BFS(adj, n, x, y, vis)) cout << "true" << endl;
    else cout << "false" << endl;
    delete[] vis;
    return 0;
}


