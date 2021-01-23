
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class NumMatrix {
private:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n >0 ? matrix[0].size():0;
        dp = vector<vector<int>>(n, vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int d = i-1>=0 && j-1>=0 ? dp[i-1][j-1]:0;
                int l = j-1>=0 ? dp[i][j-1]:0;
                int u = i-1>=0 ? dp[i-1][j]:0;
                dp[i][j]=matrix[i][j]+l+u-d;
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int x = r1-1>=0 ? dp[r1-1][c2]:0;
        int y = c1-1>=0 ? dp[r2][c1-1]:0;
        int z = r1-1>=0 && c1-1>=0 ? dp[r1-1][c1-1]:0;
        return dp[r2][c2]-x-y+z;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


