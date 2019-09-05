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

/* L, U, R, D*/
int x[] = {0,-1,0,1};
int y[] = {-1,0,1,0};

void ratInAMazeHelper(int maze[][20], int n, int r, int c) {
    if(r==n-1 && c==n-1) {
        maze[r][c]=2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(maze[i][j] == 2) cout << "1 ";
                else cout << "0 ";
            }
        }
        cout << "\n";
    }
    if (maze[r][c]==0 || maze[r][c]==2 || r>=n || r<0 || c>=n || c<0) return;
    maze[r][c] = 2;
    for(int i=0;i<4;i++) { ratInAMazeHelper(maze, n, r+x[i], c+y[i]); }
    maze[r][c] = 1;
    return;
}

void ratInAMaze(int maze[][20], int n) {
    ratInAMazeHelper(maze,n,0,0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int maze[n][20];
    for(int i=0;i<n;i++) { for (int j=0;j<n;j++) cin>>maze[i][j]; }
    ratInAMaze(maze,n);
    return 0;
}


