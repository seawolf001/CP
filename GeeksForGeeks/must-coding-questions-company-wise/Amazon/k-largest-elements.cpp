/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

#include "../utils/minHeap.h"

int* kLargestNum(int* arr, int n, int k) {
    int *ans = new int[k];
    minHeap * m = new minHeap(k, arr);
    for(int i=k; i<n; i++) {
        if(arr[0]>arr[i])
            continue;
        else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
    for(int i=0;i<k;i++)
        ans[i]=arr[i];
    delete m;
    sort(ans, ans+k, greater<int>());
    return ans;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    int input1[] = {12, 5, 787, 1, 23};
    int output1[] = {787, 23};
    allTestsPassing &= equal(output1, output1+2, kLargestNum(input1, sizeof(input1)/sizeof(input1[0]), 2));
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


