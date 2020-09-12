/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


string oneAway(string a,string b){
    int m=a.length(), n=b.length();
    if (abs(m-n) > 1) {
        return "NO";
    }
    int diffs = 0;
    int i=0,j=0;
    while (i<m && j<n) {
        if(a[i] != b[j]) {
            if (diffs == 1) {
                return "NO";
            } else {
                diffs++;
            }
            if (m > n) {
                i++;
            } else if (m < n) {
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            j++;
        }
    }
    if (i<m || j<n) {
        diffs++;
    }
    return diffs==1 ? "YES" : "NO";
}

