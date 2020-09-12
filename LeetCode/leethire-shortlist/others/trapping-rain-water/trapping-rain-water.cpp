/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int * lmax = new int[n];
        int * rmax = new int[n];
        int MAX = INT_MIN;
        for(int i=0;i<n;i++) {
            MAX = max(height[i], MAX);
            lmax[i] = MAX;
        }
        MAX = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            MAX = max(height[i], MAX);
            rmax[i] = MAX;
        }
        long long trapped=0;
        for(int i=0;i<n;i++) {
            trapped += min(lmax[i], rmax[i]) - height[i];
        }
        delete[] lmax;
        delete[] rmax;
        return trapped;
    }
};

