/*
 * Author: Jitendra Kumar (seawolf001)
 * Email: jitendra.iitp@gmail.com
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

ll power(int x, int n) {
    if(n==0) { return 1; }
    else if(n==1) { return x; }
    ll res = power(x,n/2);
    if (n%2==0) { return res*res; }
    else { return x*res*res; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int x,n=0; cin>>x>>n;
    cout << power(x,n) << endl;
    return 0;
}


