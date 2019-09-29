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
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>> n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n, greater<int>());
    long long ans = 0;
    long long c = 1;
    for(int i=0;i<n;i++) {
        ans += arr[i] * c;
        c = c << 1;
    }
    cout << ans << endl;
    delete[] arr;
    return 0;
}



