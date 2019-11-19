/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void buildTree(int * arr, int * tree, int L, int R, int node) {
    if(L==R) {
        tree[node] = arr[L];
        return;
    }
    int m = (L+R)/2;
    buildTree(arr, tree, L, m, 2*node);
    buildTree(arr, tree, m+1, R, 2*node+1);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void updateTree(int* arr, int* tree, int L, int R, int node, int idx, int v) {
    if(L==R) {
        arr[idx] = v;
        tree[node] = v;
        return;
    }
    int m = (L+R)/2;
    if(m < idx) { updateTree(arr, tree, m+1, R, 2*node+1, idx, v);}
    else { updateTree(arr, tree, L, m, 2*node, idx, v); }
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int* tree, int L, int R, int node, int l, int r) {
    if(L > r || R < l) return 0;
    if(L >= l && R <= r) return tree[node];
    int m = (L+R)/2;
    int ans1 = query(tree, L, m, 2*node, l, r);
    int ans2 = query(tree, m+1, R, 2*node+1, l, r);
    return ans1+ans2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[] = {1,2,3,4,5};
    int N = sizeof(arr)/sizeof(arr[0]);
    int * tree = new int[2*N];
    int L=0, R=N-1;
    buildTree(arr, tree, L, R, 1);
    for(int i=1;i<2*N;i++) cout << tree[i] << " ";
    cout << endl;
    updateTree(arr, tree, L, R, 1, 2, 10);
    for(int i=1;i<2*N;i++) cout << tree[i] << " ";
    int ans = query(tree, L, R, 1, 2, 4);
    cout << "\nSum of elements between the range " << 2 << " to " << 4 << " is=" << ans << endl;
    return 0;
}


