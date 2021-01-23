#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int get_value(vector<vector<int>>& board, int x, int n) {
        /* board is n*n arranged in boustrophedonically, bottom to up.
         x is a number between  1...n*n
        */
        int row=0, col=0;
        row = (x % n) == 0 ? x/n : x/n + 1;
        if(row % 2 == 1) { // 1 indexed odd row from bottom
            if(x % n == 0) col = n - 1;
            else col = x % n - 1;
        } else { // 1 indexed even from bottom
            if(x%n == 0) col = 0;
            else col = n - (x % n);
        }
        return board[n - row][col];
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), dest = n*n, src=1, moves=0;
        queue<int> q; q.push(1);
        unordered_set<int> vis;
        vis.insert(1); moves = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int front = q.front(); q.pop();
                if(front == dest)
                    return moves;
                for(int i=1;i<=6;i++) {
                    int num = min(front+i, dest);
                    int val = get_value(board, num, n);
                    if(val == -1) val = num;
                    if(vis.find(val)==vis.end()) {
                        vis.insert(val);
                        q.push(val);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};


