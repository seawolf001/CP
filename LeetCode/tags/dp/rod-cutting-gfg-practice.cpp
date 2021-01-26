/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int max_price(int price[], int n) {
    if(n==0) return 0;
    int dp[n+1]; memset(dp, INT_MIN, sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            dp[i] = max(dp[i], price[j-1]+dp[i-j]);
        }
    }
    return dp[n];
}

int main() {
    int T; cin>>T;
    while(T--) {
        int n = 0; cin>> n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout << max_price(arr, n) << endl;
    }
    return 0;
}

