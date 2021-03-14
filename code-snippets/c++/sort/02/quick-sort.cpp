#include<bits/stdc++.h>
using namespace std;

/* Time complexity:
 *  Avg case: O(NlogN)
 *  Worst case: O(N^2) when the pivot is either the minimum or maximum element. Occurs when array is sorted monotically.
 *
 *  Space complexity:
 *  Avg case: O(logN)   for recursion stacks
 *  Worst case: O(N)    for recursion stacks
 *
 *  Even the worst case space complexity can be brought down to logN using tail optimization
 * */

int partition(int * arr, int l, int h) {
    int pivot = arr[h];
    int i=l-1, j=l;
    while(j < h) {
        if(arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
        ++j;
    }
    swap(arr[i+1], arr[h]);
    return i+1;
}

void quickSortTailOptimization(int * arr, int l, int h) {
    while(l<h) {
        int p = partition(arr, l, h);
        if(p-l < h-p) {
            // left partion is smaller
            quickSortTailOptimization(arr, l, p-1);
            l = p+1;
        } else {
            // right partition is smaller
            quickSortTailOptimization(arr, p+1, h);
            h = p-1;
        }
    }
}

void quickSort(int * arr, int l, int h) {
    if(l >= h) return;
    int p = partition(arr, l, h);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, h);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // quickSort(arr, 0, n - 1);
    quickSort_tail_optimization(arr, 0, n-1);
    for(int e: arr) cout << e << " "; cout << endl;
    return 0;
}
