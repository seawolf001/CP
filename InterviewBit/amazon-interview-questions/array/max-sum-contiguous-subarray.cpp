/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    if (n==0) return 0;
    int curr_sum=A[0], max_sum=A[0];
    for(int i=1; i<n; i++) {
        curr_sum = max(A[i], curr_sum+A[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

