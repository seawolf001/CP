
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int x=1,y=2, tmp=0;
        for(int i=2;i<n;i++) {
            tmp = x+y;
            x=y;
            y=tmp;
        }
        return y;
    }
};


