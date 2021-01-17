#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    unordered_map<long, long> memoize;
public:
    int integerReplacement(int n) {
        if(n==1)
            return 0;
        if(memoize.find(n)==memoize.end()) {
            if((n&1) == 0) {
                memoize[n] = 1 + integerReplacement(n/2);
            } else {
                // if n (>1) is odd, n-1/2 is n/2. n+1/2 ==> n/2+1
                memoize[n]= 2 + min(integerReplacement(n/2), integerReplacement(n/2+1));
            }
        }
        return memoize[n];
    }
};


