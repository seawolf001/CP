#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int i=0,j=n-2,k=n-1, L=n/3;
        long coins=0;
        while(L--) {
            coins += piles[j];
            ++i; j-=2; k-=2;
        }
        return coins;
    }
};


