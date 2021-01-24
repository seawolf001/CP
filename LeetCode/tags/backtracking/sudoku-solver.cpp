#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    bool valid(vector<vector<char>>& board, int x, int y, int d) {
        int r=x-x%3, c=y-y%3;
        for(int k=0;k<9;k++) {
            if(board[x][k]==d) return false;
            if(board[k][y]==d) return false;
            if(board[r+k/3][c+k%3]==d) return false;
        }
        return true;
    }
    bool solver(vector<vector<char>>& board, int x=0, int y=0) {
        if(x==9)
            return true;// zero based 0..8
        if(y==9)
            return solver(board, x+1, 0);
        if(board[x][y] != '.')
            return solver(board, x, y+1);
        for(char d='1'; d<='9'; ++d) {
            if(valid(board, x, y, d)) {
                board[x][y] = d;
                if(solver(board, x,y+1))
                    return true;
                board[x][y] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board){
        solver(board,0,0);
    }
};

