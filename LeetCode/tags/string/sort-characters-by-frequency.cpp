#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
public:
    string frequencySort(string s) {
        int f[256]={0};
        for(char &c:s) f[(int)c]++;
        sort(s.begin(), s.end(), [&](const char &x, const char &y) {
                                        if(f[x]==f[y])
                                            return x > y;
                                        return f[x] >= f[y];
                                    });
        return s;
    }
};


