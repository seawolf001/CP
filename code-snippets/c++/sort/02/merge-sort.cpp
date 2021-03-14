#include<bits/stdc++.h>
using namespace std;

/*
 * Time complexity:  O(NlogN) for all cases.
 * Space: O(N) while merge
 * Note: useful for sorting linkedlist because quicksort needs a lot of random access which is costly in linkedlist
 * */

void merge(int * arr, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m, i=0, j=0, k=0;
    int L[n1], R[n2];
    for(;i < n1; i++)
        L[i] = arr[l + i];
    for(;j < n2; j++)
        R[j] = arr[m + 1 + j];
    i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int * arr, int l, int r) {
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(arr, 0, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for(int e: arr)
        cout << e << " ";
    cout << endl;
    return  0;
}
