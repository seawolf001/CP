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
    int t=0; cin>>t;
    int n=0;
    int MAX = INT_MIN;
    while(t--) {
        cin >> n;
        int* arr = new int[n];
        int* lmax = new int[n];
        int* rmax = new int[n];
        MAX = INT_MIN;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++) {
            MAX = max(MAX, arr[i]);
            lmax[i] = MAX;
        }
        MAX = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            MAX = max(MAX, arr[i]);
            rmax[i] = MAX ;
        }
        long ans=0;
        for(int i=0;i<n;i++) {
            ans += min(lmax[i], rmax[i]) - arr[i];
        }
        cout << ans << endl;
        delete[] arr, lmax, rmax;
    }
    return 0;
}


