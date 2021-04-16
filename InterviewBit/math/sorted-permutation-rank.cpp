#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

#define MOD 1000003

int Solution::findRank(string A) {
    int n = A.size();
    if(n==0)  return 0;
    vector<long> f(n, 0);
    f[0] = 1; // 0!
    for(int i=1;i<n;i++) {
        f[i] = (i * f[i-1]) % MOD;
    }
    long long rank = 1;
    for(int i=0;i<n;i++) {
        int count = 0;
        for(int j=i+1; j<n; j++) {
            if(A[i]>A[j]) ++count;
        }
        rank = (rank + (count * f[n-i-1] % MOD) ) % MOD;
    }
    return rank % MOD;
}

