#include<bits/stdc++.h>
using namespace std;

// Time: O(n^2) || constant space

void insertionSort(int arr[], int n) {
    // Values from the unsorted part are picked and placed at the correct position in the sorted part.
    for(int i=1; i<n; i++) {
        int key = arr[i], j=i-1;
        while(j >= 0 && arr[j] > key)
            arr[j+1] = arr[j], --j;
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for(int e: arr)
        cout << e << " ";
    cout << endl;
    return 0;
}

