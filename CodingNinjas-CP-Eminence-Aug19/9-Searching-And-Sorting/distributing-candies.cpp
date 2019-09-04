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
vector<string> split(const string& s, char delim);

bool verify(ll arr[], int n, ll m, ll k) {
    ll count=0;
    for(int i=0;i<n;i++) {
        int x = arr[i]/m;
        count += x;
        if (count >= k) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t; cin>>t;
    while(t--) {
        int n; ll k; cin>>n>>k;
        ll arr[n];
        for (int i=0;i<n;i++) { cin>>arr[i]; }
        sort(arr, arr+n);
        ll l=0,r=arr[n-1];
        ll ans=0;
        while(l<=r) {
            ll mid = (l+r)/2;
            if(verify(arr, n, mid, k)) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   stringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

