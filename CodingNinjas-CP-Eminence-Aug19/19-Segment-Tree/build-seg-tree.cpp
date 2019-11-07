/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void buildTree(int * arr, int * tree, int L, int R, int index) {
    if(L==R) {
        tree[index] = arr[L];
        return;
    }
    int m = (L+R)/2;
    buildTree(arr, tree, L, m, 2*index);
    buildTree(arr, tree, m+1, R, 2*index+1);
    tree[index] = tree[2*index] + tree[2*index+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int N = sizeof(arr)/sizeof(arr[0]);
    int * tree = new int[2*N];
    int L=0, R=N-1;
    buildTree(arr, tree, L, R, 1);
    for(int i=1;i<2*N;i++) cout << tree[i] << " ";
    return 0;
}


