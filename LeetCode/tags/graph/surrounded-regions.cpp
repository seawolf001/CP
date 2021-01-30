#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
    int n=0,m=0, xm[4]={0,0,-1,1}, ym[4]={-1,1,0,0};

    bool inside(int x, int y) {
        return !(x<=0 || x>=n-1 || y<=0 || y>=m-1);
    }
    void dfs(int x, int y, vector<vector<char>>& board) {
        if(!inside(x,y) || board[x][y] != 'O')
            return;
        bool flag=true;
        for(int k=0;k<4;k++){
            int x1=x+xm[k], y1=y+ym[k];
            if(x1<0||x1>=n||y1<0||y1>=m) continue;
            if(board[x1][y1] != 'X') {
                if(inside(x1,y1) && board[x1][y1]=='O')
                    continue;
                flag = false;
            }
        }
        if(flag) {
            board[x][y] = 'X';
            for(int k=0;k<4;k++)
                dfs(x+xm[k], y+ym[k], board);
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = n > 0 ? board[0].size():0;
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                if(board[i][j]=='O') {
                    dfs(i,j,board);
                }
            }
        }
    }
};


