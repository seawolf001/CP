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

struct Job { int s=0,f=0,p=0; };
bool comparator(Job x, Job y) { return x.f < y.f; }
int non_conflicting(Job * arr, int n) {
    int l=0, r=n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m].f <= arr[n].s) {
            if(arr[m+1].f <= arr[n].s) {
                l = m+1;
            } else {
                return m;
            }
        } else {
            r = m-1;
        }
    }
    return -1;
}
long long max_profit(Job * arr, int n) {
    long long * dp = new long long[n];
    sort(arr, arr+n, comparator);
    dp[0] = arr[0].p;
    for(int i=1;i<n;i++){
        long long inc = arr[i].p;
        int index = non_conflicting(arr, i);
        if (index !=-1) {
            // inc += arr[index].p;
            inc += dp[index];
        }
        dp[i] = max(inc, dp[i-1]);
    }
    long long ans = dp[n-1];
    delete[] dp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    Job * arr = new Job[n];
    for (int i=0;i<n;i++) { cin >> arr[i].s >> arr[i].f >> arr[i].p; }
    cout << max_profit(arr, n) << endl;
    delete[] arr;
    return 0;
}


