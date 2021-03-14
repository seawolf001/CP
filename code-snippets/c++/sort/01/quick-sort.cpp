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

void swap(int *a, int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[], int l, int h) {
    int p = arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++) {
        if(arr[j]<p){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return i+1;
}

void quickSort(int arr[], int l, int h) {
    if(l<h) {
        int p = partition(arr,l,h);
        quickSort(arr, 0, p-1);
        quickSort(arr, p+1, h);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i=0;i<n;i++) { cout << arr[i] << " "; }
    return 0;
}


