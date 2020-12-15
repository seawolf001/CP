/* Jitendra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    int n=0, m=0, w=0;
    const vector<int> X{-1,0,1,0};
    const vector<int> Y{0,1,0,-1};

    bool safe(int x, int y) {
        return !(x<0||x>=n||y<0||y>=m);
    }
    bool dfs(vector<vector<char>>& board, int x, int y,
            vector<vector<bool>> &vis, const string &word, int idx) {
        if(!safe(x,y)) {
            return false;
        }
        vis[x][y]=true;
        if(idx>=w-1) return true; // matched the whole word
        for(int k=0;k<X.size();k++) {
            int x1 = x+X[k];
            int y1 = y+Y[k];
            if(!safe(x1,y1) || vis[x1][y1]) {
                continue;
            }
            if(board[x1][y1]==word[idx+1]) {
                if(dfs(board, x1, y1, vis, word, idx+1)) {
                    return true;
                }
            }
        }
        vis[x][y]=false; //backtrack
        return false;
    }

    vector<vector<bool>> get_visited() {
        vector<vector<bool>> v(n, vector<bool>(m, false));
        return v;
    }
    void reset(vector<vector<bool>> &v) {
        for(int i=0;i<n; i++) {
            for(int j=0;j<m;j++) {
                v[i][j]=false;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        w = word.size();
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> v = get_visited();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==word[0]) {
                    reset(v);
                    v[i][j]=true;
                    if(dfs(board, i, j, v, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

