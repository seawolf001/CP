#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int n=A.size(), i = 0, j = n - 1;
        vector<int> ret(2, -1);
        if(n==0) return ret;
        // Search for the left one
        while (i < j)
        {
            int mid = (i + j) /2;
            if (A[mid] < target) i = mid + 1;
            else j = mid;
        }
        if (A[i]!=target) return ret;
        else ret[0] = i;

        // Search for the right one
        j = n-1;  // We don't have to set i to 0 the second time.
        while (i < j)
        {
            int mid = (i + j) /2 + 1;	// Make mid biased to the right
            if (A[mid] > target) j = mid - 1;
            else i = mid;				// So that this won't make the search range stuck.
        }
        ret[1] = j;
        return ret;
    }
};


