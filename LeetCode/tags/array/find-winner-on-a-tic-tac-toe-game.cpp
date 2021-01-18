#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    bool AnyRow(vii &A, int X) {
        for(int i=0;i<3;i++) {
            if(A[i][0]!=X) continue;
            if(A[i][0]==A[i][1] && A[i][1]==A[i][2])
                return true;
        }
        return false;
    }
    bool AnyColumn(vii &A, int X) {
        for(int j=0;j<3;j++) {
            if(A[0][j]!=X) continue;
            if(A[0][j]==A[1][j] && A[1][j]==A[2][j])
                return true;
        }
        return false;
    }
    bool diagonal(vii &A, int X) {
        if(A[0][0]==X && A[1][1]==X && A[2][2]==X)
            return true;
        if(A[0][2]==X && A[1][1]==X && A[2][0]==X)
            return true;
        return false;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        vii A(3,vi(3,0));
        int a=1, b=2, flag=true;
        for(auto move:moves) {
            if(flag) {
                A[move[0]][move[1]]=a;
                if(AnyRow(A,a) || AnyColumn(A,a) || diagonal(A,a))
                    return "A";
            } else {
                A[move[0]][move[1]]=b;
                if(AnyRow(A,b) || AnyColumn(A,b) || diagonal(A,b))
                    return "B";
            }
            flag=!flag;
        }
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(A[i][j]!=a && A[i][j]!=b)
                    return "Pending";
            }
            cout <<endl;
        }
        return "Draw";
    }
};


