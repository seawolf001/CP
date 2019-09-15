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

void dfs(vi adj[], int s, bool * vis, vi &ans) {
    vis[s]=true;
    ans.push_back(s);
    for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
        if(!vis[*it]) dfs(adj, *it, vis, ans);
    }
}
vector<vector<int>> dfsAll(vi adj[], int n) {
    bool * vis=new bool[n];
    memset(vis, false, n*sizeof(bool));
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            ans[i].clear();
            dfs(adj, i, vis, ans[i]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,e,x,y;
    cin>>n>>e;
    vi adj[n];
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>> ans = dfsAll(adj, n);
    for(int i=0;i<n; i++) {
        if(ans[i].size()>0) {
            sort(ans[i].begin(), ans[i].end());
            for(auto it=ans[i].begin(); it!=ans[i].end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


