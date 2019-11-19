/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void build(int* arr, int* tree, int l, int r, int node) {
    if(l==r) {
        tree[node] = arr[l];
        return;
    }
    int m = (l+r)/2;
    build(arr, tree, l, m, 2*node);
    build(arr, tree, m+1, r, 2*node+1);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void update(int* arr, int* tree, int l, int r, int node, int idx, int v) {
    if(l==r) {
        arr[idx] = v;
        tree[node] = v;
        return;
    }
    int m = (l+r)/2;
    if(m<idx) { update(arr, tree, m+1, r, 2*node+1, idx, v); }
    else update(arr, tree, l, m, 2*node, idx, v);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int* tree, int l, int r, int node, int s, int e) {
    if(l>e || r<s) return INT_MAX;
    else if(l>=s && r<=e) return tree[node];
    int m = (l+r)/2;
    return min(query(tree, l, m, 2*node, s, e), query(tree, m+1, r, 2*node+1, s, e));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n, q;
    cin >> n >> q;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int * tree = new int[4*n];
    memset(tree, 4*n, 0);
    build(arr, tree, 0, n-1, 1);
    char c; int x, y;
    while(q--) {
        cin >> c >> x >> y;
        if(c=='q') {
            int ans = query(tree, 0, n-1, 1, x-1, y-1);
            cout << ans << endl;
        } else if(c=='u') {
            update(arr, tree, 0, n-1, 1, x-1, y);
        }
    }
    return 0;
}


