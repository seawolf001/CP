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

void merge_sort(int arr[], int l, int r) {
    if (r>l) {
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        int n1=m-l+1, n2=r-m;
        int L[n1], R[n2];
        for(int i=0;i<n1;i++) { L[i] = arr[i+l]; }
        for(int j=0;j<n2;j++) { R[j] = arr[m+1+j]; }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2) {
            if (L[i]<R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while(i<n1) { arr[k++] = L[i++]; }
        while(j<n2) { arr[k++] = R[j++]; }
    }
}

void mergeSort(int arr[], int n) {
    merge_sort(arr, 0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr, n);
    for (int i=0;i<n;i++) { cout << arr[i] << " "; }
    return 0;
}

