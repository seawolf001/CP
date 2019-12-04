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

int trap_water(int arr[], int n) {
    int l=0,r=n-1;
    int ans=0; int lmax=0, rmax=0;
    while(l<=r) {
        if(arr[l]<arr[r]) {
            if(arr[l] > lmax) {
                lmax = arr[l];
            } else {
                ans += lmax-arr[l];
            }
            l++;
        } else {
            if(arr[r] > rmax){
                rmax=arr[r];
            } else {
                ans += rmax-arr[r];
            }
            r--;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << trap_water(arr, n) <<endl;
    return 0;
}


