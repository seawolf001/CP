#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int i=A.size()-1;i>1;i--) {
            if(A[i-2]+A[i-1] > A[i])
                return A[i-2] + A[i-1] + A[i];
        }
        return 0;
    }
};
