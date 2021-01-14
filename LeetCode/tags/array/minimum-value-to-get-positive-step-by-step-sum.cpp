
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prev=0, MIN=INT_MAX;
        for(int &x:nums) {
            x+=prev;
            prev=x;
            MIN=min(MIN, prev);
            cout << prev << " ";
        }
        return MIN <= 0 ? abs(MIN)+1: 1;
    }
};m
