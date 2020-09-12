/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


string palindromePermutation(string s){
    int f[256];
    memset(f, 0, sizeof f);
    for(char c: s) {
        int x = (int) c;
        f[x]++;
    }
    int even=0, odd=0;
    for(int i=0;i<256;i++) {
        if (f[i] % 2 ==0 ) even++;
        else odd++;
    }
    return (odd==0 || odd==1) ? "YES": "NO";
}

