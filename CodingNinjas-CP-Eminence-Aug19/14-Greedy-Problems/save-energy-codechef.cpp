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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n = 0; cin >> n;
    long * arr = new long[n];
    for (int i=0;i<n;i++) cin>>arr[i];

    long curr = 0, ans = 0, next = 0;
    while(curr < n-1) {
        next = curr + 1;
        while(next < n-1) {
            if((abs(arr[curr]) > abs(arr[next])) || (abs(arr[next])==abs(arr[curr]) && arr[curr] > 0)) {
                break;
            } else {
                next++;
            }
        }
        ans += (next-curr)*arr[curr] + (next*next-curr*curr)*arr[curr]*arr[curr];
        curr = next;
    }
    cout << ans << endl;

    delete[] arr;
    return 0;
}


