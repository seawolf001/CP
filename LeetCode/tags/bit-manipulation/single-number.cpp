#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr=0;
        for(int &x:nums) xr ^= x;
        return xr;
    }
};


