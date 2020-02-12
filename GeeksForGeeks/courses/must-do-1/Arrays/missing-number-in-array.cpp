/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int T=0, N=0, x=0;
    cin>>T;
    while(T--) {
        cin >> N;
        long sum1 = (N*(N+1))/2;
        // for (int i=1;i<=N;i++) sum1 += i;
        for (int i=1;i<N;i++) {
            cin >> x;
            sum1 -= x;
        }
        cout << sum1 << endl;
    }
    return 0;
}


