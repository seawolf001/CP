#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    int set_bits_count(int n) {
        int c=0;
        while(n>0) n = n & (n-1), ++c;
        return c;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](const int x, const int y) {
                                int xbits = set_bits_count(x);
                                int ybits = set_bits_count(y);
                                if(xbits==ybits)
                                    return x<y;
                                return xbits < ybits;
                         });
        return arr;
    }
};


