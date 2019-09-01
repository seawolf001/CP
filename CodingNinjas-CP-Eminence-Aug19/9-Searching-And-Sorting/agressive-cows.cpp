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

bool check(ll arr[], int n, int c, ll d) {
    int count=1;
    ll last=arr[0];
    for(int i=1;i<n;i++){
        if (arr[i]-last >= d){
            last=arr[i];
            count++;
        }
        if(count==c) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t=0; cin>>t;
    while(t--){
        int n,c; cin>>n>>c;
        ll *arr = new ll[n];
        for(int i=0;i<n;i++) { cin>>arr[i]; }
        sort(arr, arr+n);
        ll s=0;
        ll e=arr[n-1]-arr[0];
        ll ans=-1;
        while(s<=e){
            ll mid = s+(e-s)/2;
            if(check(arr,n,c,mid)) {
                ans=mid;
                s=mid+1;
            } else {
                e=mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
