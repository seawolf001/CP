
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

string checkPermutation(string a,string b){
    bitset<256> bits(0);
    int x=0;
    for (char c: a) {
        x = (int)c;
        bits.set(x);
    }
    for (char c: b) {
        x = (int)c;
        bits.set(x,0);
    }
    return bits.none() ? "YES" : "NO";
}


