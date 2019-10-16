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

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    /* Start writing from here */
    int t; cin >> t;
    while(t--) {
        int p,x;
        cin >> p >> x;
        cout << ((p+x)%12) << endl;
    }
    return 0;
}


