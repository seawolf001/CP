#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
        for(int i=1; i<=n; i++) {
            int c=0,x=i; while(x>0) x = x>>1, ++c;
            ans = ((ans << c ) % MOD + i) % MOD;
        }
        return ans;
    }
};


