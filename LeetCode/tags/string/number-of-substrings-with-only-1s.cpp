#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int numSub(string s) {
        long ans = 0, count = 0;
        for(char c: s) {
            count = c == '1' ? count + 1 : 0;
            ans = (ans + count) % MOD;
        }
        return ans;
    }
};
