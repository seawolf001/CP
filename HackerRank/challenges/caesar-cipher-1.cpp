/* Jitendra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

#define CHARS 256
// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    for(int i=0;i<s.size(); i++) {
        s[i] = (s[i]+k) % 256;
    }
    return string
}


