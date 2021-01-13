
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        long ans=0;
        for(int i=0;i<n;i++) {
            int l=i-1,r=i+1;
            while(l>=0 && A[l]>=A[i]) l--;
            while(r<n && A[r]>A[i]) r++;
            ans = (ans + A[i]*(i-l)*(r-i) % MOD) %  MOD;
        }
        return ans;
    }
};




