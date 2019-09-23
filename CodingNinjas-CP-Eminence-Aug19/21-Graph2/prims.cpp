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

int min_weight_node(int * weight, bool * vis, int n) {
    int min=INT_MAX, index = -1;
    for(int i=0;i<n;i++) {
        if(!vis[i] && weight[i]<min) {
            min = weight[i];
            index = i;
        }
    }
    return index;
}

void primsMST(int ** g, int n) {
    bool * vis = new bool[n];
    int * weight = new int[n];
    int * parent = new int[n];
    memset(vis, false, n*sizeof(bool));
    for(int i=0;i<n;i++) { weight[i] = INT_MAX; parent[i]=INT_MAX; }
    weight[0] = 0;
    parent[0] = -1;
    for(int i=0;i<n-1;i++) {
        int u = min_weight_node(weight, vis, n);
        vis[u]=true;
        for(int v=0;v<n;v++) {
            if(g[u][v]!=0 && !vis[v]) {
                if (g[u][v] < weight[v]) {
                    parent[v] = u;
                    weight[v] = g[u][v];
                }
            }
        }
    }
    for (int i=1;i<n;i++) {
        if (i < parent[i]) { cout << i << " " << parent[i] << " "; }
        else { cout << parent[i] << " " << i << " "; }
        cout << weight[i] << endl;
    }
    delete[] vis, weight, parent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n, m, x, y, w;
    cin >> n >> m;
    int ** g = new int* [n];
    for(int i=0;i<n;i++) {
        g[i] = new int[n];
        memset(g[i], 0, sizeof g);
    }
    for (int i=0;i<m;i++) {
        cin >> x >> y >> w;
        g[x][y] = w;
        g[y][x] = w;
    }
    primsMST(g, n);
    for(int i=0;i<n;i++) delete g[i];
    delete[] g;
    return 0;
}


