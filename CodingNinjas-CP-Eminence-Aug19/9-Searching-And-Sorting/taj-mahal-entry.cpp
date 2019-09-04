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
typedef std::vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int arr[n]; for (int i=0;i<n;i++) { cin>>arr[i]; }
    int time[n], t,t_min = INT_MAX, index = 0;
    for (int i=0;i<n;i++) {
        if (i >= arr[i]) {
            t=0;
        } else {
            int x = abs(arr[i]-i);
            if (x % n == 0) {
                t = x/n;
            } else {
                t = (x/n)+1;
            }
        }
        time[i] = i+t*n;
    }
    for (int i=0;i<n;i++) {
        if(time[i] < t_min) {
            t_min = time[i];
            index=i;
        }
    }
    cout << (index+1) << endl;
    return 0;
}

