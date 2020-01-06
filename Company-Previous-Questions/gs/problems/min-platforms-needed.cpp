/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

struct Activity {
    int s; int f;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Activity array[n];
    for (int i=0;i<n;i++) { array[i].s=arr[i]; array[i].f=dep[i]; }
    sort(array, array+n, [](struct Activity x, struct Activity y) { return x.f < y.f; });
    int ans=1, k=0;
    for (int i=1;i<n; i++) {
        if(array[i].s > array[k].f) {
            ans++;
            k=i;
        }
    }
    cout << ans << endl;
    return 0;
}


