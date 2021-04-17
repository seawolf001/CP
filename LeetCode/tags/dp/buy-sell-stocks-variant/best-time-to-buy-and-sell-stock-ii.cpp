#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size(), buy=0, sell=0, i=1;
        while(i<n) {
            while(i<n && prices[i-1] >= prices[i]) ++i;
            buy = i-1;
            while(i<n && prices[i-1] <= prices[i]) ++i;
            sell = i-1;
            profit += prices[sell] - prices[buy];
        }
        return profit;
    }
};


