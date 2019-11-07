/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

ll kadane(ll * arr, int m, int* s, int* e) {
    ll max_ending_here=0, max_so_far = LLONG_MIN;
    int x=0; *e=-1;
    for(int i=0;i<m;i++) {
        max_ending_here += arr[i];
        if(max_ending_here < 0) {
            max_ending_here = 0;
            x = i+1;
        } else if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            *s = x;
            *e = i;
        }
    }
    if(*e!=-1)
        return max_so_far;
    max_so_far = arr[0];
    *s = *e = 0;
    for(int i=1;i<m;i++){
        if(arr[i]>max_so_far) {
            max_so_far=arr[i];
            *s = *e = i;
        }
    }
    return max_so_far;
}

ll solve(int ** arr, int m, int n) {
    int L=0, R=0, U=0, D=0;
    ll * temp = new ll[m];
    int s=0, e=0;
    ll ans = LLONG_MIN;
    for(int l=0; l<n; l++) {
        for(int k=0;k<m;k++){ temp[k]=0; }
        for(int r=l; r<n; r++) {
            for(int k=0; k<m; k++) { temp[k] += arr[k][r]; }
            ll sum = kadane(temp, m, &s, &e);
            if (sum > ans) {
                ans = sum;
                L=l; R=r; U=s; D=e;
            }
        }
    }
    // ans=0;
    // for(int i=L;i<=R;i++) {
    //     for(int j=U;j<=D;j++) {
    //         ans += arr[i][j];
    //     }
    // }
    delete[] temp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int m=0,n=0; cin>>m>>n;
    int ** arr = new int*[m];
    for(int i=0;i<m;i++) {
        arr[i] = new int[n];
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    cout << solve(arr, m, n) << endl;
    for(int i=0;i<m;i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}


