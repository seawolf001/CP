/* Jitendra Kumar */
// https://leetcode.com/problems/longest-mountain-in-array/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> incL(n,1), incR(n,1); // vectors of size n, filled with 1.
        for(int i=1;i<n;i++) {
            if(arr[i-1] < arr[i]) incL[i] += incL[i-1];
        }
        for(int i=n-1; i>0; i--) {
            if(arr[i-1] > arr[i]) incR[i-1] += incR[i];
        }
        int mx = 0;
        for(int i=0;i<n;i++) {
            if(incL[i] < 2 || incR[i] < 2) continue;
            mx = max(mx, incL[i] + incR[i] - 1);
        }
        return (mx >= 3 ? mx : 0);
    }
};

