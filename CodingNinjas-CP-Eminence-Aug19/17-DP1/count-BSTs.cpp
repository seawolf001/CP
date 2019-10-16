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

int countBST(int n) {
    int * dp = new int[n+1];
    dp[0] = dp[1] = 1;
    for (int i=2; i<=n; i++) {
        for(int j=0;j<i;j++) {
            long temp = ((dp[j] % MOD ) * (dp[i-j-1] % MOD)) % MOD;
            dp[i] = (dp[i] % MOD + temp ) % MOD;
        }
    }
    int ans = dp[n];
    delete[] dp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin >> n;
    cout << countBST(n) << endl;
    return 0;
}


