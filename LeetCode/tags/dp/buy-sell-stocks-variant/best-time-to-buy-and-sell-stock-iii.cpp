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
        int n = prices.size();
        int b1=INT_MAX, b2=INT_MAX, s1=0,s2=0;
        for(int i=0;i<n;i++) {
            b1 = min(b1, prices[i]);
            s1 = max(s1, prices[i]-b1);
            b2 = min(b2, prices[i]-s1); // adjust profit from first sell into second buy,
            s2 = max(s2, prices[i]-b2); // s2 will have profit from s1 embedded.
        }
        return s2;
    }
};


