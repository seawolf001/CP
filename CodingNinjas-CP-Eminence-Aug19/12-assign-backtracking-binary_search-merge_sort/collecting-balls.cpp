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

bool check(ll k, ll n) {
    ll c=0, x=0, N=n;
    while(n>0) {
        x = min(n,k);
        c+=x; n-=x; n-=n/10;
    }
    if(c<N/2) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    ll n; cin>>n;
    ll l=1,r=n,k,smallest=LLONG_MAX;
    while(r>=l) {
        k=(l+r)/2;
        if(check(k,n)) {
            smallest = min(smallest,k);
            r=k-1;
        } else {
            l=k+1;
        }
    }
    cout << smallest << endl;
    return 0;
}
