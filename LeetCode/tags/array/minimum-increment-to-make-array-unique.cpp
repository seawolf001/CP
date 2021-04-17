#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();
        if(n==0) return 0;
        sort(A.begin(), A.end());
        int ans=0, prev=0;
        for(int i=1;i<n;i++)  {
            prev = A[i];
            A[i] = max(A[i-1]+1, A[i]);
            ans += A[i] - prev;
        }
        return ans;
    }
};
