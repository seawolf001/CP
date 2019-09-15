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
void BFS(vector<int> adj[], int s, int n) {
    bool * visited = new bool[n];
    memset(visited, false, n*sizeof(bool));
    queue<int> q; q.push(s); visited[s] = true;
    while(!q.empty()) {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for(int i=0;i < adj[front].size(); i++){
            int next=adj[front][i];
            if(!visited[next]) {
                q.push(next);
                visited[next]=true;
            }
        }
    }
    delete[] visited;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int v,e,x,y; cin >> v >> e;
    vector<int> adj[v];
    for (int i=0;i<e;i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<v;i++) { sort(adj[i].begin(), adj[i].end()); }
    BFS(adj, 0, v);
    return 0;
}
