#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    int n = 0, target = 0;
    cin >> n >> target;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int s=0, curr=arr[0];
    bool exists = false;
    for (int i=1; i<=n ; i++) {
        while (curr > target && s < i-1) {
            curr -= arr[s];
            s++;
        }
        if (curr == target) {
            exists = true;
            cout << "true" << endl;
            for (int j=s; j<i; j++) {
                cout << arr[j] << " ";
            }
            break;
        }
        if (i<n) {
            curr += arr[i];
        }
    }
    if (!exists) {
        cout << "false";
    }
    return 0;
}
