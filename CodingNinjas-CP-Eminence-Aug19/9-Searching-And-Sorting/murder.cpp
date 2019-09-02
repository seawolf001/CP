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

ll merge(int arr[], int l, int m, int r) {
    int i=l,j=m,k=0;
    int temp[r-l+1];
    ll ans=0;
    while(i<m && j<=r) {
        if (arr[i]<arr[j]) {
            ans += (r-j+1)*arr[i];
            temp[k++]=arr[i++];
        } else {
            temp[k++]=arr[j++];
        }
    }
    while(i<m) { temp[k++]=arr[i++]; }
    while(j<=r) { temp[k++]=arr[j++]; }
    for(i=l,k=0;i<=r;i++,k++) { arr[i]=temp[k];}
    return ans;
}

ll merge_sort(int arr[], int l, int r){
    if (r>l) {
        int m = (l+r)/2;
        return merge_sort(arr,l,m) + merge_sort(arr, m+1, r) + merge(arr, l, m+1, r);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t=0; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for (int i=0;i<n;i++) cin>>arr[i];
        cout << merge_sort(arr,0,n-1) << "\n";
    }
    return 0;
}

