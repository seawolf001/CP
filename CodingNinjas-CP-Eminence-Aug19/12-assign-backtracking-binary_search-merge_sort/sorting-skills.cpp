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

bool sortTheSkills(int arr[], int l, int r) {
    for(int i=l;i<r;i++){
        if(arr[i]==arr[i+1]+1) {
            int t = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = t;
        }
    }
    for(int i=l;i<r;i++) {
        if(arr[i]>arr[i+1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t,n; cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) { cin>>arr[i]; }
        bool sorted = sortTheSkills(arr,0,n-1);
        if (sorted) { cout << "Yes" << endl; }
        else { cout << "No" << endl; }
    }
    return 0;
}



