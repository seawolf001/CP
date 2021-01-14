
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return prices;
        for(int i=0;i<n;i++) {
            int j = i+1;
            while(prices[j]>prices[i]) j++;
            if(j<n) prices[i] -= prices[j];
        }
        return prices;
    }
};
