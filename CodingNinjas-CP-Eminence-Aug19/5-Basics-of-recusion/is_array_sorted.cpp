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

bool is_sorted(int arr[], int n) {
    if (n==1 || n==0) return true;
    if (arr[0] > arr[1]) return false;
    return is_sorted(arr+1, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[] = {3,2,3,5};
    cout << "Is array sorted? " << (is_sorted(arr,4) ? "Yes" : "No") << endl;
    return 0;
}

