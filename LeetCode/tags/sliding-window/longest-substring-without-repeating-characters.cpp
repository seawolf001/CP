#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int maxL=0, n=str.length(), s=0;
        unordered_map<char, int> _map;
        for (int i=0;i<n;i++) {
            char c=str[i];
            if (_map.count(c)!=0) {
                s = max(s, _map[c]+1);
            }
            _map[c]=i;
            maxL = max(maxL, i-s+1);
        }
        return maxL;
    }
};
