/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

// M * N matrix

void nullify_row(vector<vector<int>>& matrix, int row, int N) {
    for(int i=0; i<N; i++) {
        matrix[row][i]=0;
    }
}

void nullify_col(vector<vector<int>>& matrix, int col, int M) {
    for(int i=0; i<M; i++) {
        matrix[i][col]=0;
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> matrix){
    // M * N
    int M =matrix.size();
    if (M==0) return matrix;
    int N = matrix[0].size();

    bool first_row = false;

    for(int j=0; j<N; j++) {
        if(matrix[0][j]==0) {
            first_row = true;
            break;
        }
    }
    for(int i=1;i<M;i++) {
        bool nullify_r=false;
        for(int j=0;j<N;j++) {
            if(matrix[i][j]==0) {
                matrix[0][j]=0;
                nullify_r=true;
            }
        }
        if (nullify_r) nullify_row(matrix, i, N);
    }
    for(int j=0;j<N;j++) {
        if(matrix[0][j] == 0) {
            nullify_col(matrix, j, M);
        }
    }
    if (first_row) nullify_row(matrix, 0, N);

    return matrix;
}

