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

int latticePoints(int r) {
    if(r<=0) return 0;
    int ans=0;
    for(int x=1;x<=r;x++) {
        int y=sqrt(r*r-x*x);
        if(x*x+y*y==r*r) {
            ans+=4;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int r=5;
    cout << latticePoints(r) << endl;
    return 0;
}


