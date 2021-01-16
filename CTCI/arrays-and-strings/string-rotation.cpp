/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


string stringRotation(string a,string b){
    size_t n = a.length();
    size_t m = b.length();
    if (n==0 || m==0 || n!=m)  return "NO";
    string aa = a.append(a);
    // As asked to use a function like `isSubstring`, single call only
    return aa.find(b) != string::npos ? "YES" : "NO";
}

