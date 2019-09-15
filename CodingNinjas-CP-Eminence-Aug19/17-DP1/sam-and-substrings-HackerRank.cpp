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

int substrings(string s) {
    ll ans=s[0]-'0';
    ll last=s[0]-'0';
    int n=s.length();
    for(int i=1;i<n;i++) {
        last = (last*10) + (i+1)*(s[i]-'0');
        last = last % MOD;
        ans = (ans+last)%MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    string s; cin>>s;
    cout << substrings(s) << endl;
    return 0;
}


