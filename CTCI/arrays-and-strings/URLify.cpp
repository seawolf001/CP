
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

string urlify(int n,string s){
    int spaces = 0;
    for(int i=0;i<n;i++) {
      if(s[i]==' ') spaces++;
    }
    int z  = n + 2 * spaces; // for one space char, we need 3 (1+2) chars, %20
    z--;
    for(int i=n-1; i>=0; i--) {
        if(s[i] == ' ') {
            s[z--] = '0';
            s[z--] = '2';
            s[z--] = '%';
        } else {
            s[z--] = s[i];
        }
    }
    return s;
}
