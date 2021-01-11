/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int numberOfMatches(int n) {
        if(n<2) return 0;
        if(n%2==0) {
            return (n / 2) + numberOfMatches(n / 2);
        } else {
            return (n-1)/2 + numberOfMatches( 1 + (n-1) / 2);
        }
    }
};

