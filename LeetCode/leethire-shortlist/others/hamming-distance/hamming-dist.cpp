/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> x_bits(x), y_bits(y);
        bitset<32> _xor = (x_bits ^ y_bits);
        return _xor.count();
    }
};

