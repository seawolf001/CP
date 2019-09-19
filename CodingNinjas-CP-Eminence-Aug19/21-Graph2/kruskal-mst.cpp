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

struct Edge{
    int s=0;
    int d=0;
    int w=0;
};

struct Subset{
    int parent=0;
    int rank=0;
};

bool comparator(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

int find(Subset comps[], int x) {
    if(comps[x].parent != x) {
        comps[x].parent = find(comps, comps[x].parent);
    }
    return comps[x].parent;
}

void Union(Subset comps[], int x, int y) {
    int xr = find(comps, x);
    int yr = find(comps, y);
    if(comps[xr].rank < comps[yr].rank) {
        comps[xr].parent = yr;
    } else if (comps[xr].rank > comps[yr].rank) {
        comps[yr].parent = xr;
    } else {
        comps[yr].parent = xr;
        comps[xr].rank++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,e; cin>>n>>e;
    int x=0;
    Edge * edges = new Edge[e];
    for (int i=0;i<e;i++){
        cin >> edges[i].s >> edges[i].d >> edges[i].w;
    }
    sort(edges, edges+e, comparator);
    Subset * comps = new Subset[n];
    for(int i=0;i<n;i++) { comps[i].parent = i; comps[i].rank=0; }
    int c1=0, c2=0;
    Edge * result = new Edge[n-1];
    while(c1 < (n-1) && c2 < e ) {
        Edge next = edges[c2++];
        int x = find(comps, next.s);
        int y = find(comps, next.d);
        if (x!=y) {
            result[c1++] = next;
            Union(comps, x, y);
        }
    }
    for (int i=0;i<c1;i++) {
        if (result[i].s < result[i].d) {
            cout << result[i].s << " " << result[i].d << " ";
        } else {
            cout << result[i].d << " " << result[i].s << " ";
        }
        cout << result[i].w << endl;
    }
    delete[] edges;
    delete[] comps;
    delete[] result;
    return 0;
}


