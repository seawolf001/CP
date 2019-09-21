/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
#define MAXN 50
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

const int X[]={-1,0,1,0};
const int Y[]={0,-1,0,1};

int pathLen(unordered_map<string, string> m, int x, int y) {
    string s= to_string(x) + "_" + to_string(y);
    string curr = m[s];
    int len=0;
    while(1){
        len++;
        if(curr=="START") break;
        curr=m[curr];
    }
    return len;
}

bool dfs(char board[][MAXN], int sx, int sy, int x, int y, unordered_map<string, string> &mp, char ch, int n, int m, bool** vis) {
    vis[x][y] = true;
    for(int c=0;c<4;c++){
        int nx = x + X[c];
        int ny = y + Y[c];
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;
        if(board[nx][ny]==ch && !vis[nx][ny]) {
            mp[ to_string(nx) + "_" + to_string(ny) ] = to_string(x) + "_" + to_string(y);
            if(dfs(board, sx, sy, nx, ny, mp, ch, n, m, vis))
                return true;
        } else if(vis[nx][ny] && nx==sx && ny==sy) {
            if(pathLen(mp, x, y)>=4)
                return true;
        }
    }
    return false;
}

int solve(char board[][MAXN],int n, int m) {
    char ch='\0';
    int sx=0, sy=0;
    bool ** vis = new bool * [n];
    for (int i=0;i<n;i++){
        vis[i] = new bool[m];
        memset(vis[i], false, m*sizeof(bool));
    }
    unordered_map<string, string> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(!vis[i][j]) {
                mp.clear();
                mp[ to_string(i) + "_" + to_string(j) ] = "START";
                ch= board[i][j];
                sx = i;
                sy = j;
                if(dfs(board, sx, sy, i, j, mp, ch, n, m, vis))
                    return 1;
            }
        }
    }
    for(int i=0;i<n;i++) delete vis[i];
    delete[] vis;
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,m;
    cin>>n>>m;
    char arr[n][MAXN];
    for(int i=0;i<n;i++) memset(arr[i], '\0', m*sizeof(char));
    string s="";
    for(int i=0;i<n;i++) {
        cin>>s;
        for(int j=0;j<m;j++){
            arr[i][j] = s[j];
        }
    }
    cout << solve(arr, n, m) << endl;
    return 0;
}


