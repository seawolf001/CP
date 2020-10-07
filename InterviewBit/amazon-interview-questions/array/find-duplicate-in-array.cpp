/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size()-1;
    return accumulate(A.begin(), A.end(), 0) - n*(n+1)/2;
}

