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

long countBTs(int h) {
    if (h==0 || h==1) return 1;
    else if (h==2) return 3;
    long * dp = new long [h+1];
    dp[0] = dp[1] = 1;
    dp[2] = 3;
    long x,y;
    for(int i=3; i<=h; i++) {
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2]) % MOD + dp[i - 1]) % MOD) % MOD;
    }
    long res = dp[h];
    delete[] dp;
    return  res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int h; cin>>h;
    cout << countBTs(h) << endl;
    return 0;
}


