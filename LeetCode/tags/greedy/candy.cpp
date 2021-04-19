#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> choco(n, 1);
        for(int i=1;i<n;i++) {
            if(ratings[i] > ratings[i-1])
                choco[i] = choco[i-1]+1;
        }
        for(int i=n-2;i>=0;i--) {
            if(ratings[i] > ratings[i+1])
                choco[i] = max(choco[i], choco[i+1]+1);
        }
        return accumulate(choco.begin(), choco.end(), 0);
    }
};


