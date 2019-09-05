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

bool done(int arr[9][9], int& r, int& c) {
    for(r=0;r<9;r++) {
        for(c=0;c<9;c++) {
            if(arr[r][c]==0) return false;
        }
    }
    return true;
}

bool is_safe(int arr[9][9], int r, int c, int x) {
    for(int i=0;i<9;i++) { if(arr[r][i]==x) return false; }
    for(int i=0;i<9;i++) { if(arr[i][c]==x) return false; }
    int box_r = r/3, box_c = c/3;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(arr[3*box_r+i][3*box_c+j]==x) return false;
        }
    }
    return true;
}

bool sudokuSolver(int arr[9][9]) {
    int r,c;
    if(done(arr, r, c)) return true;
    for(int x=1;x<=9;x++) {
        if(is_safe(arr,r,c,x)) {
            arr[r][c]=x;
            if(sudokuSolver(arr)) return true;
            arr[r][c]=0;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[9][9];
    memset(arr, 0, 9*9*sizeof(int));
    for(int i=0;i<9;i++) { for(int j=0;j<9;j++) { cin>>arr[i][j]; } }
    // if(sudokuSolver(arr)) { cout << "true" << endl; }
    // else { cout << "false" << endl; }
    if(sudokuSolver(arr)) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


