#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, groups = 0, remains = 0;
    cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x=0, y=0, s=0;
    for (int i=0; i<n/2; i++) {
        x = arr[i];
        y = arr[n-1-i];
        s = x + y;
        cout << s/10 << " " << s%10 << "\n";
    }
    return 0;
}
