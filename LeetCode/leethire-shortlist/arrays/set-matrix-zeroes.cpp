/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (matrix[i][j]==0){
                    matrix[i][0]=-1;
                    matrix[0][j]=-1;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(matrix[i][0] == -1) {
                for(int j=0;j<m;j++){
                    if(matrix[i][j] != -1)
                        matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(matrix[0][j] == -1){
                for(int i=0;i<n;i++) {
                    if(matrix[i][j] != -1)
                        matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(matrix[i][0]==-1)
                matrix[i][0]=0;
        }
        for(int j=0;j<m;j++) {
            if(matrix[0][j]==-1)
                matrix[0][j]=0;
        }
    }
};
