#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // marking visited by multiplying by -1.
        return (
            (start >= 0 && start < arr.size() && arr[start] >= 0) &&  (
                (arr[start] = -1 * arr[start]) == 0 ||
                canReach(arr, start + arr[start]) ||
                canReach(arr, start - arr[start])
            )
        );
    }
};


