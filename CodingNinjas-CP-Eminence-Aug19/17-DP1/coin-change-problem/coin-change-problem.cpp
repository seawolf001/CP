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

int coin_change(int v, int* arr, int n, int** dp) {
    if (v==0) return 1;
    if (v <= 0 || n == 0) return 0;
    if(dp[v][n] != -1) return dp[v][n];
    int first = coin_change(v-arr[n-1], arr, n, dp);
    int second = coin_change(v, arr, n-1, dp);
    // int first = coin_change(v-arr[0], arr, n, dp);
    // int second = coin_change(v, arr+1, n-1, dp);
    dp[v][n] = first + second;
    return dp[v][n];
}

int countWaysToMakeChange(int d[], int n, int v){
    int ** dp = new int*[v+1];
    for(int i=0;i<=v;i++) {
        dp[i] = new int[n+1];
    }
    for(int i=0;i<=v;i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j] = -1;
        }
    }
    int ans = coin_change(v, d, n, dp);
    for(int i=0;i<=v; i++)
        delete[] dp[i];
    delete[] dp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n=0; cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) { cin>>arr[i]; }
    int v; cin>>v;
    cout << countWaysToMakeChange(arr, n, v) << endl;
    delete[] arr;
    return 0;
}


