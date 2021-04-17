#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN, lowest = INT_MAX;
        for(int &x: prices) {
            lowest = min(lowest, x);
            profit = max(profit, x-lowest);
        }
        return profit;
    }
};


