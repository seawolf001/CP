#include<bits/stdc++.h>
using namespace std;

/*
 * Time complexity:  O(NlogN)
 * Space: constant
 * */

void heapify(int * arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child
    if(l<n && arr[l] > arr[largest])
        largest = l;
    if(r<n && arr[r] > arr[largest])
        largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void heapSort(int * arr, int n){
    // build heap
    for(int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);
    // extract max and heapify the reduced array
    for(int i=n-1; i>0; i--) {
        swap(arr[0], arr[i]); // moving the max element to last
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    for(int e: arr)
        cout << e << " ";
    cout << endl;
    return 0;
}

