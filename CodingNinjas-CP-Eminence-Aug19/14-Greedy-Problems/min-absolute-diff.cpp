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

int minAbsoluteDiff(int arr[], int n) {
    sort(arr, arr+n);
    int m = INT_MAX;
    for(int i=1;i<n;i++) {
        if(abs(arr[i]-arr[i-1]) < m) { m = abs(arr[i]-arr[i-1]); }
    }
    return m;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int * arr = new int [n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout << minAbsoluteDiff(arr, n) << endl;
    delete[] arr;
    return 0;
}


