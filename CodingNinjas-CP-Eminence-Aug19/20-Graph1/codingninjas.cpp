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

const string codingninjas="CODINGNINJA";
const int X[] = {-1,-1,0,1,1,1,0,-1};
const int Y[] = {0,-1,-1,-1,0,1,1,1};
const int MAXN=100;

bool dfs(char arr[][MAXN], int n, int m, int c, int x, int y, bool ** vis) {
    if(c==codingninjas.length()-1)
        return true;
    vis[x][y]=true;
    for (int k=0;k<8;k++){
        int nx = x + X[k];
        int ny = y + Y[k];
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;
        if(arr[nx][ny] == codingninjas[c+1] && !vis[nx][ny]) {
            if(dfs(arr, n, m, c+1, nx, ny, vis))
                return true;
        }
    }
    vis[x][y]=false;
    return false;
}


int solve(char Graph[][MAXN],int n, int m)
{
    bool ** vis = new bool* [n];
    for (int i=0;i<n;i++) {
        vis[i] = new bool[m];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(Graph[i][j]=='C') {
                for(int i=0;i<n;i++){
                    memset(vis[i],false,sizeof(bool)*m);
                }
                if(dfs(Graph, n, m, 0, i, j, vis))
                    return 1;
            }
        }
    }
    for(int i=0;i<n;i++) delete vis[i];
    delete vis;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,m;
    cin>>n>>m;
    char arr[n][MAXN];
    char c; string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        strcpy(arr[i],s.c_str());
    }
    cout << solve(arr, n, m) << endl;
    return 0;
}
