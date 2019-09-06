/*
 * Author: Jitendra Kumar (seawolf001)
 * Email: jitendra.iitp@gmail.com
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

int arr[10][10];

bool is_safe(int r, int c, int n) {
    for(int i=r-1; i>=0; i--) { if(arr[i][c]==1) return false; }
    for(int i=r-1,j=c-1; i>=0 && j>=0; i--,j--) { if(arr[i][j]==1) return false; }
    for(int i=r-1,j=c+1; i>=0 && j<n; i--,j++) { if(arr[i][j]==1) return false; }
    return true;
}

void nQueenHelper(int r, int n) {
    if(r==n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
    for(int c=0;c<n;c++) {
        if(is_safe(r,c,n)) {
            arr[r][c]=1;
            nQueenHelper(r+1,n);
            arr[r][c]=0;
        }
    }
    return;
}

void placeNQueens(int n) {
    nQueenHelper(0, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n=0; cin>>n;
    memset(arr, 0, n*n*sizeof(int));
    placeNQueens(n);
    return 0;
}

