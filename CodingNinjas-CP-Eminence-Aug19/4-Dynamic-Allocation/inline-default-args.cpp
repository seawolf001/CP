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

//inline function
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// default argument s=0 incase s is provided
int sum(int arr[], int size, int s=0) {
    int ans = 0;
    for (int i=s; i<size; i++) {
        ans += arr[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    cout << max(10, 15) << endl;

    int arr[] = {1,2,3,4,5};
    cout << sum(arr, 5) << endl;
    return 0;
}

