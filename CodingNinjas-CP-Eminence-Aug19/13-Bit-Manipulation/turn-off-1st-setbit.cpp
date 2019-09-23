/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

int turnOffFirstSetBit(int n){
    int x=1;
    for(int i=0;i<32;i++) {
        x = x<<i;
        if(n&x) break;
    }
    return n & (~x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    cout << turnOffFirstSetBit(n) << endl;
    return 0;
}


