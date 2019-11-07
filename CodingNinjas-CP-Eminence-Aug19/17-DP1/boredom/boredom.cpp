/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int solve(int n, vector<int> arr) {
    int * dp = new int[1001];
    int * freq = new int[1001];
    for (int i=0;i<=1000;i++) { freq[i]=0; }
    for (auto it=arr.begin(); it!=arr.end(); it++) { freq[*it]++; }
    dp[0] = 0; int x=0;
    for (int i=1;i<=1000;i++) {
        x = 0;
        if((i-2) >= 0) { x = dp[i-2]; }
        dp[i] = max(dp[i-1], x+i*freq[i]);
    }
    int ans = dp[1000];
    delete[] dp;
    delete[] freq;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    cout << solve(n, arr) << endl;
    return 0;
}


