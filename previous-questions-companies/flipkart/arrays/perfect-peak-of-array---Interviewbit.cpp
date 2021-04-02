#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<int> left(n), right(n);
    left[0] = 0, right[n-1]=n-1;
    int lmax = 0, rmin = n-1;
    for(int i=1;i<n;i++) {
        if(A[i]>A[lmax])
            lmax = i;
        if(A[n-i-1]<A[rmin])
            rmin = n-i-1;
        // cout << i << " " << lmax << ", " << (n-i-1) << rmax << endl;
        left[i] = lmax;
        right[n-i-1] = rmin;
    }
    // for(int e: left) cout << e << " "; cout << endl;
    // for(int e: right) cout << e << " "; cout << endl;
    int ans = 0;
    for(int i=1;i<n-1;i++) {
        if(left[i]==i && right[i]==i) {
            ans = 1;
            break;
        }
    }
    return ans;
}

