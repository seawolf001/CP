/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int Solution::strStr(const string needle, const string haystack) {
    int m = needle.size(), n = haystack.size();
    if (m==0 || n==0) return -1;
    int len = 0, s = INT_MAX;
    for(int i=0; i<n; i++) {
        if(needle[len]==haystack[i]) {
            if(len==0) s=i;
            len++;
            if(idx==m) return s;
        } else {
            len = 0;
            s = INT_MAX;
        }
    }
    return s==INT_MAX ? -1 : s;
}

