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

struct Interval {
    int s;
    int e;
}

bool comparator(Interval x, Interval y) {
    return x.s < y.s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */

    // sort
    int arr[] = {32,4,5,2,2,5,8};
    sort(arr, arr+7); // for ascending order
    sort(arr, arr+7, greater<int>()); // for descending order

    // custom comparator
    Interval arr1[] = {{},{},........};
    sort(arr1,arr+size, comparator);
    return 0;
}

