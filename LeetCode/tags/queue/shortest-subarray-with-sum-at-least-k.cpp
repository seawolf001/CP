// NOT YET ACCEPTED 62/93

/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        if(n==0) return -1;
        queue<int> q;
        long curr = 0;
        int L = INT_MAX, i=0;
        while(i<n) {
            while(curr < K && i < n) {
                curr += A[i];
                q.push(A[i]);
                cout << "i=" << i<<" e="<<A[i]<< " curr=" << curr << endl;
                i++;
            }
            while(!q.empty() && curr-q.front() >= K) {
                curr -= q.front();
                q.pop();
            }
            if(curr >= K && L>q.size()) L = q.size();
            if(i<n) {
                curr += A[i];
                q.push(A[i++]);
            }
        }
        while(!q.empty()) {
            if(curr>=K && L>q.size()) L = q.size();
            curr -= q.front();
            q.pop();
        }
        return L == INT_MAX ? -1 : L;
    }
};


