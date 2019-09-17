
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

const int X[]={-1,0,1,0};
const int Y[]={0,-1,0,1};

void dfs(char cake[NMAX][NMAX], int n, int &count, int x, int y) {
    cake[x][y]='X'; /*visited[x][y]=true*/
    count++;
    for (int k=0;k<4;k++){
        int nx=x+X[k];
        int ny=y+Y[k];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(cake[nx][ny]=='1'){
            dfs(cake, n, count, nx, ny);
        }
    }
}

int solve(int n, char cake[NMAX][NMAX]) {
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(cake[i][j]=='1'){
                int c=0;
                dfs(cake, n, c, i, j);
                ans = max(ans, c);
            }
        }
    }
    return ans;
}

