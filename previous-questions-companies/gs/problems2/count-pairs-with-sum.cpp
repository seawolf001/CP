/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int countPairs(const int arr[], int n, int SUM) {
    unordered_map<int, int> m;
    for(int i=0;i<n;i++) { m[arr[i]]++; }
    int count=0;
    for(int i=0;i<n;i++) {
        count += m[SUM-arr[i]];
        if(SUM-arr[i] == arr[i]) count--;
    }
    return count/2;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    int int_size = sizeof(int);

    int a[] = {1, 5, 7, -1};
    allTestsPassing &= countPairs(a, sizeof(a)/int_size, 6) == 2;

    int b[] = {1, 5, 7, -1, 5};
    allTestsPassing &= countPairs(b, sizeof(b)/int_size, 6) == 3;

    int c[] = {1, 1, 1, 1};
    allTestsPassing &= countPairs(c, sizeof(c)/int_size, 2) == 6;

    int d[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1};
    allTestsPassing &= countPairs(d, sizeof(d)/int_size, 11) == 9;

    return allTestsPassing;
}

int main() {
    ios_base::sync_with_stdio(false);
    if(doTestsPass()) {
        cout << "\nAll Tests Passed.\n" << endl;
    } else {
        cout << "\nFailed for one or more tests.\n" << endl;
    }
    return 0;
}


