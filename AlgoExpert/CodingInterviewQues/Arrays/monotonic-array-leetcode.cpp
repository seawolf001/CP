/* Jitendra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/* O(n) Time | O(1) Space*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool nonIncreasing = true, nonDecreasing=true;
        int n = A.size();
        for(int i=1;i<n; i++) {
            if(A[i] > A[i-1]) {
                nonIncreasing = false;
            }
            if(A[i] < A[i-1]) {
                nonDecreasing = false;
            }
        }
        return (nonIncreasing || nonDecreasing);
    }
};
/*
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool nonIncreasing = true, nonDecreasing=true;
        int n = A.size();
        for(int i=0;i<n-1; i++) {
            if(A[i+1] > A[i]) {
                nonIncreasing = false;
                break;
            }
        }
        for(int i=0;i<n-1; i++) {
            if(A[i+1] < A[i]) {
                nonDecreasing = false;
                break;
            }
        }
        return (nonIncreasing || nonDecreasing);
    }
};
*/
