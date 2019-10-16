/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int solve(int n, vector<int> arr) {
    sort(arr,begin(), arr.end());
    //TODO
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


