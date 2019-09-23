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

void dijkstras(vector<pair<int, int>> adj[], int n) {
    int * d = new int[n];
    for(int i=0;i<n;i++) { d[i]=INT_MAX; }
    d[0]=0;
    bool * vis = new bool[n];
    memset (vis, false, n*sizeof (bool));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()) {
        int u = pq.top().second;
        vis[u]=true;
        pq.pop();
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++) {
            int v = (*it).first;
            int w = (*it).second;
            if(!vis[v] && (d[v] > w + d[u])) {
                d[v] = w + d[u];
                pq.push(make_pair(d[v], v));
            }
        }
    }
    for(int i=0;i<n;i++) cout << i << " " << d[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n, m, x, y, w;
    cin >> n >> m;
    vector<pair<int, int>> g[n];
    for(int i=0;i<m;i++) {
        cin >> x >> y >> w;
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }
    dijkstras(g, n);
    return 0;
}


