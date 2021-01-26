#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(), res=0, i=0,j=0;
        vector<int> f(3,0);
        for(;j<n;j++) {
            f[s[j]-'a']++;
            while(f[0] && f[1] && f[2]) {
                f[s[i]-'a']--;
                ++i;
            }
            // reaching at i, discards 0..i which will produce i substring which when added to
            // substring i..j will produce i other substrings which are valid.
            res += i;
        }
        return res;
    }
};

