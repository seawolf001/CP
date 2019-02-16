#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int prim(vector<PII> adj[], int v, int N){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    int _min = 0;
    
    bool vis[N]; 
    memset(vis, false, sizeof vis);
    PII p;
    
    q.push(make_pair(0, v));
    
    while(!q.empty()){
        p = q.top();
        q.pop();
        int x = p.second;
        if(!vis[x]){
            _min += p.first;
            vis[x] = true;
            for(auto it=adj[x].begin(); it!=adj[x].end(); it++){
                int y = (*it).second;
                if(!vis[y]) q.push(*it);
            }
        }
    }
    return _min;
}

int main(){
    int n=0,m=0,x=0,y=0,w=0;
    
    cin>>n>>m;
    vector<PII> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(w, y));
        adj[y].push_back(make_pair(w, x));
    }
    int _min = prim(adj, 1, n);
    cout << _min << "\n";
    return 0;
}