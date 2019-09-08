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

ll decryption_count(string s, int n, ll* output) {
    if(n==0 || n==1) return 1;
    if(output[n]>0) return output[n];
    ll x=0;
    if(s[n-1]!='0') { x = decryption_count(s, n-1, output) % MOD; }
    if(((s[n-2]-'0')*10+(s[n-1]-'0')) <= 26) {
        if(s[n-2]!='0') {
            x += decryption_count(s, n-2, output) % MOD;
            x = x % MOD;
        }
    }
    output[n] = x;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    /* Start writing from here */
    string s;
    while(cin>>s) {
        if (s[0]=='0') break;
        int n=s.size();
        ll* output = new ll[n+1];
        for(int i=0;i<=n;i++) { output[i]=0; }
        cout << decryption_count(s,n, output) << endl;
        delete[] output;
    }
    return 0;
}
