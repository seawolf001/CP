#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int getSum(int a, int b) {
        int c=0;
        while(b!=0) {
            c =  a;
            a = a ^ b; // correct result for bits where both didn't had '1'.
            //Now, Bits where both had '1', left shift and take xor with previous
            // result to adjust for the carry for the remaining case above;
            b = (unsigned int)(c & b) << 1; // typecast to unsigned it to avoid overflow due to sign bit. ((c&b) & 0xffffffff) << 1 would do the same
        }
        return a;
    }
};


