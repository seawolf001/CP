/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void addEdge(unordered_map<int, list<int>> &adj, int x, int y) {
    adj[x].push_front(y);
}

int BFS(unordered_map<int, list<int>> adj, int s, int t) {
    unordered_map<int, bool> vis;
    vis.clear();
    queue<pair<int, int>> q;
    q.push(make_pair(s, t)); vis[s]=true;
    int c=0, f=0, ct=0;
    while(!q.empty()) {
        auto front = q.front(); q.pop();
        f = front.first;
        ct = front.second;
        if(ct==0) continue;
        for(auto it=adj[f].begin(); it!=adj[f].end(); it++) {
            c= *it;
            if(vis.find(c) == vis.end() || vis[c]==false) {
                q.push(make_pair(c, ct-1));
                vis[c]= true;
            }
        }
    }
    int count=0;
    for(auto it=adj.begin(); it!=adj.end(); it++) {
        c=it->first;
        if(vis.find(c) == vis.end() || vis[c]==false) count++;
    }
    vis.clear();
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    /* Start writing from here */
    int n=0, x=0, y=0, s=0, t=0, cases=0, count=0;
    unordered_map<int, list<int>> adj;
    while(1) {
        adj.clear();
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++) {
            cin >> x >> y;
            addEdge(adj, x, y);
            addEdge(adj, y, x);
        }
        while(1) {
            cin >> s >> t;
            if(s==0 && t==0) break;
            count = BFS(adj, s, t);
            cases++;
            cout << "Case " << cases << ": " << count << " nodes not reachable from node " << s << " with TTL = " << t << "." << endl;
        }
    }
    return 0;
}


