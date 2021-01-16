#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = n>0 ? matrix[0].size() : 0;
        int x=0, y=m-1;
        while(x<n && y>=0) {
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]<target) ++x;
            else --y;
        }
        return false;
    }
};


