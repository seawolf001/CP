#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), i=0, j=0, counter=t.size(), minl=INT_MAX, idx=INT_MAX;
        unordered_map<char, int>f;
        for(char &c:t) f[c]++;
        for(;j<n;j++) {
            if(f[s[j]] > 0) --counter; // s[j] exists in t
            --f[s[j]]; // decrease, if not in t, frequency will go -ve
            while(counter==0) { // all chars in t matched
                if(j-i < minl) {
                    minl = j-i+1;
                    idx = i;
                }
                ++f[s[i]]; // discard i-th, increase because it was decreased.
                if(f[s[i]] > 0) ++counter; // > 0 stands it was in t otherwise, frequency will not exceed 0
                ++i;
            }
        }
        return minl==INT_MAX ? "" : s.substr(idx, minl);
    }
};


