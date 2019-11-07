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

void lis(int * arr, int n, int * inc) {
    inc[0]=1;
    for(int i=1; i<n; i++) {
        inc[i]=1;
        for(int j=i-1;j>=0;j--) {
            if(arr[j] >= arr[i]) continue;
            inc[i] = max(inc[j]+1, inc[i]);
        }
    }
}

void lds(int * arr, int n, int * dec) {
    dec[n-1]=1;
    for(int i=n-2;i>=0;i--) {
        dec[i]=1;
        for(int j=i+1;j<n;j++) {
            if(arr[j] >= arr[i]) continue;
            dec[i] = max(dec[j]+1, dec[i]);
        }
    }
}

int lbs(int * arr, int n) {
    int * inc = new int[n];
    lis(arr, n, inc);

    int * dec = new int[n];
    lds(arr, n, dec);

    int ans = INT_MIN;
    for(int i=0;i<n;i++) { ans = max(ans, inc[i]+dec[i]-1); }
    delete[] inc;
    delete[] dec;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int * arr = new int [n];
    for(int i=0;i<n;i++) { cin>>arr[i]; }
    cout << lbs(arr, n) << endl;
    delete[] arr;
    return 0;
}


