//https://leetcode.com/problems/replace-the-substring-for-balanced-string/discuss/408978/JavaC%2B%2BPython-Sliding-Window
#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), k=n/4, i=0,j=0,res=n;
        unordered_map<char, int> f;
        for(char &c:s) f[c]++;
        while(j<n) {
            f[s[j]]--; ++j;
            while(i<n && f['Q']<=k && f['W']<=k && f['E']<=k && f['R']<=k) {
                res = min(res, j-i);
                ++f[s[i]]; ++i;
            }
        }
        return res;
    }
};


