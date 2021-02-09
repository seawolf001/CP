#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int n=0, m=0, xm[4]={0,0,-1,1}, ym[4]={-1,1,0,0};
    void dfs(int x, int y, vector<vector<int>>& A) {
        if(x<0||x>=n||y<0||y>=m) return;
        A[x][y] = -2;
        for(int k=0;k<4;k++) {
            int x1=x+xm[k], y1=y+ym[k];
            if(x1<0||x1>=n||y1<0||y1>=m) continue;
            if(A[x1][y1]==1) dfs(x1,y1,A);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        n = A.size(), m = n>0 ? A[0].size() : 0;
        for(int i=0;i<n;i++) {
            if(A[i][0]==1) dfs(i,0,A);
            if(A[i][m-1]==1) dfs(i, m-1, A);
        }
        for(int j=0;j<m;j++){
            if(A[0][j]==1) dfs(0,j,A);
            if(A[n-1][j]==1) dfs(n-1,j,A);
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // cout << A[i][j] << " ";
                if(A[i][j]==1)
                    ++cnt;
            }
            // cout << endl;
        }
        return cnt;
    }
};

