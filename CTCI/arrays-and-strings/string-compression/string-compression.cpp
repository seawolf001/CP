/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


string stringCompression(string s){

    int n = s.length();
    if (n==1) return s;

    string output("");
    int f=1;

    for (int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            f++;
        } else {
            output.append(s[i-1] + to_string(f));
            f=1;
            if (output.length() > n) return s;
        }
    }
    output.append(s[n-1]+to_string(f)); // Last char not processed in the loop
    return output.length() <= n ? output: s;
}

