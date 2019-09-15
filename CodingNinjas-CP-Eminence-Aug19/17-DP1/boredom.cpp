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

int solve(int n, vi a) {
    if (n==0) return 0;
    if (n==1) return a[0];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    vi a(n,0); int x=0;
    for(int i=0;i<n;i++) {
        cin>>x;
        a.push_back(x);
    }
    cout << solve(int n, vi a) << endl;
    return 0;
}


