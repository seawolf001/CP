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

void dfs(vi arr[], int s, bool* vis) {
    vis[s]=true;
    for(auto it=arr[s].begin(); it!=arr[s].end(); it++) {
        if(!vis[*it]) dfs(arr, *it, vis);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,e,x,y;
    cin>>n>>e;
    vi arr[n];
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bool* vis=new bool[n];
    memset(vis, false, n*sizeof(bool));
    dfs(arr, 0, vis);
    bool is_connected=true;
    for(int i=0;i<n;i++) {
        if(!vis[i]) is_connected=false;
    }
    if(is_connected) { cout << "true" << endl; }
    else { cout << "false" << endl; }
    delete[] vis;
    return 0;
}


