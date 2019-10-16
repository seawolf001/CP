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

int solve_recurr(int n) {
    if(sqrt(n)==floor(sqrt(n))) return 1;
    if (n<=3) return n;
    int ans = n;
    for(int i=1;i<=sqrt(n);i++){
        ans = min(ans, 1+solve_recurr(n-i*i));
    }
    return ans;
}

int solve_dp(int n) {
    int * dp = new int[n+1];
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for(int i=4;i<=n;i++) {
        dp[i] = i;
        for(int j=1;j<=sqrt(i);j++){
            dp[i] = min(dp[i], 1+dp[i-j*j]);
        }
    }
    int ans=dp[n];
    delete[] dp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin >> n;
    cout << solve_dp(n) << endl;
    return 0;
}


