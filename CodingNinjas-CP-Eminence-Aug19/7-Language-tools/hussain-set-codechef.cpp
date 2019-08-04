/*
 * Author: Jitendra Kumar (seawolf001)
 * Email: jitendra.iitp@gmail.com
 */

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

int main() {
    /* Start writing from here */
    int n=0,m=0;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    queue<ll> q;
    int next=0;
    ll x=0;
    int query=0;
    cin >> query;
    ll j=1;
    while(true) {
        if((next < n) && (q.empty() || arr[next] >= q.front())) {
            x = arr[next++];
        } else {
            x = q.front();
            q.pop();
        }
        if (j==query) {
            cout << x << endl;
            if (--m == 0) break;
            cin >> query;
        }
        x/=2;
        q.push(x);
        j++;
    }
    return 0;
}

