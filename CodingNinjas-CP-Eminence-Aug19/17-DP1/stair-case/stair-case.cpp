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

long staircase(int n) {
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    long * arr = new long[n+1];
    arr[0] = 1; arr[1] = 1; arr[2] = 2;
    for(int i=3;i<=n;i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    long ans = arr[n];
    delete[] arr;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    cout << staircase(n) << endl;
    return 0;
}


