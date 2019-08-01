#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int ** arr = new int * [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    // Don't forget to deallocate the memory
    for (int i=0; i<m; i++) {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}
