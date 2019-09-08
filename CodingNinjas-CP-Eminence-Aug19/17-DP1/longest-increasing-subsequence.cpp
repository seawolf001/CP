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

int lis(int * arr, int n) {
    int * output = new int[n];
    output[0]=1;
    for(int i=1; i<n; i++) {
        output[i]=1;
        for(int j=i-1; j>=0;j--) {
            if (arr[j]>arr[i]) continue;
            output[i] = max(output[j]+1, output[i]);
        }
    }
    int largest = 0;
    for(int i=0;i<n;i++) { largest = max(largest, output[i]); }
    delete[] output;
    return largest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) { cin>>arr[i]; }
    cout << lis(arr, n) << endl;
    delete[] arr;
    return 0;
}


