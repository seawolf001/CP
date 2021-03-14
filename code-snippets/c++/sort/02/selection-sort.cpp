#include<bits/stdc++.h>
using namespace std;

// Time: O(N^2), constant space

void selectionSort(int arr[], int n) {
    // find the next minimum and put in the beginning
    int i,j,idx;
    for(int i=0;i<n-1; i++) {
        idx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[idx] > arr[j])
                idx = j;
        }
        swap(arr[idx], arr[i]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(int e: arr)
        cout << e << " ";
    cout << endl;
    return 0;
}
