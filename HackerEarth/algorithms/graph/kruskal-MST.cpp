#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

/*
 * Greedy approach.
 * 1. Find least weight edge that is not included
 * 2. Include in MST if does not form a cycle.
 * 3. Use union-find method for checking cycles.
 * 4. time complexity can further be reduced using path-compress in union-find
 * */

struct Edge { int s, d, w; };

int find(int x, unordered_map<long, long> &parent) {
    while(x != parent[x])
        x = parent[x];
    return x;
}

void kruskal(int n, int m, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [&](const Edge e1, const Edge e2) {
                                            return e1.w <= e2.w;
                                        });
    unordered_map<long, long> parent;
    long min_cost=0, x, y;
    for(int i=1;i<=n;i++) parent[i]=i;

    for(Edge &e: edges) {
        x = find(e.s, parent);
        y = find(e.d, parent);
        if(x != y) {
            // cout << e.s << " " << e.d << " " <<  e.w << endl;
            min_cost += e.w;
            parent[x] = y; // union; not using path-compress yet.
        }
    }
    cout << min_cost << endl;
}

int main() {
    int n,m,s,d,w;
    cin >> n >> m;
    vector<Edge> edges;
    for(int c=0;c<m;c++) {
        cin >> s >> d >> w;
        Edge e = {
            s, // source
            d, // destination
            w // edge weight
        };
        edges.push_back(e);
    }
    kruskal(n, m, edges);
}

