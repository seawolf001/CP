#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l=1, r=n;
        while(l<=r) {
            long m = (l+r)/2;
            if(isBadVersion(m)) r = m-1;
            else l = m+1;
        }
        return l;
    }
};


