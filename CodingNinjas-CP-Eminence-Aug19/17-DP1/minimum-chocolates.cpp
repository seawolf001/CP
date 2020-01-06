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

int getMin(int * arr, int n) {
    sort(arr, arr+n);
    int * dp = new int[n];
    dp[0] = 1; dp[1] = 1;
    // for (int i=2; i<n;i++) {
    //     dp[i] = 1;
    //     for(int j=1; j<i; j++) {
    //         if(arr[j-1] < arr[j]) {
    //             dp[j]++;
    //             // if (arr[j] < arr[j+1]) {
    //             //     dp[j]++;
    //             // }
    //         }
    //     }
    // }
    for (int i=0;i<n;i++) cout << dp[i] << " "; cout << endl;
    int ans = 0;
    ans = accumulate(dp, dp+n, ans);
    delete[] dp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin >> n;
    int * arr  = new int[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    cout << getMin(arr, n) << endl;
    return 0;
}


