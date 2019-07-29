#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, x = 0;
    cin >> n;
    int* arr = new int[n];
    int profit = 0 ;
    for(int i=0; i<n ; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (arr[i]-arr[j] > profit) {
                profit = arr[i] - arr[j];
            }
        }
    }
    cout << profit;

    delete[] arr;
    return 0;
}
