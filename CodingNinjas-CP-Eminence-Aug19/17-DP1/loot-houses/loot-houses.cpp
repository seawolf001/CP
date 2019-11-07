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

int getMaxMoney(int arr[], int n) {
    if (n==0) return 0;
    if (n==1) return arr[0];
    if (n==2) return max(arr[0], arr[1]);
    int * dp = new int [n];
    memset(dp, 0, sizeof dp);
    dp[0]=arr[0];
    dp[1]=max(arr[0], arr[1]);
    for(int i=2;i<n;i++) {
        dp[i] = max (arr[i]+dp[i-2], dp[i-1]);
    }
    int ans = dp[n-1];
    delete[] dp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout << getMaxMoney(arr, n) << endl;
    return 0;
}
