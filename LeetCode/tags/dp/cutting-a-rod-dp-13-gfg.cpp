/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int rod_cutting_recur(int price[], int n) {
    if(n==0) return 0;
    int MAX = INT_MIN;
    for(int i=1;i<=n;i++) {
        MAX = max(MAX, price[i-1]+rod_cutting_recur(price, n-i));
    }
    return MAX;
}

int rod_cutting_dp(int price[], int n) {
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

int rod_cutting_unbounded_knapsack(int price[], int n) {
    if(n==0) return 0;
    int dp[n+1]; memset(dp, 0, sizeof(dp));
    for(int j=1;j<=n;j++) {
        for(int i=n;i>=j;i--) {
            dp[i] = max(dp[i], price[j-1]+dp[i-j]);
        }
    }
    return dp[n];
}

int main() {
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    assert (rod_cutting_recur(arr, size)==22);
    assert (rod_cutting_dp(arr, size)==22);
    assert (rod_cutting_unbounded_knapsack(arr, size)==22);
    cout << "Passing" << endl;
    return 0;
}
