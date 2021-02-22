#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

/*
 * Greedy approach.
 * 1. Maintain two disjoint sets, those included and rest others
 * 2. select vertex with min weight from the adjacent to included nodes
 * 3. Include if it does not createa cycle.
 * 4. TIP: If node already visited, implies cycle.
 * */

typedef pair<int, int> PII;
unordered_map<int, list<PII>> adj;

void prims(int n, int m) {
    priority_queue<PII, vector<PII>, greater<PII>> q;
    long long min_cost=0;
    vector<bool> vis(n+1, false);
    q.push(make_pair(0,1)); // start with node:1
    while(!q.empty()) {
        auto f = q.top(); q.pop();
        int v = f.second;
        if(vis[v]) continue;
        vis[v] = true;
        min_cost += f.first; // cost in adding vertex v
        for(PII &p: adj[v]) {
            if(!vis[p.first])
                q.push(p);
        }
    }
    cout << min_cost << endl;
}

int main() {
    int n,m,s,d,w;
    cin >> n >> m;
    adj.clear();
    for(int c=0;c<m;c++) {
        cin >> s >> d >> w;
        adj[s].push_front(make_pair(w, d));  // s---- (w) ---->d
        adj[d].push_front(make_pair(w, s));  // d---- (w) ---->s
    }
    prims(n, m);
}

