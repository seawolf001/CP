#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int x[]={-1,-1,-1,0,0,1,1,1};
int y[]={-1,0,1,-1,1,-1,0,1};

struct Point {
    int x, y;
};

void dfs(vector<vector<int>> &arr, int n, vector<vector<bool>> &vis, Point s){
    vis[s.x][s.y]=true;
    queue<Point> q;
    q.push(s);
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int a = x[i]+p.x;
            int b = y[i]+p.y;
            if(a<0||b<0||a>=n||b>=n) continue;
            else {
                if(!vis[a][b] && arr[a][b]==1){
                    vis[a][b]=true;
                    Point _p;
                    _p.x=a; _p.y=b;
                    q.push(_p);
                }
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T=0;
    cin>>T;
    while(T--){
        int n=0; cin>>n;
        vector<vector<int>> arr(n, vector<int>(n,0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                vis[i][j]=false;
            }
        }
        int components = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && arr[i][j]==1){
                    Point p ={i,j};
                    dfs(arr, n, vis, p);
                    components++;
                }
            }
        }
        cout << components << "\n";
    }
    return 0;
}

